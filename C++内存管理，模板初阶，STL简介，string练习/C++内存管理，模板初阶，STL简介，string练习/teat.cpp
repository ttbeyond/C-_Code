//#include<iostream>
//using namespace std;

//int main()
//{
//	int* ptr = new int[3];
//	cout << ptr + 1 << endl;
//	cout << ptr + 2 << endl;
//	cout << ptr + 3 << endl;
//	cout << ptr + 4 << endl;
//
//	cout << &ptr + 1 << endl;
//	cout << &ptr + 2 << endl;
//	cout << &ptr + 3 << endl;
//	cout << &ptr + 4 << endl;
//
//	delete ptr;
//	system("pause");
//	return 0;
//}

//class Test
//{
//public:
//	Test()
//		: _data(0)
//	{
//		cout << "构造" << this << endl;
//	}
//	~Test()
//	{
//		cout << "~析构" << this << endl;
//	}
//
//private:
//	int _data;
//};
//void Test1()
//{
//	// 申请单个Test类型的空间
//	Test* p1 = (Test*)malloc(sizeof(Test));
//	free(p1);
//
//	// 申请10个Test类型的空间
//	Test* p2 = (Test*)malloc(sizeof(Test) * 10);
//	free(p2);
//}
//
//void Test2()
//{
//	// 申请单个Test类型的对象
//	Test* p1 = new Test;
//	delete p1;
//
//	// 申请10个Test类型的对象
//	Test* p2 = new Test[10];
//	delete[] p2;
//}
//int main()
//{
//	//Test1();
//	Test2();
//	system("pause");
//	return 0;
//}

//int main()
//{
//	//在堆上开辟4个G的空间
//	void* p = new char[0xfffffffful];//将系统调为64位即可实现
//	cout << "new:" << p << endl;
//		system("pause");
//
//	return 0;
//}

//template<typename T>//模板关键字
////使用模板实现不同类型的交换函数
//void Swap(T& p,T& q)
//{
//	T tmp = p;
//	p = q;
//	q = tmp;
//}

//template<class T>
//void Swap(T& p, T& q)
//{
//	T tmp = p;
//	p = q;
//	q = tmp;
//}
//int main()
//{
//	int a = 2, b = 3;
//	double x = 3.1, y = 4.4;
//	Swap(a, b);
//	Swap(x, y);
//
//	cout << a << '-' << b << endl;
//	cout << x << '-' << y << endl;
//
//	system("pause");
//	return 0;
//}

//template<class T>
//T ADD(const T& p, const T& q)
//{
//	return p + q;
//}
//int main()
//{
//	int a = 2, b = 3;
//	double x = 3.1, y = 4.4;
//	
//	ADD(a, b);
//	ADD(x, y);
//
//	//ADD(a, y);
//	//该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
//	//通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有一个T，
//	//编译器无法确定此处到底该将T确定为int 或者 double类型而报错
//	//注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅
//
//	//解决
//	//1.将第二个参数的类型强转为与第一个参数类型相同
//	//cout << ADD(a, (int)x) << endl;
//	//2.显式实例化
//	cout << ADD<int>(a, x) << endl;
//
//
//	//cout << ADD(a, b) << endl;
//	//cout << ADD(x, y) << endl;
//
//	system("pause");
//	return 0;
//}

// 动态顺序表
//#include<assert.h>
//template<class T>
//class Vector
//{
//public:
//	Vector(size_t capacity = 10)//直接给开了十个大小的空间
//		: _pData(new T[capacity])
//		, _size(0)
//		, _capacity(capacity)
//	{}
//
//	// 使用析构函数演示：在类中声明，在类外定义。
//	~Vector();
//
//	void PushBack(const T& data);
//
//	void PopBack()
//	{
//		--_size;
//	}
//
//	size_t Size()
//	{
//		return _size;
//	}
//
//	T& operator[](size_t pos)
//	{
//		assert(pos < _size);
//
//		return _pData[pos];
//	}
//
//private:
//	T* _pData;
//	size_t _size;
//	size_t _capacity;
//};
//
//template<class T>
//Vector<T>::~Vector()
//{
//	assert(_pData);
//	delete[] _pData;
//	_size = 0;
//	_capacity = 0;
//}
//template<class T>
//void Vector<T>::PushBack(const T& data)
//{
//	//完整的应该考虑到增容的问题
//
//	//实现的有点问题//没有释放旧的空间
//	size_t newcapacity = _capacity == 0 ? 2 : 2 * _capacity;
//	if (_size==_capacity)
//	{
//		auto* p = new T(newcapacity);
//		memcpy(p,_pData, sizeof(_pData)*_capacity);	
//		
//	}
//	_capacity = newcapacity;
//	_pData[_size++] = data;
//}
//
//int main()
//{
//	Vector<int> st1;
//	st1.PushBack(1);
//	st1.PushBack(2);
//	st1.PushBack(3);
//
//	Vector<double> st2;
//	st2.PushBack(1.1);
//	st2.PushBack(2.2);
//	st2.PushBack(3.3);
//
//	for (size_t i = 0; i < st1.Size(); ++i)
//	{
//		cout << st1[i] << ' ';
//	}
//	cout << endl;
//
//	for (size_t i = 0; i < st1.Size(); ++i)
//	{
//		cout << st2[i] << ' ';
//	}
//	cout << endl;
//
//	system("pause");
//	return 0;
//}


