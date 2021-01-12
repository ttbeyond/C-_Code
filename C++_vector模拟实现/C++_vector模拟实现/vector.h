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
		typedef const T* const_iterator;//const���ε�

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
		//����
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}
		//��������//���
		////д��һ
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
		//д����
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(v.capacity());
			for (const auto e : v)
				push_back(e);
		}
		//��ֵ����
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

		////�ִ�д��
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
		//����
		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				//Ҫ��ǰ����ԭ��С�Ŀռ����Ч���ȴ�С
				size_t len = size();
				T* tmp = new T[n];
				//�����һ�����ݣ����ռ�ʱ_startΪ�յ����
				if (_start)
				{
					//���ֽڿ�����ǳ���������һ��ʹ���Զ������͵�vector�ͻ����
					//memcpy(tmp, _start, sizeof(T)*size());

					for (size_t i = 0; i < len; ++i)
					{
						tmp[i] = _start[i];//����operator=�����
					}
					delete[] _start;
				}
				//��������
				_start = tmp;
				_finish = tmp + len;//���ﲻ��ֱ�Ӽ�size(),��Ϊԭ�ռ��ѱ��ͷ�
				_endofstorage = tmp + n;
			}
		}
		//Ĭ������Ԫ�ظ�һ��T���͵�ȱʡֵ��ԭ�򣺲�֪��������ʲô���͵�ֵ�����ô˺���
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
			////�ռ���������Ҫ���ݵ����
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

			//��������//һ�����ݵ�������ǰ��pos�ͻ�ʧЧ�������Ҫ����pos
			if (_finish == _endofstorage)
			{
				//1��4�д���Ϊ�����µ�������pos��λ�ã���Ϊ���ݺ�ɿռ�ᱻ�ͷţ�
				//����轫posλ�ø������¿ռ��ϣ��Է�ֹ������ʧЧ���⡣
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
		iterator _start;//ָ����ЧԪ�صĵ�һ��λ��
		iterator _finish;//ָ����ЧԪ�ص����һ���ĺ��
		iterator _endofstorage;//�ռ��С

	};

	void test1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		//���ֱ����Ĳ���
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

	//����resize()
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

	//���Կ������죬���,��ֵ
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