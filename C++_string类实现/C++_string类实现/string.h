#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;

namespace txt
{
	class string
	{
	public:
		static size_t npos;
		//迭代器
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str+_size;
		}
		//构造
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];//+1操作：为'\0'预留一个空间
			strcpy(_str, str);
		}

		//拷贝构造
		string(string& s)
			:_str(nullptr),
			_size(0),
			_capacity(0)
		{
			string tmp(s._str);
			this->swap(tmp);
			//swap(tmp);与上等价
		}
		//s.swap(s1)将s与s1的内容进行交换
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}
		//赋值运算符重载
		string& operator=(string s)
		{
			this->swap(s);

			return *this;
		}
		//有效个数
		size_t size()const
		{
			return _size;
		}
		//容量大小
		size_t capacity()
		{
			return _capacity;
		}
		//非const的[]
		char& operator[](size_t i)
		{
			assert(i < _size);
			return _str[i];
		}
		//const的[]
		const char& operator[](size_t i)const
		{
			assert(i < _size);
			return _str[i];
		}
		//C格式的访问
		const char* c_str()
		{
			return _str;
		}

		//析构
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		//增容
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
			   char* tmp = new char[n + 1];
			   strcpy(tmp, _str);
			   delete[] _str;
			   _str = tmp;
			   _capacity = n;//更新容量大小
			}
		}

		//改变有效字符的大小
		void resize(size_t n,char ch = '\0')
		{
			//小于等于原本有效大小的情况
			if (n <= _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				//考虑需要增容的情况
				if (n > _capacity)
				{
					reserve(n);
				}
				//需要用参数填充的情况
				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = ch;
				}
				_size = n;
				_str[_size] = '\0';
			}
		}
		//尾插
		void push_back(char ch)
		{
			if (_size == _capacity)//考虑增容情况
			{
				size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
				reserve(newcapacity);
			}
			//_str[_size++] = ch;
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}
		//尾插字符串
		void append(const char* str)
		{
			int len = strlen(str);
			if (_size + len > _capacity)//考虑增容情况
			{
				size_t newcapacity = _size + len;//保证要增够，因此+len刚好合适
				reserve(newcapacity);
			}

			strcpy(_str + _size, str);//_str+_size：旧串的最后一个位置
			_size += len;             //更新有效字符的大小
		}
		string& operator+=(char ch)
		{
			this->push_back(ch);
			return *this;
		}
		string& operator+=(char* str)
		{
			this->append(str);
			return *this;
		}
		//任意位置插入
		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
				reserve(newcapacity);
			}
			size_t end = _size;
			while (end >= pos)//第一次_str[end]其实为'\0'
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			++_size;

			return *this;
		}
	  string& insert(size_t pos, const char* str)
		{
			assert(pos < _size);
			size_t len = strlen(str);
			//考虑是否需要增容
			if (_size + len>_capacity)
			{
				reserve(_size + len);
			}

			//挪动数据
			size_t end = _size;
			while (end >= (int)pos)
			{
				_str[end + len] = _str[end];
				--end;
			}
		//注意：此处不能能用strcpy；原因：strcpy会将'\0'拷贝过去，将会覆盖一个字符
			strncpy(_str + len, str, len);
			_size += len;
          
			return *this;
		}
	  //任意位置删除
	  string& erase(size_t pos, size_t len = npos)
	  {
		  assert(pos < _size);
		  //删除pos位置后所有的字符
		  if (len >= _size - pos)
		  {
			  _str[pos] = '\0';
			  _size = pos;
		  }
		  else
		  {
			  size_t i = pos + len;//所要保留字符的第一个位置
			  while (i <= _size)
			  {
				  _str[pos++] = _str[i++];
			  }
			  _size -= len;//更新大小
		  }
		  return *this;
	  }
	  //寻找字符
	  size_t find(char ch, size_t pos = 0)
	  {
		  for (size_t i = 0; i < _size; ++i)
		  {
			  if (_str[i] == ch)//找到返回下标
				  return i;
		  }
		  return npos;
	  }
	  //寻找字符串
	  size_t find(const char* str, size_t pos = 0)
	  {
		  char* p = strstr(_str, str);
		  //找不到
		  if (p == nullptr)
			  return npos;
		  else//找到
			  return p - _str;
	  }
	  //strcmp,大于返回一个大于0的数，等于：0；小于：小于0的数
	  bool operator<(const string& s)
	  {
		  int ret = strcmp(_str, s._str);
		  return ret < 0;
	  }
	  bool operator==(const string& s)
	  {
		  int ret = strcmp(_str, s._str);
		  return ret ==0;
	  }
	  bool operator<=(const string& s)
	  {
		  return *this < s || *this == s;
	  }
	  bool operator>(const string& s)
	  {
		  return !(*this <= s);
	  }
	  bool operator>=(const string& s)
	  {
		  return !(*this < s);
	  }
	  bool operator!=(const string& s)
	  {
		  return !(*this == s);
	  }

	private:
		char* _str;
		size_t _size;      //有效字符
		size_t _capacity;  //容量大小，也不为其预留空间//'\0'不是有效字符
	};
	size_t string::npos = -1;//整形的最大值
	istream& operator>>(istream& in, string& s)
	{
		while (1)
		{
           char ch;
		   //in >> ch;
		   ch = in.get();
		   if (ch == ' ' || ch == '\n')//遇到空格或换行结束
			   break;
		   else
			   s += ch;
		}
		return in;
	}
	ostream& operator<<(ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); ++i)
		{
			cout << s[i];
		}
		cout << endl;
		return out;
	}

	void test()
	{
		string s("hello world");
		cout << s;
		s.push_back('a');
		s.append("haha");
		cout << s;
	}
	void test1()
	{
		string s("hello");
		cout << s;
		s.insert(2, 't');
		cout << s;

		s.insert(0, "xt.");
		cout << s;
	}
	void test2()
	{
		string s("hello");
		cout << s<<endl;

		s.resize(8, 'x');//helloxxx
		cout << s << endl;

		s.resize(8, 'a');//同上
		cout << s << endl;

		s.resize(2, 'y');//he
		cout << s << endl;	
	}
	void test3()
	{
		string s("hello world");
		cout << s << endl;

		s.erase(5, 2);
		cout << s << endl;

        int n = s.find("llo",0);
		cout << n << endl;//2
	}
	void test4()
	{
		string s;
		cin >> s;
		cout << s;
	}
}