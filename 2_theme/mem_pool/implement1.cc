// https://blog.csdn.net/K346K346/article/details/49538975
// 一个MemBlock用完了，创建一个新的块追到上一个MemBlock后面
// 每个MemBlock块里有固定数量的FreeNode块，用于保存用户数据
#include <iostream>

using namespace std;

template<int ObjectSize, int NumofObjects = 20>
class MemPool {
public:
	~MemPool()
    {
		MemBlock* ptr;
		while (memBlockHeader_) {
			ptr = memBlockHeader_->pNext;
			delete memBlockHeader_;
			memBlockHeader_ = ptr;
		}
	}

	void* malloc();
	void free(void*);

private:
	//空闲节点结构体
	struct FreeNode {
		char data[ObjectSize]; // 用户数据
		FreeNode* pNext;       // MemBlock耗尽标志
	};

	//内存块结构体
	struct MemBlock {
		MemBlock* pNext;       // MemBlock结尾标志
		FreeNode data[NumofObjects]; // 大块内存
	};

	MemBlock* memBlockHeader_ = nullptr;
	FreeNode* freeNodeHeader_ = nullptr;
};

//分配空闲的节点
template<int ObjectSize, int NumofObjects>
void* MemPool<ObjectSize, NumofObjects>::malloc()
{
	//无空闲节点，申请新内存块
	if (!freeNodeHeader_) {
		MemBlock* newBlock = new MemBlock;
		newBlock->pNext = nullptr;

		freeNodeHeader_ = &newBlock->data[0];	 //设置内存块的第一个节点为空闲节点链表的首节点
		//将内存块的其它节点串起来
		for (int i = 1; i < NumofObjects; ++i) {
			newBlock->data[i - 1].pNext = &newBlock->data[i];
		}
		newBlock->data[NumofObjects - 1].pNext = nullptr;

		//首次申请内存块
		if (!memBlockHeader_) {
			memBlockHeader_ = newBlock;
		} else {
			//将新内存块加入到内存块链表
			newBlock->pNext = memBlockHeader_;
			memBlockHeader_ = newBlock;
		}
	}
	//返回空节点闲链表的第一个节点
	void* freeNode = freeNodeHeader_;
	freeNodeHeader_ = freeNodeHeader_->pNext;
	return freeNode;
}

//释放已经分配的节点
template<int ObjectSize, int NumofObjects>
void MemPool<ObjectSize, NumofObjects>::free(void* p)
{
	FreeNode* pNode = (FreeNode*)p;
	pNode->pNext = freeNodeHeader_;	//将释放的节点插入空闲节点头部
	freeNodeHeader_ = pNode;
}

class ActualClass {
	static int count;
	int No;

public:
	ActualClass()
    {
		No = count;
		count++;
	}

	void print()
    {
		cout << this << ": ";
		cout << "the " << No << "th object" << endl;
	}

	void* operator new(size_t size);
	void operator delete(void* p);
};

int ActualClass::count = 0;

//定义内存池对象
MemPool<sizeof(ActualClass), 2> mp;

void* ActualClass::operator new(size_t size)
{
	return mp.malloc();
}

void ActualClass::operator delete(void* p)
{
	mp.free(p);
}


int main() {
	ActualClass* p1 = new ActualClass;
	p1->print();

	ActualClass* p2 = new ActualClass;
	p2->print();

	delete p1;
	p1 = new ActualClass; // 使用原来P1的地址
	p1->print();

	ActualClass* p3 = new ActualClass;
	p3->print();

	delete p1;
	delete p2;
	delete p3;
}
