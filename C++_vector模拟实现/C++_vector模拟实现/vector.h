#include<iostream>
#include<assert.h>
#include<string>

using namespace std;

namespace txt_vector
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;//const修饰的

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}

		const_iterator begin()const
		{
			return _start;
		}
		const_iterator end()const
		{
			return _finish;
		}

		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}
		const T& operator[](size_t i)const
		{
			assert(i < size());
			return _start[i];
		}
		//构造
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}
		//拷贝构造//深拷贝
		////写法一
		//vector(const vector<T>& v)
		//{
		//	_start = new T[v.capacity()];
		//	_finish = _start;
		//	_endofstorage = _start + v.capacity();

		//	for (size_t i = 0; i < v.size(); ++i)
		//	{
		//		*_finish = v[i];
		//		++_finish;
		//	}
		//}
		//写法二
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(v.capacity());
			for (const auto e : v)
				push_back(e);
		}
		//赋值重载
		//vector<T>& operator=(const vector<T>& v)
		//{
		//	if (&v != this)
		//	{
		//		delete[] _start;
		//		_start = new T[v.capacity];
		//		memcpy(_start, v._start, sizeof(T)*v.size());
		//	}
		//	return *this;
		//}

		////现代写法
		vector<T>& operator=(vector<T> v)
		{
			swap(v);

			return *this;
		}
		void swap(vector<T> v)
		{
			::swap(_start, v._start);
			::swap(_finish, v._finish);
			::swap(_endofstorage, v._endofstorage);
		}
		//析构
		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				//要提前保存原来小的空间的有效长度大小
				size_t len = size();
				T* tmp = new T[n];
				//处理第一次增容，开空间时_start为空的情况
				if (_start)
				{
					//按字节拷贝，浅拷贝，因此一旦使用自定义类型的vector就会崩掉
					//memcpy(tmp, _start, sizeof(T)*size());

					for (size_t i = 0; i < len; ++i)
					{
						tmp[i] = _start[i];//调用operator=的深拷贝
					}
					delete[] _start;
				}
				//更新数据
				_start = tmp;
				_finish = tmp + len;//这里不能直接加size(),因为原空间已被释放
				_endofstorage = tmp + n;
			}
		}
		//默认填充的元素给一个T类型的缺省值，原因：不知道具体是什么类型的值来调用此函数
		void resize(size_t n, T val=T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}
		void push_back(const T& x)
		{
			////空间已满，需要增容的情况
			//if (_finish == _endofstorage)
			//{
			//	size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
			//	reserve(newcapacity);
			//}
			//*_finish = x;
			//++_finish;
			insert(_finish, x);
		}
		void pop_back()
		{
			assert(_start < _finish);
			--_finish;
		}

		void insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);

			//考虑增容//一旦增容迭代器以前的pos就会失效，因此需要更新pos
			if (_finish == _endofstorage)
			{
				//1，4行代码为：更新迭代器中pos的位置，因为增容后旧空间会被释放，
				//因此需将pos位置更新至新空间上，以防止迭代器失效问题。
				size_t n = pos - _start;//1
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
				pos = _start + n;       //4
			}
			iterator end = _finish;
			while (pos < end)
			{
				*end = *(end - 1);
				--end;
			}

			*pos = x;
			++_finish;
		}

		iterator erase(iterator pos)
		{
			assert(pos < _finish);

			iterator it = pos;
			while (it < _finish)
			{
				*it = *(it + 1);
				++it;
			}
			--_finish;

			return pos;
		}
		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _endofstorage - _start;
		}
	private:
		iterator _start;//指向有效元素的第一个位置
		iterator _finish;//指向有效元素的最后一个的后边
		iterator _endofstorage;//空间大小

	};

	void test1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		//三种遍历的测试
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << ' ';
			++it;
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << ' ';
		}
		cout << endl;

		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << ' ';
		}
		cout << endl;
	}

	void test2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		v.insert(v.begin(), 0);
		//v.erase(v.begin() + 1);
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
				it = v.erase(it);
			else
			{
				cout << *it << ' ';
				++it;
			}
		}
		cout << endl;
	}

	//测试resize()
	void test3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		for (auto e : v)
		{
			cout << e << ' ';
		}
		cout << endl;
		cout << v.size() << endl;
		cout << v.capacity() << endl << endl;

		v.resize(10,10);
		for (auto e : v)
		{
			cout << e << ' ';
		}
		cout << endl;
		cout << v.size() << endl;
		cout << v.capacity() << endl << endl;

		v.resize(20,20);
		for (auto e : v)
		{
			cout << e << ' ';
		}
		cout << endl;
		cout << v.size() << endl;
		cout << v.capacity() << endl << endl;
	}

	//测试拷贝构造，深拷贝,赋值
	void test4()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		vector<int> v2(v);
		vector<int> v3 = v2;

		for (auto e : v)
		{
			cout << e << ' ';
		}
		cout << endl;
		for (auto e : v2)
		{
			cout << e << ' ';
		}
		cout << endl;
		for (auto e : v3)
		{
			cout << e << ' ';
		}
		cout << endl;

	}
	void test5()
	{
		vector<string> v;
		v.push_back("11111111111111");
		v.push_back("11111111111111");
		v.push_back("11111111111111");
		v.push_back("11111111111111");

		for (auto e : v)
		{
			cout << e << ' ';
		}
		cout << endl;
	}
};