//string练习
#include<iostream>
#include<string>
using namespace std;
//int main()
//{
//	string s1;            //构造出空的string类对象s1
//	string s2("hello ");  //用C格式字符串构造出string类对象s2
//	string s3("world");   //同上
//	string s4(11, 't');   //用11个字符t构造string类对象s4
//	string s5(s3);         //用s3拷贝构造s5
//	string s6(s3, 1);
//
//
//	//因为没有包<string>,因此需要用->对象.c_str()的方法将string转化为char*的方式进行输出
//	//cout<<s3<<endl;//报错
//	/*cout << (s1 = s2).c_str() << endl;
//	cout << s3.c_str() << endl;*/
//
//	//包了string头文件之后
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//	cout << s5 << endl;
//	cout << s6 << endl;
//
//	return 0;
//}

//int main()
//{
//	string s("hello world");
//	string s1(20,'t');
//
//	cout << s.size() << endl;    //11 计算s的有效长度
//	cout << s.length() << endl;  //11 同上
//	cout << s.capacity() << endl;//15 计算为s开辟了多大的空间(函数返回值为有效字符串长度)
//	cout << s.capacity() << endl;//15
//	cout << endl;
//	cout << endl;
//	cout << endl;
//
//	s.clear();//清空s//清空只是将其size置为0，并没有改变其底层空间大小小(capacity)
//	cout << s.empty() << endl;//判空，空返回1(true)，非空返回0(false)
//	cout << s.capacity() << endl;//15
//	cout << s.size() << endl;    //0
//
//	cout << endl;
//	cout << endl;
//	cout << endl;
//
//	s.resize(20, 'a');//将s的有效字符个数增加到20，多出的位置用a填充
//	cout << s << endl;           //20个a//原因：s在上一步操作中被清空
//	cout << s.size() << endl;    //20
//	cout << s.capacity() << endl;//31
//
//	cout << endl;
//	cout << endl;
//	cout << endl;
//
//
//	s.resize(5);//将s中有效字符缩小为5个
//	cout << s << endl;           //5个a
//	cout << s.size() << endl;    //5
//	cout << s.capacity() << endl;//31
//
//
//	return 0;
//}

//int main()
//{
//	string s;
//
//	//reserve不会改变string中的有效个数
//	s.reserve(100);
//	cout << s.size() << endl;    //0
//	cout << s.capacity() << endl;//111
//	cout << endl;
//	cout << endl;
//	cout << endl;
//
//	//reserve的参数小于string的底层空间大小时，不会缩小string的底层空间
//	s.reserve(50);
//	cout << s.size() << endl;    //0
//	cout << s.capacity() << endl;//111
//	return 0;
//}

//int main()
//{
//	string s1("hello world");
//	const string s2("change world");
//
//	cout << s1 << ' ' << s2 << endl;
//	//s1[]访问第层调用char& operator[](size_t pos);
//	//s2[]            const char& operator[](size_t pos)const;
//	cout << s1[0] << ' ' << s2[0] << endl;
//
//	//非const对象，可以被改
//	s1[0] = 'c';
//	cout << s1 << endl;
//	cout << endl;
//	cout << endl;
//
//	//支持类似于数组形式的访问
//	for (int i = 0; i < s1.size(); ++i)
//	{
//		cout << s1[i] << ' ';
//	}
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	//string str;
//	//str.push_back(' '); //尾插一个字符
//	//str.append("hello ");//追加字符串
//	//cout << str << endl;
//
//	//str += 'w';      //追加字符'w'
//	//str += "orld";   //追加字符串"orld"
//	//cout << str << endl;// hello world
//	//cout << str.c_str() << endl;//以C语言的形式进行打印
//    
//	string str("beyond.com");
//	size_t pos = str.find('.');//找字符串中某个字符的位置
//	cout << pos << endl;
//	//从pos位置开始截取有效个数-pos个字符(从pos位置开始到字符串结束)，用所截取到的字符串来构造str1
//	string str1(str.substr(pos, (str.size() - pos)));
//	cout <<str1 << endl;
//
//}
//int main()
//{
//	// 取出url中的域名
//	string url("http://www.cplusplus.com/reference/string/string/find/");
//	cout << url << endl;
//	size_t start = url.find("://");
//	if (start == string::npos)
//	{
//		cout << "invalid url" << endl;
//		return 0;
//	}
//	start += 3;
//	size_t finish = url.find('/', start);
//	string address = url.substr(start, finish - start);
//	cout << address << endl;//输出：www.cplusplus.com
//
//	// 删除url的协议前缀
//	size_t pos = url.find("://");//找到字符串中://出现的位置
//	cout << pos << endl;
//	url.erase(0, pos + 3);//删除字符串[0,pos+3]位置的内容，类似头删
//	cout << url << endl;//输出：www.cplusplus.com/reference/string/string/find/
//	return 0;
//}

