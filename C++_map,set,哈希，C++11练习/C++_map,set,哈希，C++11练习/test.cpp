#include<iostream>
#include<set>
using namespace std;

void test_set_use()
{
	int array[] = { 1, 4, 3, 2, 7, 8, 6, 5, 9, 0, 3, 6, 47, 6 };
	set<int> s(array, array + sizeof(array) / sizeof(array[0]));

	//set可以去重
	cout << s.size() << endl;//输出：11
	for (auto e : s)
		cout << e << ' ';
	cout << endl;
	//输出：0 1 2 3 4 5 6 7 8 9 47  //有序且元素不重复

	//使用迭代器逆向打印
	for (auto it = s.rbegin(); it != s.rend(); ++it)
		cout << *it << ' ';
	cout << endl;
	//count计算set中元素x出现的次数
	cout << "6出现的次数：" << s.count(6) << endl;

	//插入数据
	s.insert(10);
	for (auto e : s)
		cout << e << ' ';
	cout << endl;

	//插入已存在的值x，返回pair<x在色图中的位置，false>
	//插入不了，但并不报错
	auto i = s.insert(0);

	//删除值为x的元素，并返回删了几个，在set中一个值只能被删除一次
	//想要多次删除同样的值，则只会删除一次，之后的删除操作只会返回0次
	cout << s.erase(0) << endl;
	cout << s.erase(0) << endl;

	//删除区间//删除区间不能直接给位置，让其按下标进行删除
	//要借助指针，帮助确定区间大小
	s.erase(++s.begin(), --s.end());
	set<int>::iterator it2 = s.begin();
	while (it2 != s.end())
	{
		cout << *it2 << ' ';
		++it2;
	}
	cout << endl;

	if (!s.empty())
		cout << s.size() << endl;
	//s.find(),找值为x的元素，找到返回下标，
	//找不到返回iterator的end(),即set最后一个元素的后一个位置
	//要注意返回的是iterator迭代器的位置，因此需要用迭代器类型的变量进行接受
	//因此使用find()要检查其返回值是否越界

	//s.find()查找效率为log(N),而算法find()的查找效率为O(N)
	set<int>::iterator pos = s.find(1);
	if (pos != s.end())
		cout << *pos << endl;
}

//multiset允许键值冗余，即：允许相同的元素同时存在
//使用方法与set类似
void test_multiset()
{
	int arr[] = { 1, 4, 3, 2, 7, 8, 6, 5, 9, 0, 3, 6, 47, 6 };
	multiset<int> ms(arr, arr + sizeof(arr) / sizeof(int));

	multiset<int>::iterator it = ms.begin();
	while (it != ms.end())
	{
		cout << *it << ' ';
		++it;
	}
	cout << endl;

	//注意：multiset的find()，在寻找一个重复存在的数据时，返回的是其第一次出现的顺序
	multiset<int>::iterator pos = ms.find(6);
	cout << *pos << endl;

	++pos;
	cout << *pos << endl;

	++pos;
	cout << *pos << endl;
	++pos;
	cout << *pos << endl;

	for (auto e : ms)
		cout << e << ' ';
	cout << endl;
}


