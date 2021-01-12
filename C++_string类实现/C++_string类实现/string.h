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
		//������
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str+_size;
		}
		//����
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];//+1������Ϊ'\0'Ԥ��һ���ռ�
			strcpy(_str, str);
		}

		//��������
		string(string& s)
			:_str(nullptr),
			_size(0),
			_capacity(0)
		{
			string tmp(s._str);
			this->swap(tmp);
			//swap(tmp);���ϵȼ�
		}
		//s.swap(s1)��s��s1�����ݽ��н���
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}
		//��ֵ���������
		string& operator=(string s)
		{
			this->swap(s);

			return *this;
		}
		//��Ч����
		size_t size()const
		{
			return _size;
		}
		//������С
		size_t capacity()
		{
			return _capacity;
		}
		//��const��[]
		char& operator[](size_t i)
		{
			assert(i < _size);
			return _str[i];
		}
		//const��[]
		const char& operator[](size_t i)const
		{
			assert(i < _size);
			return _str[i];
		}
		//C��ʽ�ķ���
		const char* c_str()
		{
			return _str;
		}

		//����
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		//����
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
			   char* tmp = new char[n + 1];
			   strcpy(tmp, _str);
			   delete[] _str;
			   _str = tmp;
			   _capacity = n;//����������С
			}
		}

		//�ı���Ч�ַ��Ĵ�С
		void resize(size_t n,char ch = '\0')
		{
			//С�ڵ���ԭ����Ч��С�����
			if (n <= _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				//������Ҫ���ݵ����
				if (n > _capacity)
				{
					reserve(n);
				}
				//��Ҫ�ò����������
				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = ch;
				}
				_size = n;
				_str[_size] = '\0';
			}
		}
		//β��
		void push_back(char ch)
		{
			if (_size == _capacity)//�����������
			{
				size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
				reserve(newcapacity);
			}
			//_str[_size++] = ch;
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}
		//β���ַ���
		void append(const char* str)
		{
			int len = strlen(str);
			if (_size + len > _capacity)//�����������
			{
				size_t newcapacity = _size + len;//��֤Ҫ���������+len�պú���
				reserve(newcapacity);
			}

			strcpy(_str + _size, str);//_str+_size���ɴ������һ��λ��
			_size += len;             //������Ч�ַ��Ĵ�С
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
		//����λ�ò���
		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
				reserve(newcapacity);
			}
			size_t end = _size;
			while (end >= pos)//��һ��_str[end]��ʵΪ'\0'
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
			//�����Ƿ���Ҫ����
			if (_size + len>_capacity)
			{
				reserve(_size + len);
			}

			//Ų������
			size_t end = _size;
			while (end >= (int)pos)
			{
				_str[end + len] = _str[end];
				--end;
			}
		//ע�⣺�˴���������strcpy��ԭ��strcpy�Ὣ'\0'������ȥ�����Ḳ��һ���ַ�
			strncpy(_str + len, str, len);
			_size += len;
          
			return *this;
		}
	  //����λ��ɾ��
	  string& erase(size_t pos, size_t len = npos)
	  {
		  assert(pos < _size);
		  //ɾ��posλ�ú����е��ַ�
		  if (len >= _size - pos)
		  {
			  _str[pos] = '\0';
			  _size = pos;
		  }
		  else
		  {
			  size_t i = pos + len;//��Ҫ�����ַ��ĵ�һ��λ��
			  while (i <= _size)
			  {
				  _str[pos++] = _str[i++];
			  }
			  _size -= len;//���´�С
		  }
		  return *this;
	  }
	  //Ѱ���ַ�
	  size_t find(char ch, size_t pos = 0)
	  {
		  for (size_t i = 0; i < _size; ++i)
		  {
			  if (_str[i] == ch)//�ҵ������±�
				  return i;
		  }
		  return npos;
	  }
	  //Ѱ���ַ���
	  size_t find(const char* str, size_t pos = 0)
	  {
		  char* p = strstr(_str, str);
		  //�Ҳ���
		  if (p == nullptr)
			  return npos;
		  else//�ҵ�
			  return p - _str;
	  }
	  //strcmp,���ڷ���һ������0���������ڣ�0��С�ڣ�С��0����
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
		size_t _size;      //��Ч�ַ�
		size_t _capacity;  //������С��Ҳ��Ϊ��Ԥ���ռ�//'\0'������Ч�ַ�
	};
	size_t string::npos = -1;//���ε����ֵ
	istream& operator>>(istream& in, string& s)
	{
		while (1)
		{
           char ch;
		   //in >> ch;
		   ch = in.get();
		   if (ch == ' ' || ch == '\n')//�����ո���н���
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

		s.resize(8, 'a');//ͬ��
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