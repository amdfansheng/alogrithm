// 线程安全 (Best of all)
// C++11规定了local static在多线程条件下的初始化行为，要求编译器保证了内部静态变量的线程安全性。
// C++11规定，在一个线程开始local static 对象的初始化后到完成初始化前，
// 其他线程执行到这个local static对象的初始化语句就会等待，直到该local static 对象初始化完成。
// 在C++11标准下，《Effective C++》提出了一种更优雅的单例模式实现，使用函数内的 local static 对象。
// 这样，只有当第一次访问getInstance()方法时才创建实例。
// 这种方法也被称为Meyers' Singleton。C++0x之后该实现是线程安全的，C++0x之前仍需加锁。
#include <cstdio>

class Singleton {
private:
	Singleton() { printf("Singleton\n"); };
	~Singleton() { printf("~Singleton\n"); };
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);

public:
	static Singleton *getInstance()
    {
        static Singleton instance;
		return &instance;
	}
};

int main()
{
    Singleton *ps = Singleton::getInstance();
}