#include<map>
#include<string>
#include<vector>
void test_map_use()
{
	map<int, string> m;

	m.insert(pair<int, string>(1, "关羽"));
	m.insert(pair<int, string>(2, "张飞"));
	m.insert(pair<int, string>(3, "马超"));
	m.insert(pair<int, string>(4, "赵云"));//以上调用pair的构造函数，构造一个匿名对象
	m.insert(make_pair(5, "黄忠"));        //函数模板构造一个pair对象

	//map为<key,value>模型，使用了pair<first,second>，
	//相当于一个map的对象实际为为一个pair对象，而pair对象中存储了first与second俩个变量
	map<int, string>::iterator it = m.begin();
	while (it != m.end())
	{
		//基于上述原因，map的迭代器遍历需要做一下改动

		//cout << (*it).first << "：" << (*it).second << endl;
		cout << it->first << "：" << it->second << endl;
		++it;
	}
	//范围for也同理
	for (auto e : m)
	{
		cout << e.first <<"："<< e.second << endl;
	}
	cout << endl;


	////利用map统计元素出现次数1
	//vector<string> str = { "松花江", "白山", "黑水", "黑土地", "松花江", "黑水", "白山", "松花江", "白山" };
	//map<string, int> countMap;
	//for (auto& e : str)
	//{
	//	//insert成功返回数据iterator位置和其bool值true
	//	//失败返回已有数据的iterator位置和false
	//	pair<map<string, int>::iterator, bool> ret = countMap.insert(make_pair(e, 1));

	//	//注意：ret的键值对第一个内容为countMap中插入数据位置的迭代器，类似一个指针，第二个内容为插入是否成功的bool值，即true为插入成功，false为失败
	//	//其实这么写是为了与insert的返回值进行匹配
	//	if (ret.second == false)
	//		ret.first->second++;
	//}

	//for (auto e : countMap)
	//	cout << e.first << "：" << e.second << endl;
	//cout << endl;

	//利用map统计元素出现次数2
	//一般使用operator[]去1.修改；2.插入+修改
	//一般不用其做查找操作，原因：key不在时其会插入数据
	vector<string> str = { "松花江", "白山", "黑水", "黑土地", "松花江", "黑水", "白山", "松花江", "白山" };
	map<string, int> countMap;
	for (auto& e : str)
	{
		//[]原理：如果元素不在map中，则operator[]会插入pair<str,0>,返回映射对象(次数)的引用++
		//如果数据在map中，则operator[]返回对元素映射对象(次数)的引用，对它++
		countMap[e]++;
	}

	countMap["黑龙江"];        //插入
	countMap["黑龙江"] = 2;    //修改
	cout << countMap["黑龙江"] << endl;//查找，找出其key值对应的value
	countMap["东北"] = 5;      //插入+修改
	for (auto e : countMap)
		cout << e.first << "：" << e.second << endl;
	cout << endl;
}

//与multiset同理，允许数据冗余，其key值可以相同，对value不做要求，即可以相同，也可不同
//注意：multimap没有operator[]   原因：当有多个相同的key值时，查看、修改同一个key时，不知道该返回哪个key对应的value
void test_multimap()
{
	multimap<string, int> mm;
	mm.insert(pair<string,int>("苹果",1));
	mm.insert(pair<string, int>("香蕉", 2));
	mm.insert(pair<string, int>("苹果", 1));//俩个都相同
	mm.insert(pair<string, int>("苹果", 3));//key相同，value不同
	mm.insert(make_pair("石榴", 3));

	for (auto e : mm)
		cout << e.first << "：" << e.second << endl;
	cout << endl;

	//验证find
	//注意：使用find查找时，其实是按照key来查找的，无关value

	//multimap<string, int>::iterator pos1 = mm.find("2");//因此不能通过value来查找
	
	multimap<string, int>::iterator pos = mm.find("苹果");
	cout << pos->first << "：" << pos->second << endl;

	++pos;
	cout << pos->first << "：" << pos->second << endl;

	++pos;
	cout << pos->first << "：" << pos->second << endl;

	++pos;
	cout << pos->first << "：" << pos->second << endl;
}

#include<functional>
//排序是按照key的顺序来进行的，因此仿函数的类型只能是key，而不能是value
void test()
{
	map<int, string,greater<int>> m;

	m.insert(pair<int, string>(1, "关羽"));
	m.insert(pair<int, string>(2, "张飞"));
	m.insert(pair<int, string>(3, "马超"));
	m.insert(pair<int, string>(4, "赵云"));//以上调用pair的构造函数，构造一个匿名对象
	m.insert(make_pair(5, "黄忠"));

	for (auto e : m)
		cout << e.first <<"："<< e.second << endl;
	cout << endl;

	map<string, int,greater<string>> map;
	map.insert(make_pair("关羽", 1));
	map.insert(make_pair("张飞", 2));
	map.insert(make_pair("马超", 3));
	map.insert(make_pair("赵云", 4));
	map.insert(make_pair("黄忠", 5));
	for (auto e : map)
		cout << e.first << "：" << e.second << endl;
	cout << endl;
}
#if 0
int main()
{
	//test_set_use();
	//test_map_use();
	//test_multiset();
	//test_multimap();
	test();//仿函数使用测试

	return 0;
}
#endif


