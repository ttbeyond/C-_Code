#include<iostream>
#include <mutex>
#include <thread>
#include<vector>
using namespace std;

namespace Txt
{
	//C++98 auto_ptr
	//����RAII����������Դ(�ռ䣬���ڴ�)
	//ʹ�������ָ��һ��ȥʹ��
	template<class T>
	class auto_ptr
	{
	  public:
		  auto_ptr(T* ptr)
			  :_ptr(ptr)
		  {}

		  //copy(ap)
		  //˼�룺��*this��������ap�����ݽ�����*thisԭ��Ϊ�գ�ֱ����ap�����ݳ�ʼ��*this
		  auto_ptr(auto_ptr<T>& copy)
			  :_ptr(copy._ptr)
		  {
			  copy._ptr = nullptr;
		  }

		  //ap1=ap2
		  auto_ptr<T>& operator=(auto_ptr<T>& ap)
		  {
			  //��ֹ�Լ����Լ���ֵ
			  if (this != &ap)
			  {
				  //Ҫ��֤ap1Ϊ�գ�����Ϊ�վͰ���ռ��ͷ�
				  //��֤Ϊ�յ�ԭ��;һ������ָ��ֻ�ܹ���һ��ռ�
				  if (_ptr)
					  delete _ptr;

				  //����
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
		auto_ptr<int> copy(p1);    //��p1���������copy���󣬽�p1�Կռ�Ĺ���Ȩ��ת�ø�copy
		
		//�������У�ԭ�򣺴�ʱcopy�Կռ��й���Ȩ��
		*copy = 10;
		cout << *copy << endl;

		auto_ptr<int> p2 = copy;   //��copy��ֵ��p2������Ȩ��ת�Ƹ�p2

		*p1 = 20;//���գ����ʱ���
		         //ԭ��p1�Կռ��Ѿ�û�й���Ȩ����
	}


	//C++11  unique_ptr
	//���˼·������������(���ÿ�������͸�ֵ)
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

		//��ֹ��������ķ���һ��
		//C++11
		unique_ptr(const unique_ptr<T>& ptr) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& ptr) = delete;
	private:
		T* _ptr;

	//	//��������
	//	//C++98 ���������캯����operator= ֻ������ʵ��+����Ϊ˽��
	//private:
	//	unique_ptr(const unique_ptr<T> ptr);
	//	unique_ptr<T>& operator=(const unique_ptr<T> ptr);
	};

	void test_unique_ptr()
	{
		unique_ptr<int> p1(new int);

		//��֤�Ƿ���Կ���������߸�ֵ
		//unique_ptr<int> copy(p1);    //�﷨�����޷�ͨ������
		//unique_ptr<int> p2 = copy;   //ͬ��  
	}

	//C++11  shared_ptr
	//֧�ֿ�������͸�ֵ
	//ʵ��ԭ����ÿ������ͬһ����Դ�Ķ�����м���������������һ�Σ�����--һ��
	//����һ��++һ�Σ��ڼ���Ϊ0ʱ�ͷŸ���Դ
	template<class T>
	class shared_ptr
	{
	  public:
		shared_ptr(T* ptr=nullptr)
			:_ptr(ptr)
			, _pCount(new int(1))  //����������������һ��ռ䣬����ʼ��Ϊ1
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
			//if(_ptr != &sp &&_ptr !=sp._ptr)//��ֹ�Լ����Լ���ֵ�͸�ͬһ����Դ��ĸ�ֵ
			if (_ptr != sp._ptr)//����ͬ��(ԭ��ͬһ����Դ��ַ��ͬ)
			{
				//�ͷ�ԭ�������Դ
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

		//�ڱ�֤�̰߳�ȫ��ǰ����++������
		void AddRef()
		{
			_pMutex->lock();
			++(*_pCount);
			_pMutex->unlock();
		}

		//�����ü���
		void ReleaseRef()
		{
			bool delete_Lock_flaf = false;

			_pMutex->lock();
			//��ʹ����������������Ҳ�Ѿ�--���ˣ�����������Ҫ�ͷ���Դ
			if (--(*_pCount) == 0)
			{
				delete _pCount;
				delete _ptr;

				delete_Lock_flaf = true;//�޸ı��
			}
			_pMutex->unlock();

			//��֤������ԴҲҪ�ͷ�
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
		sp1 = sp4;//��sp4������ָ����Դ������һ����Ϊsp1�Ķ������sp1ԭ����ָ�����Դ������-1
		cout << sp1.GetRefCount() << endl;   //3

		cout << sp3.GetRefCount() << endl;   //3
		cout << sp4.GetRefCount() << endl;   //3
		sp3 = sp4;//����ָ��ͬһ��Դ��ĸ�ֵ�����Դ����ˣ���Դ��������
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
	//���shared_ptr�е�ѭ����������
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

	//����shared_ptr�ɻ�����
	struct ListNode
	{
		//shared_ptr<ListNode> _next;
		//shared_ptr<ListNode> _prev;
		//�ϱߵĶ��巽ʽ������ɻ������⣬������Դ���ղ��ᱻ�ͷ�

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

		//�������ڵ������������鿴�Ƿ�����shared_ptr�ĳɻ�����
		node1->_next = node2;
		node2->_prev = node1;

		cout << node1.GetRefCount() << endl;//���ɻ������������Ϊ2������Դ���ᱻϵͳ���գ�����ڴ�й¶
		cout << node2.GetRefCount() << endl;//�����ɻ��������Ϊ1������Դ�ᱻ�ͷţ����������ListNode����������

	}


	//����ɾ����
	template<class T>
	class FreeFunc
	{
		void operator()(T* ptr)
		{
			cout << "free:" << ptr << endl;
			delete ptr;
		}
	};

	//��Ҫ��shared_ptrд������ģ�������
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
	//Txt::test_shared_ptr_threads();//�̰߳�ȫ�Ĳ���
	//Txt::test_cycle_ref();

		//// ����ɾ���� ->�º��� lamber  �˽�һ�� �����к��ٿ���
		//std::shared_ptr<A> sp1(new A[10], DeleteArray<A>());
		//std::shared_ptr<A> sp2(new A[10], [](A* ptr){delete[] ptr; });
	
		//std::shared_ptr<A> sp3((A*)malloc(sizeof(A)), [](A* ptr){free(ptr); });
		//std::shared_ptr<FILE> sp4(fopen("test.txt", "w"), [](FILE* ptr){fclose(ptr); });

	system("pause");
	return 0;
}