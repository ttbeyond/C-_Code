#include<iostream>
#include <mutex>
#include <thread>
#include<vector>
using namespace std;

namespace Txt
{
	//C++98 auto_ptr
	//利用RAII技术管理资源(空间，即内存)
	//使其可以像指针一样去使用
	template<class T>
	class auto_ptr
	{
	  public:
		  auto_ptr(T* ptr)
			  :_ptr(ptr)
		  {}

		  //copy(ap)
		  //思想：将*this的内容与ap的内容交换，*this原本为空，直接用ap的内容初始化*this
		  auto_ptr(auto_ptr<T>& copy)
			  :_ptr(copy._ptr)
		  {
			  copy._ptr = nullptr;
		  }

		  //ap1=ap2
		  auto_ptr<T>& operator=(auto_ptr<T>& ap)
		  {
			  //防止自己给自己赋值
			  if (this != &ap)
			  {
				  //要保证ap1为空，若不为空就把其空间释放
				  //保证为空的原因;一个智能指针只能管理一块空间
				  if (_ptr)
					  delete _ptr;

				  //交换
				  _ptr = ap._ptr;
				  ap._ptr = nullptr;
			  }

			  return *this;
		  }

		  ~auto_ptr()
		  {
			  if (_ptr)
			  {
				  cout << "delete:" << endl;
				  delete _ptr;
			  }
		  }

		  T& operator*()
		  {
			  return *_ptr;
		  }

		  T* operator->()
		  {
			  return _ptr;
		  }
	private:
		T* _ptr;
	};

	void test_auto_ptr()
	{
		auto_ptr<int> p1(new int);
		auto_ptr<int> copy(p1);    //用p1拷贝构造出copy对象，将p1对空间的管理权限转让给copy
		
		//可以运行，原因：此时copy对空间有管理权限
		*copy = 10;
		cout << *copy << endl;

		auto_ptr<int> p2 = copy;   //用copy赋值出p2，管理权限转移给p2

		*p1 = 20;//悬空，访问崩溃
		         //原因：p1对空间已经没有管理权限了
	}


