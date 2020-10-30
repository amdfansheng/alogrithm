#pragma once

#include <functional>
#include <future>
#include <mutex>
#include <queue>
#include <thread>
#include <utility>
#include <vector>

#include "SafeQueue.h"

class ThreadPool {
private:
  class ThreadWorker {
  private:
    int m_id;
    ThreadPool *m_pool;

  public:
    ThreadWorker(ThreadPool * pool, const int id)
      : m_pool(pool), m_id(id) { }

    void operator()() {
      std::function<void()> func;
      bool dequeued; // 是否正在取出队列中元素
      while (!m_pool->m_shutdown) {
        {
          std::unique_lock<std::mutex> lock(m_pool->m_conditional_mutex); // 为线程环境锁加锁，互访问工作线程的休眠和唤醒
          if (m_pool->m_queue.empty()) { m_pool->m_conditional_lock.wait(lock); } // 等待条件变量通知，开启线程
          dequeued = m_pool->m_queue.dequeue(func); // 取出任务队列中的元素
        }
        if (dequeued) { func(); } // 如果成功取出，执行工作函数
      }
    }
  };

  bool m_shutdown;
  SafeQueue<std::function<void()>> m_queue;
  std::vector<std::thread> m_threads;
  std::mutex m_conditional_mutex; // 线程休眠锁互斥变量
  std::condition_variable m_conditional_lock; // 线程环境锁，让线程可以处于休眠或者唤醒状态

public:
  ThreadPool(const int n_threads)
    : m_threads(std::vector<std::thread>(n_threads)), m_shutdown(false) { }

  ThreadPool(const ThreadPool &) = delete;
  ThreadPool(ThreadPool &&) = delete;

  ThreadPool & operator=(const ThreadPool &) = delete;
  ThreadPool & operator=(ThreadPool &&) = delete;

  // Inits thread pool
  void init() {
    for (int i = 0; i < m_threads.size(); ++i) {
      m_threads[i] = std::thread(ThreadWorker(this, i));
    }
  }

  // Waits until threads finish their current task and shutdowns the pool
  void shutdown() {
    m_shutdown = true;
    m_conditional_lock.notify_all(); // 通知 唤醒所有工作线程

    for (int i = 0; i < m_threads.size(); ++i) {
      if(m_threads[i].joinable()) { // 判断线程是否正在等待
        m_threads[i].join(); // 将线程加入等待队列
      }
    }
  }

  // Submit a function to be executed asynchronously by the pool
  // 线程的主要工作函数，使用了后置返回类型，自动判断函数返回值
  template<typename F, typename...Args>
  auto submit(F&& f, Args&&... args) -> std::future<decltype(f(args...))> {
    // Create a function with bounded parameters ready to execute
    std::function<decltype(f(args...))()> func = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
    // Encapsulate it into a shared ptr in order to be able to copy construct / assign 封装获取任务对象，方便另外一个线程查看结果
    auto task_ptr = std::make_shared<std::packaged_task<decltype(f(args...))()>>(func);

    // Wrap packaged task into void function 利用lambda表达式，返回一个函数对象
    std::function<void()> wrapper_func = [task_ptr]() { (*task_ptr)(); };

    // Enqueue generic wrapper function
    m_queue.enqueue(wrapper_func);

    // Wake up one thread if its waiting
    m_conditional_lock.notify_one();

    // Return future from promise, 返回先前注册的任务指针
    return task_ptr->get_future();
  }
};
