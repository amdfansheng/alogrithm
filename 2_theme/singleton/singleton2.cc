// 线程安全
// 双检测锁模式（DCL: Double-Checked Locking Pattern）
// 线程安全问题仅出现在第一次初始化（new）过程中，而在后面获取该实例的时候并不会遇到，也就没有必要再使用lock。
// 双检测锁很好地解决了这个问题，它通过加锁前检测是否已经初始化，避免了每次获取实例时都要首先获取锁资源。
//
// C++11引进了memory model，提供了Atomic实现内存的同步访问，
// 即不同线程总是获取对象修改前或修改后的值，无法在对象修改期间获得该对象。
#include <cstdio>
#include <mutex>
#include <atomic>

class Singleton {
private:
	static std::atomic<Singleton*> instance;

	Singleton() { printf("Singleton\n"); };
	~Singleton() { printf("~Singleton\n"); };
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);

	class Deletor {
	public:
        Deletor() { printf("Deletor\n"); }
		~Deletor()
        {
            printf("~Deletor\n");
			if (Singleton::instance) delete Singleton::instance;
		}
	};

	static Deletor deletor;
    static std::mutex mtx;

public:
	static Singleton *getInstance()
    {
        Singleton *p = instance;
		if (!p) {
            std::lock_guard<std::mutex> guard(mtx);
            if (!(p = instance)) instance = p = new Singleton();
        }
		return p;
	}
};

// init static member
std::atomic<Singleton *> Singleton::instance {nullptr};
Singleton::Deletor Singleton::deletor; // 这行必须要有
std::mutex Singleton::mtx;

int main()
{
    Singleton *ps = Singleton::getInstance();
}
