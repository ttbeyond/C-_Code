#include<iostream>
#include<set>
using namespace std;

void test_set_use()
{
	int array[] = { 1, 4, 3, 2, 7, 8, 6, 5, 9, 0, 3, 6, 47, 6 };
	set<int> s(array, array + sizeof(array) / sizeof(array[0]));

	//set����ȥ��
	cout << s.size() << endl;//�����11
	for (auto e : s)
		cout << e << ' ';
	cout << endl;
	//�����0 1 2 3 4 5 6 7 8 9 47  //������Ԫ�ز��ظ�

	//ʹ�õ����������ӡ
	for (auto it = s.rbegin(); it != s.rend(); ++it)
		cout << *it << ' ';
	cout << endl;
	//count����set��Ԫ��x���ֵĴ���
	cout << "6���ֵĴ�����" << s.count(6) << endl;

	//��������
	s.insert(10);
	for (auto e : s)
		cout << e << ' ';
	cout << endl;

	//�����Ѵ��ڵ�ֵx������pair<x��ɫͼ�е�λ�ã�false>
	//���벻�ˣ�����������
	auto i = s.insert(0);

	//ɾ��ֵΪx��Ԫ�أ�������ɾ�˼�������set��һ��ֵֻ�ܱ�ɾ��һ��
	//��Ҫ���ɾ��ͬ����ֵ����ֻ��ɾ��һ�Σ�֮���ɾ������ֻ�᷵��0��
	cout << s.erase(0) << endl;
	cout << s.erase(0) << endl;

	//ɾ������//ɾ�����䲻��ֱ�Ӹ�λ�ã����䰴�±����ɾ��
	//Ҫ����ָ�룬����ȷ�������С
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
	//s.find(),��ֵΪx��Ԫ�أ��ҵ������±꣬
	//�Ҳ�������iterator��end(),��set���һ��Ԫ�صĺ�һ��λ��
	//Ҫע�ⷵ�ص���iterator��������λ�ã������Ҫ�õ��������͵ı������н���
	//���ʹ��find()Ҫ����䷵��ֵ�Ƿ�Խ��

	//s.find()����Ч��Ϊlog(N),���㷨find()�Ĳ���Ч��ΪO(N)
	set<int>::iterator pos = s.find(1);
	if (pos != s.end())
		cout << *pos << endl;
}

//multiset�����ֵ���࣬����������ͬ��Ԫ��ͬʱ����
//ʹ�÷�����set����
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

	//ע�⣺multiset��find()����Ѱ��һ���ظ����ڵ�����ʱ�����ص������һ�γ��ֵ�˳��
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

	m.insert(pair<int, string>(1, "����"));
	m.insert(pair<int, string>(2, "�ŷ�"));
	m.insert(pair<int, string>(3, "��"));
	m.insert(pair<int, string>(4, "����"));//���ϵ���pair�Ĺ��캯��������һ����������
	m.insert(make_pair(5, "����"));        //����ģ�幹��һ��pair����

	//mapΪ<key,value>ģ�ͣ�ʹ����pair<first,second>��
	//�൱��һ��map�Ķ���ʵ��ΪΪһ��pair���󣬶�pair�����д洢��first��second��������
	map<int, string>::iterator it = m.begin();
	while (it != m.end())
	{
		//��������ԭ��map�ĵ�����������Ҫ��һ�¸Ķ�

		//cout << (*it).first << "��" << (*it).second << endl;
		cout << it->first << "��" << it->second << endl;
		++it;
	}
	//��ΧforҲͬ��
	for (auto e : m)
	{
		cout << e.first <<"��"<< e.second << endl;
	}
	cout << endl;


	////����mapͳ��Ԫ�س��ִ���1
	//vector<string> str = { "�ɻ���", "��ɽ", "��ˮ", "������", "�ɻ���", "��ˮ", "��ɽ", "�ɻ���", "��ɽ" };
	//map<string, int> countMap;
	//for (auto& e : str)
	//{
	//	//insert�ɹ���������iteratorλ�ú���boolֵtrue
	//	//ʧ�ܷ����������ݵ�iteratorλ�ú�false
	//	pair<map<string, int>::iterator, bool> ret = countMap.insert(make_pair(e, 1));

	//	//ע�⣺ret�ļ�ֵ�Ե�һ������ΪcountMap�в�������λ�õĵ�����������һ��ָ�룬�ڶ�������Ϊ�����Ƿ�ɹ���boolֵ����trueΪ����ɹ���falseΪʧ��
	//	//��ʵ��ôд��Ϊ����insert�ķ���ֵ����ƥ��
	//	if (ret.second == false)
	//		ret.first->second++;
	//}

	//for (auto e : countMap)
	//	cout << e.first << "��" << e.second << endl;
	//cout << endl;

	//����mapͳ��Ԫ�س��ִ���2
	//һ��ʹ��operator[]ȥ1.�޸ģ�2.����+�޸�
	//һ�㲻���������Ҳ�����ԭ��key����ʱ����������
	vector<string> str = { "�ɻ���", "��ɽ", "��ˮ", "������", "�ɻ���", "��ˮ", "��ɽ", "�ɻ���", "��ɽ" };
	map<string, int> countMap;
	for (auto& e : str)
	{
		//[]ԭ�����Ԫ�ز���map�У���operator[]�����pair<str,0>,����ӳ�����(����)������++
		//���������map�У���operator[]���ض�Ԫ��ӳ�����(����)�����ã�����++
		countMap[e]++;
	}

	countMap["������"];        //����
	countMap["������"] = 2;    //�޸�
	cout << countMap["������"] << endl;//���ң��ҳ���keyֵ��Ӧ��value
	countMap["����"] = 5;      //����+�޸�
	for (auto e : countMap)
		cout << e.first << "��" << e.second << endl;
	cout << endl;
}

