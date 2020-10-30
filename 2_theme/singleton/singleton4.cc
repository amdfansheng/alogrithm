// 线程安全 (有潜在问题)
//
// non-local static对象（函数外）
// C++规定，non-local static 对象的初始化发生在main函数执行之前，也即main函数之前的单线程启动阶段，所以不存在线程安全问题。
// 但C++没有规定多个non-local static 对象的初始化顺序，尤其是来自多个编译单元的non-local static对象，他们的初始化顺序是随机的。
#include <cstdio>

class Singleton {
private:
	Singleton() { printf("Singleton\n"); };
	~Singleton() { printf("~Singleton\n"); };
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);

    static Singleton instance;
public:
	static Singleton *getInstance()
    {
		return &instance;
	}
};

Singleton Singleton::instance;

int main()
{
    Singleton *ps = Singleton::getInstance();
}
