#include<iostream>
using namespace std;

//template<class T>
//bool Isequal( T& x1,  T& x2)
//{
//	cout << "模板调用" << endl;
//	return x1 == x2;
//}
//template<>
//bool Isequal<char*>( char*& x1, char*& x2)
//{
//	cout << "char*全特化" << endl;
//	if (strcmp(x1, x2) > 0)
//		return true;
//	return false;
//}
//template<>
//bool Isequal<char>(char& x1, char& x2)
//{
//	cout << "char的全特化" << endl;
//	return x1 == x2;
//}
//void test2()
//{
//   char* p1 = "asdf";
//   char* p2 = "zxcv";
//   //char*全特化调用
//   if (Isequal(p1, p2))
//	   cout << "相等" << endl;
//   else
//	   cout << "不相等" << endl;
//
//   //模板调用
//   int a = 3, b = 3;
//   if (Isequal(a, b))
//	   cout << "相等" << endl;
//   else
//	   cout << "不相等" << endl;
//
//   //char全特化调用
//   char c1 = 'a';
//   char c = 'a';
//   Isequal(c,c1);
//}
//int main()
//{
//	//test1();
//	test2();
//
//	return 0;
//}

//函数模板全特化
//template<class T1>
//bool isequal(T1& left, T1& right)
//{
//	cout << "模板调用" << endl;
//	return left == right;
//}
//template<>
//bool isequal<char*>(char*& left, char*& right)
//{
//	cout << "char*全特化" << endl;
//		if (strcmp(left, right) > 0)
//			return true;
//		return false;
//}
//template<>
//bool isequal<int>(int& left, int& right)
//{
//	cout << "int全特化" << endl;
//	return left == right;
//}
//
//int main()
//{
//	int a = 1, b = 2;
//	isequal(a, b);
//
//	char* p1 = "asdf", *p2 = "zxcv";
//	isequal(p1, p2);
//
//	return 0;
//
//}

//类模板的全特化与偏特化
//template<typename T1,typename T2>
//class txt
//{
//public:
//	txt()
//	{
//		cout << "类模板调用" << endl;
//	}
//private:
//	T1 _x1;
//	T2 _x2;
//	
//};
//
////类模板全特化
//template<>
//class txt<int, char>
//{
//public:
//	txt()
//	{
//		cout << "int，char的全特化调用" << endl;
//	}
//private:
//	char _x1;
//	char _x2;
//};

//类模板偏特化
//部分特化：将第一个参数特化为int
//template<class T1>
//class txt<int, T1>
//{
//public:
//	txt()
//	{
//		cout << "第一个参数为int的偏特化调用" << endl;
//	}
//private:
//	T1 _x1;
//	T1 _x2;
//};
//
////对模板参数进一步限制的偏特化调用
//template<class T1,class T2>
//class txt<T1&,T2&>
//{
//public:
//	txt()
//	{
//		cout << "将参数偏特化为引用的调用" << endl;
//	}
//private:
//	T1 _x1;
//	T2 _x2;
//};
//
//int main()
//{
//	txt<int, int> x1;  //第一个参数为int的偏特化调用
//	txt<int, char> x2; //int，char的全特化调用
//	txt<char, int> x3; //类模板调用
//	txt<int&, int&> x4;//将参数偏特化为引用的调用
//
//	return 0;
//}

//继承练习
//#include<string>
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "姓名：" << _name << endl;
//		cout << "年龄：" << _age << endl;
//	}
//private:
//	string _name = "txt";
//	int _age = 23;
//};

////Student为子类(也可称作：派生类)，Person为父类(也称为：基类)
//class Student :public Person
//{
//protected:
//	int _studentID;
//};
//
//class Teacher :public Person
//{
//protected:
//	int _jobID;
//};
//
//int main()
//{
//	Student s;
//	Teacher z;
//
//	s.Print();
//	z.Print();
//
//	return 0;
//}

//#include<string>
//class Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//
//int main()
//{
//	Student s1;
//	s1.Print();
//
//	Person first;
//	first.Print();
//
//	return 0;
//}

//class Person
//{
//public:
//	void Print()
//	{
//       cout << _age << endl;
//	}
//protected:
//	int _ID;
//private:
//	int _age;
//};
//
////三种继承方式都会继承基类的成员，区别在于访问权限
//class Student: private Person
////class Student : protected Person
////class Student :public Person
//{
//protected:
//	int _telnum;
//};
//int main()
//{
//	Student first;
//
//	return 0;
//}
//class Person
//{
//protected:
//	int _ID;
//	int _age;
//};
//
//class Student : public Person
//{
//protected:
//	int _telnum = 158;
//};
//int main()
//{
//	Student first;
//	Person one = first;
//	//first = one;//编译不过
//	Person* second = &first;
//	Person &third = first;
//
//	//基类的指针可以通过强制类型转换赋值给派生类的指针
//	Person* p = &first;
//	Student *pp = (Student*)p;
//
//	return 0;
//}