//��multisetͬ�������������࣬��keyֵ������ͬ����value����Ҫ�󣬼�������ͬ��Ҳ�ɲ�ͬ
//ע�⣺multimapû��operator[]   ԭ�򣺵��ж����ͬ��keyֵʱ���鿴���޸�ͬһ��keyʱ����֪���÷����ĸ�key��Ӧ��value
void test_multimap()
{
	multimap<string, int> mm;
	mm.insert(pair<string,int>("ƻ��",1));
	mm.insert(pair<string, int>("�㽶", 2));
	mm.insert(pair<string, int>("ƻ��", 1));//��������ͬ
	mm.insert(pair<string, int>("ƻ��", 3));//key��ͬ��value��ͬ
	mm.insert(make_pair("ʯ��", 3));

	for (auto e : mm)
		cout << e.first << "��" << e.second << endl;
	cout << endl;

	//��֤find
	//ע�⣺ʹ��find����ʱ����ʵ�ǰ���key�����ҵģ��޹�value

	//multimap<string, int>::iterator pos1 = mm.find("2");//��˲���ͨ��value������
	
	multimap<string, int>::iterator pos = mm.find("ƻ��");
	cout << pos->first << "��" << pos->second << endl;

	++pos;
	cout << pos->first << "��" << pos->second << endl;

	++pos;
	cout << pos->first << "��" << pos->second << endl;

	++pos;
	cout << pos->first << "��" << pos->second << endl;
}

#include<functional>
//�����ǰ���key��˳�������еģ���˷º���������ֻ����key����������value
void test()
{
	map<int, string,greater<int>> m;

	m.insert(pair<int, string>(1, "����"));
	m.insert(pair<int, string>(2, "�ŷ�"));
	m.insert(pair<int, string>(3, "��"));
	m.insert(pair<int, string>(4, "����"));//���ϵ���pair�Ĺ��캯��������һ����������
	m.insert(make_pair(5, "����"));

	for (auto e : m)
		cout << e.first <<"��"<< e.second << endl;
	cout << endl;

	map<string, int,greater<string>> map;
	map.insert(make_pair("����", 1));
	map.insert(make_pair("�ŷ�", 2));
	map.insert(make_pair("��", 3));
	map.insert(make_pair("����", 4));
	map.insert(make_pair("����", 5));
	for (auto e : map)
		cout << e.first << "��" << e.second << endl;
	cout << endl;
}
#if 0
int main()
{
	//test_set_use();
	//test_map_use();
	//test_multiset();
	//test_multimap();
	test();//�º���ʹ�ò���

	return 0;
}
#endif


#if 0
//����ָ����ϰ

//RAII��ģ��
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
	//֮�����˿ռ䣬û�н����ͷ�
	//��������ָ��sp����
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
	// C++11 ֧�ֿ�����shared_ptr
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
		// sp3 = sp4; ����sp3��sp4���ǹ�����ͬһ����Դ��
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			//if (this != &sp && _ptr != sp._ptr)
			if (_ptr != sp._ptr)
			{
				// ���ͷ�ԭ������Դ
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

		// ���ü������̰߳�ȫ����
		// �����ü���
		void AddRef()
		{
			_pMutex->lock();
			++(*_pCount);
			_pMutex->unlock();
		}

		// �����ü���
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

		// ��ָ��һ��ʹ��
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
		int* _pCount; // ���ü���
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

	// ���Ĳ�����ר�Ž��shared_ptr��ѭ����������
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

	// �ض��ĳ����²Ż����ѭ������
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

		// ѭ������
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

	// ����ɾ���� ->�º��� lamber  �˽�һ�� �����к��ٿ���
	/*std::shared_ptr<A> sp1(new A[10], DeleteArray<A>());
	std::shared_ptr<A> sp2(new A[10], [](A* ptr){delete[] ptr; });

	std::shared_ptr<A> sp3((A*)malloc(sizeof(A)), [](A* ptr){free(ptr); });
	std::shared_ptr<FILE> sp4(fopen("test.txt", "w"), [](FILE* ptr){fclose(ptr); });
*/
	return 0;
}