#if 0
//智能指针练习

//RAII简单模板
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr = nullptr)
		:_ptr(ptr)
	{}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	~SmartPtr()
	{
		if (_ptr)
			delete _ptr;
	}
private:
	T* _ptr;
};

void test1()
{
	//之开辟了空间，没有进行释放
	//交给智能指针sp处理
	int* p1 = new(int);
	SmartPtr<int> sp(p1);

}

int main()
{
	test1();


	system("pause");
	return 0;
}
#endif

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

namespace bit
{
	// C++11 支持拷贝的shared_ptr
	template<class T>
	class shared_ptr
	{
	public:
		// RAII
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pCount(new int(1))
			, _pMutex(new mutex)
		{}

		// copy(sp1)
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pCount(sp._pCount)
			, _pMutex(sp._pMutex)
		{
			AddRef();
		}

		// sp1 = sp4
		// sp3 = sp4; 本身sp3和sp4就是管理着同一块资源的
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			//if (this != &sp && _ptr != sp._ptr)
			if (_ptr != sp._ptr)
			{
				// 先释放原对象资源
				ReleaseRef();
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				_pMutex = sp._pMutex;
				AddRef();
			}

			return *this;
		}

		int GetRefCount()
		{
			return *_pCount;
		}

		// 引用计数的线程安全问题
		// 加引用计数
		void AddRef()
		{
			_pMutex->lock();
			++(*_pCount);
			_pMutex->unlock();
		}

		// 减引用计数
		void ReleaseRef()
		{
			bool deleteflag = false;
			_pMutex->lock();
			if (--(*_pCount) == 0)
			{
				delete _pCount;
				delete _ptr;
				//cout << "delete:" << _ptr << endl;
				deleteflag = true;
			}
			_pMutex->unlock();

			if (deleteflag == true)
			{
				delete _pMutex;
			}
		}

		~shared_ptr()
		{
			ReleaseRef();
		}

		// 像指针一样使用
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
	private:
		T* _ptr;
		int* _pCount; // 引用计数
		mutex* _pMutex;
	};

	
	void test_shared_ptr()
	{
		shared_ptr<int> sp1(new int);
		shared_ptr<int> copy1(sp1);
		shared_ptr<int> copy2(copy1);

		shared_ptr<int> sp3(new int);
		shared_ptr<int> sp4(sp3);

		sp1 = sp4;
		sp3 = sp4;
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

	// 他的产生是专门解决shared_ptr的循环引用问题
	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr()
			:_ptr(nullptr)
		{}

		weak_ptr(const shared_ptr<T>& sp)
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

	// 特定的场景下才会产生循环引用
	struct ListNode
	{
		//shared_ptr<ListNode> _next;
		//shared_ptr<ListNode> _prev;
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

		// 循环引用
		node1->_next = node2;
		node2->_prev = node1;

		cout << node1.GetRefCount() << endl;
		cout << node2.GetRefCount() << endl;
	}
}

#include <memory>

class A
{
public:
	~A()
	{
		cout << "~A()" << endl;
	}

	int _a1;
	int _a2;
};

template<class T>
struct DeleteArray
{
	void operator()(T* ptr)
	{
		delete[] ptr;
	}
};

int main()
{
	//bit::test_auto_ptr2();
	//bit::test_unique_ptr();
	//bit::test_shared_ptr();
	//bit::test_shared_ptr_threads();
	bit::test_cycle_ref();

	// 定制删除器 ->仿函数 lamber  了解一下 面试中很少考察
	/*std::shared_ptr<A> sp1(new A[10], DeleteArray<A>());
	std::shared_ptr<A> sp2(new A[10], [](A* ptr){delete[] ptr; });

	std::shared_ptr<A> sp3((A*)malloc(sizeof(A)), [](A* ptr){free(ptr); });
	std::shared_ptr<FILE> sp4(fopen("test.txt", "w"), [](FILE* ptr){fclose(ptr); });
*/
	return 0;
}