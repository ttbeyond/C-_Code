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
//		cout << "����" << this << endl;
//	}
//	~Test()
//	{
//		cout << "~����" << this << endl;
//	}
//
//private:
//	int _data;
//};
//void Test1()
//{
//	// ���뵥��Test���͵Ŀռ�
//	Test* p1 = (Test*)malloc(sizeof(Test));
//	free(p1);
//
//	// ����10��Test���͵Ŀռ�
//	Test* p2 = (Test*)malloc(sizeof(Test) * 10);
//	free(p2);
//}
//
//void Test2()
//{
//	// ���뵥��Test���͵Ķ���
//	Test* p1 = new Test;
//	delete p1;
//
//	// ����10��Test���͵Ķ���
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
//	//�ڶ��Ͽ���4��G�Ŀռ�
//	void* p = new char[0xfffffffful];//��ϵͳ��Ϊ64λ����ʵ��
//	cout << "new:" << p << endl;
//		system("pause");
//
//	return 0;
//}

//template<typename T>//ģ��ؼ���
////ʹ��ģ��ʵ�ֲ�ͬ���͵Ľ�������
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
//	//����䲻��ͨ�����룬��Ϊ�ڱ����ڼ䣬��������������ʵ����ʱ����Ҫ������ʵ������
//	//ͨ��ʵ��a1��T����Ϊint��ͨ��ʵ��d1��T����Ϊdouble���ͣ���ģ������б���ֻ��һ��T��
//	//�������޷�ȷ���˴����׸ý�Tȷ��Ϊint ���� double���Ͷ�����
//	//ע�⣺��ģ���У�������һ�㲻���������ת����������Ϊһ��ת�������⣬����������Ҫ���ڹ�
//
//	//���
//	//1.���ڶ�������������ǿתΪ���һ������������ͬ
//	//cout << ADD(a, (int)x) << endl;
//	//2.��ʽʵ����
//	cout << ADD<int>(a, x) << endl;
//
//
//	//cout << ADD(a, b) << endl;
//	//cout << ADD(x, y) << endl;
//
//	system("pause");
//	return 0;
//}

// ��̬˳���
//#include<assert.h>
//template<class T>
//class Vector
//{
//public:
//	Vector(size_t capacity = 10)//ֱ�Ӹ�����ʮ����С�Ŀռ�
//		: _pData(new T[capacity])
//		, _size(0)
//		, _capacity(capacity)
//	{}
//
//	// ʹ������������ʾ�������������������ⶨ�塣
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
//	//������Ӧ�ÿ��ǵ����ݵ�����
//
//	//ʵ�ֵ��е�����//û���ͷžɵĿռ�
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


//string��ϰ
#include<iostream>
#include<string>
using namespace std;
//int main()
//{
//	string s1;            //������յ�string�����s1
//	string s2("hello ");  //��C��ʽ�ַ��������string�����s2
//	string s3("world");   //ͬ��
//	string s4(11, 't');   //��11���ַ�t����string�����s4
//	string s5(s3);         //��s3��������s5
//	string s6(s3, 1);
//
//
//	//��Ϊû�а�<string>,�����Ҫ��->����.c_str()�ķ�����stringת��Ϊchar*�ķ�ʽ�������
//	//cout<<s3<<endl;//����
//	/*cout << (s1 = s2).c_str() << endl;
//	cout << s3.c_str() << endl;*/
//
//	//����stringͷ�ļ�֮��
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
//	cout << s.size() << endl;    //11 ����s����Ч����
//	cout << s.length() << endl;  //11 ͬ��
//	cout << s.capacity() << endl;//15 ����Ϊs�����˶��Ŀռ�(��������ֵΪ��Ч�ַ�������)
//	cout << s.capacity() << endl;//15
//	cout << endl;
//	cout << endl;
//	cout << endl;
//
//	s.clear();//���s//���ֻ�ǽ���size��Ϊ0����û�иı���ײ�ռ��СС(capacity)
//	cout << s.empty() << endl;//�пգ��շ���1(true)���ǿշ���0(false)
//	cout << s.capacity() << endl;//15
//	cout << s.size() << endl;    //0
//
//	cout << endl;
//	cout << endl;
//	cout << endl;
//
//	s.resize(20, 'a');//��s����Ч�ַ��������ӵ�20�������λ����a���
//	cout << s << endl;           //20��a//ԭ��s����һ�������б����
//	cout << s.size() << endl;    //20
//	cout << s.capacity() << endl;//31
//
//	cout << endl;
//	cout << endl;
//	cout << endl;
//
//
//	s.resize(5);//��s����Ч�ַ���СΪ5��
//	cout << s << endl;           //5��a
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
//	//reserve����ı�string�е���Ч����
//	s.reserve(100);
//	cout << s.size() << endl;    //0
//	cout << s.capacity() << endl;//111
//	cout << endl;
//	cout << endl;
//	cout << endl;
//
//	//reserve�Ĳ���С��string�ĵײ�ռ��Сʱ��������Сstring�ĵײ�ռ�
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
//	//s1[]���ʵڲ����char& operator[](size_t pos);
//	//s2[]            const char& operator[](size_t pos)const;
//	cout << s1[0] << ' ' << s2[0] << endl;
//
//	//��const���󣬿��Ա���
//	s1[0] = 'c';
//	cout << s1 << endl;
//	cout << endl;
//	cout << endl;
//
//	//֧��������������ʽ�ķ���
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
//	//str.push_back(' '); //β��һ���ַ�
//	//str.append("hello ");//׷���ַ���
//	//cout << str << endl;
//
//	//str += 'w';      //׷���ַ�'w'
//	//str += "orld";   //׷���ַ���"orld"
//	//cout << str << endl;// hello world
//	//cout << str.c_str() << endl;//��C���Ե���ʽ���д�ӡ
//    
//	string str("beyond.com");
//	size_t pos = str.find('.');//���ַ�����ĳ���ַ���λ��
//	cout << pos << endl;
//	//��posλ�ÿ�ʼ��ȡ��Ч����-pos���ַ�(��posλ�ÿ�ʼ���ַ�������)��������ȡ�����ַ���������str1
//	string str1(str.substr(pos, (str.size() - pos)));
//	cout <<str1 << endl;
//
//}
//int main()
//{
//	// ȡ��url�е�����
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
//	cout << address << endl;//�����www.cplusplus.com
//
//	// ɾ��url��Э��ǰ׺
//	size_t pos = url.find("://");//�ҵ��ַ�����://���ֵ�λ��
//	cout << pos << endl;
//	url.erase(0, pos + 3);//ɾ���ַ���[0,pos+3]λ�õ����ݣ�����ͷɾ
//	cout << url << endl;//�����www.cplusplus.com/reference/string/string/find/
//	return 0;
//}