	//C++11  unique_ptr
	//设计思路：防拷贝，即(不让拷贝构造和赋值)
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}

		~unique_ptr()
		{
			if (_ptr)
				delete _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		//防止拷贝构造的方法一：
		//C++11
		unique_ptr(const unique_ptr<T>& ptr) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& ptr) = delete;
	private:
		T* _ptr;

	//	//方法二：
	//	//C++98 将拷贝构造函数和operator= 只声明不实现+声明为私有
	//private:
	//	unique_ptr(const unique_ptr<T> ptr);
	//	unique_ptr<T>& operator=(const unique_ptr<T> ptr);
	};

	void test_unique_ptr()
	{
		unique_ptr<int> p1(new int);

		//验证是否可以拷贝构造或者赋值
		//unique_ptr<int> copy(p1);    //语法错误，无法通过编译
		//unique_ptr<int> p2 = copy;   //同上  
	}

	//C++11  shared_ptr
	//支持拷贝构造和赋值
	//实现原理：对每个共享同一块资源的对象进行记数管理，对象被销毁一次，记数--一次
	//创建一次++一次，在记数为0时释放该资源
	template<class T>
	class shared_ptr
	{
	  public:
		shared_ptr(T* ptr=nullptr)
			:_ptr(ptr)
			, _pCount(new int(1))  //给计数器单独开辟一块空间，并初始化为1
			, _pMutex(new mutex)
		{}

		//copy(sp1)
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pCount(sp._pCount)
			, _pMutex(sp._pMutex)
		{
			AddRef();
		}

		shared_ptr<T>& operator=(shared_ptr<T>& sp)
		{
			//if(_ptr != &sp &&_ptr !=sp._ptr)//防止自己给自己赋值和给同一块资源间的赋值
			if (_ptr != sp._ptr)//与上同义(原因：同一块资源地址相同)
			{
				//释放原对象的资源
				ReleaseRef();

				_ptr = sp._ptr;
				_pCount = sp._pCount;
				_pMutex = sp._pMutex;
				AddRef();
			}

			return *this;
		}

		~shared_ptr()
		{
			ReleaseRef();
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* GetPtr() const
		{
			return _ptr;
		}
	//private:
		int GetRefCount()
		{
			return *_pCount;
		}

		//在保证线程安全的前提下++记数器
		void AddRef()
		{
			_pMutex->lock();
			++(*_pCount);
			_pMutex->unlock();
		}

		//减引用计数
		void ReleaseRef()
		{
			bool delete_Lock_flaf = false;

			_pMutex->lock();
			//即使条件不成立，计数也已经--过了，若成立则需要释放资源
			if (--(*_pCount) == 0)
			{
				delete _pCount;
				delete _ptr;

				delete_Lock_flaf = true;//修改标记
			}
			_pMutex->unlock();

			//保证锁的资源也要释放
			if (delete_Lock_flaf == true)
				delete _pMutex;
		}
	  private:
		T* _ptr;
		int* _pCount;
		mutex* _pMutex;
	};

	void test_shared_ptr()
	{
		shared_ptr<int> sp1(new int);
		cout << sp1.GetRefCount() << endl;   //1
		shared_ptr<int> copy1(sp1);
		cout << copy1.GetRefCount() << endl; //2
		shared_ptr<int> copy2(copy1);
		cout << copy2.GetRefCount() << endl; //3

		shared_ptr<int> sp3(new int);
		cout << sp3.GetRefCount() << endl;   //1
		shared_ptr<int> sp4(sp3);
		cout << sp4.GetRefCount() << endl;   //2

		cout << endl;
		cout << endl;
		cout << endl;


		cout << sp1.GetRefCount() << endl;   //3
		sp1 = sp4;//给sp4对象所指的资源在增加一个名为sp1的对象，因此sp1原来所指向的资源记数会-1
		cout << sp1.GetRefCount() << endl;   //3

		cout << sp3.GetRefCount() << endl;   //3
		cout << sp4.GetRefCount() << endl;   //3
		sp3 = sp4;//对象指向同一资源间的赋值，忽略处理了，资源计数不变
		cout << sp3.GetRefCount() << endl;   //3
	}

	void test_shared_ptr_threads()
	{
		shared_ptr<int> sp(new int(0));
		vector<thread> vthreads;
		const size_t thread_size = 4;
		for (size_t i = 0; i < thread_size; ++i)
		{
			vthreads.push_back(thread([&]()
			{
				for (size_t i = 0; i < 10000; ++i)
				{
					shared_ptr<int> copy(sp);
					++(*sp);
				}
			}));
		}

		for (size_t i = 0; i < thread_size; ++i)
		{
			vthreads[i].join();
		}

		cout << ++(*sp) << endl;
		cout << sp.GetRefCount() << endl;
	}


	//C++11 weak_ptr
	//解决shared_ptr中的循环引用问题
	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr()
			:_ptr(nullptr)
		{}

		weak_ptr(const weak_ptr<T>& sp)
			:_ptr(sp.GetPtr())
		{}

		weak_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			_ptr = sp.GetPtr();
			return *this;
		}

		~weak_ptr()
		{}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};

	//测试shared_ptr成环问题
	struct ListNode
	{
		//shared_ptr<ListNode> _next;
		//shared_ptr<ListNode> _prev;
		//上边的定义方式会带来成环的问题，即：资源最终不会被释放

		weak_ptr<ListNode> _next;
		weak_ptr<ListNode> _prev;
		int val;

		~ListNode()
		{
			cout << "~ListNode()" << endl;
		}
	};

	void test_cycle_ref()
	{
		shared_ptr<ListNode> node1(new ListNode);
		shared_ptr<ListNode> node2(new ListNode);

		//将俩个节点链接起来，查看是否会带来shared_ptr的成环问题
		node1->_next = node2;
		node2->_prev = node1;

		cout << node1.GetRefCount() << endl;//若成环，则计数器会为2，且资源不会被系统回收，造成内存泄露
		cout << node2.GetRefCount() << endl;//若不成环，则记数为1，且资源会被释放，即：会调用ListNode的析构函数

	}


	//定制删除器
	template<class T>
	class FreeFunc
	{
		void operator()(T* ptr)
		{
			cout << "free:" << ptr << endl;
			delete ptr;
		}
	};

	//需要将shared_ptr写成俩个模板参数的
	//template<class T>
	//class DeleteArray
	//{
	//	void operator()(T* ptr)
	//	{
	//		cout << "free:" << ptr << endl;
	//		delete[] ptr;
	//	}
	//};

	//class A
	//{
	//public:
	//	~A()
	//	{
	//		cout << "~A()" << endl;
	//	}
	//};
	//void test_Delete()
	//{
	//	
	//}
}
class A
{
public:
	~A()
	{
		cout << "~A()" << endl;
	}
};
int main()
{
	//Txt::test_auto_ptr();
	//Txt::test_unique_ptr();
	//Txt::test_shared_ptr();
	//Txt::test_shared_ptr_threads();//线程安全的测试
	//Txt::test_cycle_ref();

		//// 定制删除器 ->仿函数 lamber  了解一下 面试中很少考察
		//std::shared_ptr<A> sp1(new A[10], DeleteArray<A>());
		//std::shared_ptr<A> sp2(new A[10], [](A* ptr){delete[] ptr; });
	
		//std::shared_ptr<A> sp3((A*)malloc(sizeof(A)), [](A* ptr){free(ptr); });
		//std::shared_ptr<FILE> sp4(fopen("test.txt", "w"), [](FILE* ptr){fclose(ptr); });

	system("pause");
	return 0;
}