//四大默认函数调用顺序
//#include<string>
//class Person
//{
//public:
//	Person(const char* name="txt")
//		:_name(name)
//	{
//		cout << "父类构造" << endl;
//	}
//	Person(const Person& name)
//		:_name(name._name)
//	{
//		cout << "父类拷贝构造" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		cout << "父类赋值重载" << endl;
//		if (this != &p)
//		{
//			_name = p._name;
//		}
//		return *this;
//	}
//	~Person()
//	{
//		cout << "父类析构" << endl;
//	}
//private:
//	string _name;
//};
//
//class Student :public Person
//{
//public:
//	Student(const char* name, int num)
//		:Person(name)
//		, _ID(num)
//	{
//		cout << "子类构造" << endl;
//	}
//	Student(const Student& s)
//		:Person(s)
//		, _ID(s._ID)
//	{
//		cout << "子类拷贝构造" << endl;
//	}
//	Student& operator=(const Student& s)
//	{
//		cout << "子类复制重载" << endl;
//		if (this != &s)
//		{
//			Person::operator=(s);//调用基类的赋值(其底层会发生切片赋值)
//			_ID = s._ID;
//		}
//		return *this;
//	}
//	~Student()
//	{
//		cout << "子类析构" << endl;
//	}
//private:
//	int _ID;
//};
//
//int main()
//{
//  //如果没有显示调用基类的构造函数，则编译器自动调用，就会导致，
//  //构造的对象与实际名字不符合的现象，此处预想名字为tong，而实际生成的名字为txt
//	Student a1("tong", 170);
//
//	Student a2(a1);//拷贝构造
//	Student a3 = a1;//赋值
//	return 0;
//}

//友元函数不可被继承
//class B;
//class A
//{
//public:
//	friend void func(const A& a, const B& b);
//protected:
//	int _age;
//};
//class B :public A
//{
//public:
//	int _ID;
//};
//void func(const A& a,const B& b)
//{
//	cout << a._age << endl;
//	cout << b._ID << endl;
//}
//
//int main()
//{
//	A a;
//	B b;
//	func(a, b);
//	return 0;
//}

//继承的stctic成员
//class A
//{
//public:
//	A(){ ++_count;}
//public:
//	static int _count;
//};
//int A::_count = 0;
//class B:public A
//{
//protected:
//	int _b;
//};
//class C :public A
//{
//protected:
//	int _c;
//};
//void main()
//{
//	A a;
//	B b;//会先调用基类的构造函数，因此_count会加一次
//	C c;//同上
//	cout << " _count:" << A:: _count << endl;//输出：3
//	A::_count = 0;
//	cout << " _count:" << A::_count << endl;//输出：1
//}

//多态练习
//class A
//{
//public:
//	virtual void func()
//	{
//		cout << "基类虚函数" << endl;
//	}
//};
//class B : public A
//{
//public :
//	virtual void func()
//	{
//		cout << "子类虚函数" << endl;
//	}
//};
//void test(A& a)//引用的调用
//{
//	a.func();
//}
//void main()
//{
//	A a;
//	B b;
//	test(a);
//	test(b);
//}

//协变,返回类型为基类指针和派生类指针
//class A{};
//class B :public A{};
//
//class X{
//public:
//	virtual A* f(){
//		return new A;
//	}
//};
//class Y :public X{
//public:
//	virtual B* f(){
//		return new B;
//	}
//};

////不规范的重写
//class A{
//public:
//	virtual void f(){}
//};
//
//class B :public A{
//public:
//	void f(){}//没有写virtual关键字
//};

//析构函数重写问题
//class Person {
//public:
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//	//virtual ~Student() { cout << "~Student()" << endl; }//不重写 不满足多态
//	virtual ~Student() { cout << "~Student()" << endl; }//重写 满足多态
//};
//// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函数，才能构成多
////态，才能保证p1和p2指向的对象正确的调用析构函数。
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//
//	delete p1;
//	delete p2;
//
//	return 0;
//}


//接口函数练习
//class A
//{
//public:
//	virtual void func(int val = 1)
//	{
//		cout << "A:" << val << endl;
//	}
//	virtual void test()
//	{
//		func();
//	}
//};
//class B :public A
//{
//public:
//	virtual void func(int val = 0)//接口继承//因此此处的缺省参数会使用基类的
//	{
//		cout << "B:" << val << endl;
//	}
//};
//void main()
//{
//	A* b = new B;//构成多态，指向的是B，因此调用的为B的函数
//
//	(*b).func();
//}

//抽象类
//class A
//{
//public:
//	virtual void f() = 0;
//};
//class B :public A
//{
//public:
//	//如果不重写，B就不可以实例化出对象
//	virtual void f(){
//		cout << "我重写了" << endl;
//	}
//};
//void main()
//{
//	B b;
//	b.f();
//}

//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-操控" << endl;
//	}
//};
//void main()
//{
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//	Car* pBMW = new BMW;
//	pBMW->Drive();
//}

//override和final关键字
//class A
//{
//public:
//	virtual void f()final
//	{}
//};
//class B :public A
//{
//public:
//	virtual void f()
//	{
//		cout << "语法有误，不能被重写" << endl;
//	}
//};

//class A
//{
//public:
//	virtual void f(int a){}
//};
//class B :public A
//{
//public:
//	virtual void f(int b)override{}
//};
//void main()
//{
//	B b;
//	b.f(1);
//}

//class A{
//public:
//	virtual void F(){}
//private:
//	int _b;
//};
//void main(){
//	cout << sizeof(A) << endl;//8
//}

//异常
//double Division(int a, int b) {
//	// 当b == 0时抛出异常
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//void Func()
//{
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl;
//}
//int main()
//{
//	try {
//		Func();
//	}
//	catch (const char* errmsg){
//		cout << errmsg << endl;
//	}
//		catch (...){
//		cout << "unkown exception" << endl;
//	}
//	return 0;
//}

double Division(int a, int b) {
	// 当b == 0时抛出异常
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}
void Func()
{
	// 这里可以看到如果发生除0错误抛出异常，另外下面的array没有得到释放。
	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再
	// 重新抛出去。
	int* array = new int[10];
	try {
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...)
	{
		cout << "delete []" << array << endl;
		delete[] array;
		throw;
	}
	// ...
	cout << "delete []" << array << endl;
		delete[] array;
}
int main()
{
	try
	{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	return 0;
}