//void TestPushBack()
//{
//	string s;
//	//û��Ԥ���ռ�
//	size_t sz = s.capacity();
//	cout << "making s grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		s += 'c';
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << '\n';//�ᷢ������capacity������
//		}
//	}
//}
//void TestPushBack_P()
//{
//	string s;
//	s.reserve(100);//Ԥ���ÿռ䣬����±�capacity��������
//	size_t sz = s.capacity();
//
//	cout << "making s grow:\n";
//	for (int i = 0; i < 100; ++i)//׷��100��
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
//	//û��Ԥ���ռ�
//	TestPushBack();
//	cout << endl;
//
//	//Ԥ���ռ�
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
//	//����������Ϻ��ж�
//	//ԭ��ǳ�������⣬ͬһ��ռ䱻�ͷ����ε���
//	String s("hello world");
//	String s1(s);//����Ĭ�ϵĿ������죬����s��s1����һ��ռ䣬��������ʱͬһ�ռ䱻�ͷ����Σ���˳���
//
//	return 0;
//
//}

class String
{
public:
	//����
	String(const char* str = "")//""��ߴ���һ��'\0'//ע��˴����ܸ�=nullptr��������Ҫ����һ���յĶ����ڳ�ʼ��ʱ��strlen(nullptr)��ֱ�ӵ��±���
		
	{
		if (str == nullptr)
		{
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	//��������//���//��ͳд��
	String(const String& s)
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}

	//�ִ�д���Ŀ��������븳ֵ
	//String(const String& s)
	//	:_str(nullptr)
	//{
	//  //String tmp(s);//����д���������Ϊ���ÿ�������
	//	String tmp(s._str);//����һ����s��ͬ��
	//    swap(_str, tmp._str);//ͨ��������������
	//}
	////s1=s3,s1Ϊ�˺�����this������sΪs3�����������һ����ʱ���󣬣��ڴ���ʱ�Ϳ��������ˣ�
	////����ʱ�����ڳ�������ʱ������칹������������
	//String& operator=(String s)
	//{
	//	swap(_str, s._str);
	//	return *this;
	//}

	String& operator=(const String& s)
	{
		if (this != &s)//��ֹ�Լ����Լ���ֵ
		{
			char* pStr = new char[strlen(s._str) + 1];
			strcpy(pStr, s._str);
			delete[] _str;
			_str = pStr;
		}

		return *this;
	}
	//����
	~String()
	{
		if (_str)//�����������²���//�վͲ���������
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



////��֤���Ĵ�
//class Solution {
//public:
//	//�ж����Ƿ�Ϊ��ĸ
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
//			//�����������������ַ�
//			while (begin<end && (Ischar(s[begin]) == false))
//				++begin;
//			while (begin<end && (Ischar(s[end]) == false))
//				--end;
//
//			if (begin<end)
//			{
//				//���ͷβ�Ƿ����(��ĸ�����ִ�Сд)
//				if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32)
//					return false;
//			}
//			++begin;
//			--end;
//		}
//		return true;
//	}
//};