//void TestPushBack()
//{
//	string s;
//	//没有预留空间
//	size_t sz = s.capacity();
//	cout << "making s grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		s += 'c';
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << '\n';//会发生几次capacity的增长
//		}
//	}
//}
//void TestPushBack_P()
//{
//	string s;
//	s.reserve(100);//预留好空间，因此下边capacity不会增加
//	size_t sz = s.capacity();
//
//	cout << "making s grow:\n";
//	for (int i = 0; i < 100; ++i)//追加100次
//	{
//		s += 'c';
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}
//int main()
//{
//	//没有预留空间
//	TestPushBack();
//	cout << endl;
//
//	//预留空间
//	TestPushBack_P();
//	return 0;
//}
#include<assert.h>

//class String
//{
//public:
//	String(const char* str="")
//	{
//		if (str == nullptr)
//		{
//           assert(0);
//		   return;
//		}
//		_str = new char[strlen(str) + 1];
//		strcpy(_str , str);
//	}
//	~String()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//private:
//	char* _str;
//};
//int main()
//{
//	//程序运行完毕后中断
//	//原因：浅拷贝问题，同一块空间被释放俩次导致
//	String s("hello world");
//	String s1(s);//调用默认的拷贝构造，导致s与s1共用一块空间，而在析构时同一空间被释放俩次，因此出错
//
//	return 0;
//
//}

class String
{
public:
	//构造
	String(const char* str = "")//""里边存了一个'\0'//注意此处不能给=nullptr，否则你要构造一个空的对象，在初始化时，strlen(nullptr)会直接导致崩溃
		
	{
		if (str == nullptr)
		{
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	//拷贝构造//深拷贝//传统写法
	String(const String& s)
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}

	//现代写法的拷贝构造与赋值
	//String(const String& s)
	//	:_str(nullptr)
	//{
	//  //String tmp(s);//错误写法，此语句为调用拷贝构造
	//	String tmp(s._str);//构造一个与s相同的
	//    swap(_str, tmp._str);//通过交换，换过来
	//}
	////s1=s3,s1为此函数的this，参数s为s3拷贝构造出的一个临时对象，（在传参时就拷贝构造了）
	////而临时对象在出作用域时会调用异构函数进行销毁
	//String& operator=(String s)
	//{
	//	swap(_str, s._str);
	//	return *this;
	//}

	String& operator=(const String& s)
	{
		if (this != &s)//防止自己给自己赋值
		{
			char* pStr = new char[strlen(s._str) + 1];
			strcpy(pStr, s._str);
			delete[] _str;
			_str = pStr;
		}

		return *this;
	}
	//析构
	~String()
	{
		if (_str)//不空在做如下操作//空就不做处理即可
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
int main()
{

	String s("hello world");
	String s1(s);
	String s2;
	String s3=s;
	String s4(nullptr);


	return 0;

}



////验证回文串
//class Solution {
//public:
//	//判断其是否为字母
//	bool Ischar(char c)
//	{
//		if ((c <= 'z'&&c >= 'a') || (c <= 'Z'&&c >= 'A') || (c <= '9'&&c >= '0'))
//			return true;
//		else
//			return false;
//	}
//	bool isPalindrome(string s) {
//		if (s.empty())
//			return true;
//		int begin = 0;
//		int end = s.size() - 1;
//		while (begin<end)
//		{
//			//跳过不符合条件的字符
//			while (begin<end && (Ischar(s[begin]) == false))
//				++begin;
//			while (begin<end && (Ischar(s[end]) == false))
//				--end;
//
//			if (begin<end)
//			{
//				//检查头尾是否相等(字母不区分大小写)
//				if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32)
//					return false;
//			}
//			++begin;
//			--end;
//		}
//		return true;
//	}
//};