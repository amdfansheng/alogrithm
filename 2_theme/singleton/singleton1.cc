// 非线程安全
// 在单例类内部定义专有的嵌套类。
// 在单例类内定义私有的专门用于释放的静态成员。
// 利用程序在结束时析构全局变量的特性，选择最终的释放时机。
#include <cstdio>

class Singleton {
private:
	static Singleton* instance;

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

public:
	static Singleton* getInstance()
    {
		if (!instance) instance = new Singleton();
		return instance;
	}
};

// init static member
Singleton* Singleton::instance = nullptr;
Singleton::Deletor Singleton::deletor; // 这行必须要有

int main()
{
    Singleton *ps = Singleton::getInstance();
}
