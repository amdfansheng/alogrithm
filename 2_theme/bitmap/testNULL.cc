#include<iostream>
using namespace std;
void test(void *p)
{
    cout<<"p is pointer "<<p<<endl;
}
void test(int num)
{
    cout<<"num is int "<<num<<endl;
}

template<typename Type1, typename ptrType>
void test2(Type1 fun, ptrType ptr)
{
    /*do something*/
    fun(ptr);
    return;
}
void fun(int *val)
{
    cout<<"fun"<<endl;
}


int main(void)
{
    //test(NULL); // error: call of overloaded ‘test(NULL)’ is ambiguous
    test(nullptr);
    //test2(fun, NULL); // In instantiation of ‘void test2(Type1, ptrType) [with Type1 = void (*)(int*); ptrType = long int]’
    test2(fun, nullptr);
    return 0;
}
