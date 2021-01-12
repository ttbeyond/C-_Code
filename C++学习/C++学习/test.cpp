#include"test.h"


//using namespace std;
//
//int main()
//{
//	cout << "hello world" << endl;
//	printf("hello world\n");
//
//	system("pause");
//}

//namespace N1
//{
//	int a = 0;
//	int ADD(int a, int b)
//	{
//		return a + b;
//	}
//}
//int main()
//{
//	int a = 5, b = 6;
//	//cout << a << endl;
//	printf("%d\n", a);      //5
//	printf("%d\n", N1::a);  //0
//	printf("%d\n", N1::ADD);//没有传参，达不到预期效果
//	printf("%d\n", N1::ADD(a,b));//11
//
//	system("pause");
//}

//namespace N2
//{
//	int dd = 9;
//	namespace N
//	{
//		int sub(int a, int b)
//		{
//			return a - b;
//		}
//	}
//}
//namespace N1
//{
//	//int a = 9;//相同命名空间中的变量名不可冲突，否则会导致重定义
//	int MUL(int a, int b)
//	{
//		return a * b;
//	}
//}
//int main()
//{
//	int a = 5, b = 9;
//	printf("%d\n", N2::dd);//9
//	printf("%d\n", N2::N::sub(a,b));//-4
//	printf("%d\n", N1::ADD(a, b));//14
//	printf("%d\n", N1::MUL(a, b));//45
//
//
//	system("pause");
//}

//namespace N
//{
//	int a = 8;
//	int ADD(int a, int b){
//		return a + b;
//	}
//	int Sub(int a, int b)
//	{
//		return a - b;
//	}
//}
//using N::a;       //用谁放谁
//using namespace N;//全放
//int main()
//{
//	int ret = ADD(3, 4);
//	printf("%d\n", N::a);//8
//	printf("%d\n", a);   //8
//
//	printf("%d\n", ret);//7
//	system("pause");
//	return 0;
//}
//
//using namespace std;
//int main()
//{
//	int a;
//	double b;
//	cin >> a;
//	cin >> b;
//	cout << a + b << endl;
//	system("pause");
//	return 0;
//}


//using namespace std;
//void Fun(int a = 4)
//{
//	cout << a << endl;
//}
//int main()
//{
//	Fun() ;//4//缺省传参
//	Fun(3);//3
//
//	system("pause");
//	return 0;
//}

//using namespace std;
//void test1(int a = 1, int b = 2, int c = 3)//全缺省
//{
//	//a = 2;
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//
//}
//void test2(int a , int b = 4, int c = 5)//半缺省
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//
//}
//int main()
//{
//	test1();//1,2,3
//	test2(6);//6,4,5
//	system("pause");
//	return 0;
//}

//重载
//using namespace std;
//int Add(int left, int right) {
//	return left + right;
//}
//double Add(double left, double right) {
//	return left + right;
//}
//long Add(long left, long right) {
//	return left + right;
//}
//int main()
//{
//	cout<<Add(10, 20)<<endl;
//	cout<<Add(10.1, 20.4)<<endl;
//	cout<<Add(10L, 20L)<<endl;
//	system("pause");
//	return 0;
//}


//引用
//int main()
//{
//	int a = 9;
//	int& aa = a;//引用类型& 变量名 = 引用实体
//	int& aaa = a;//一个变量可有多个引用
//	//int& aaaa;//引用必须初始化
//
//	printf("%p\n", &a);
//	printf("%p\n", &aa);
//	printf("%p\n", &aaa);
//
//	system("pause");
//	return 0;
//}

//using namespace std;
//int Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//int& Swap1(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//int& Swap2(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}

//int& Add(int a, int b) {
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl;//输出：7
////原因：：如果函数返回时，离开函数作用域后，其栈上空间已经还给系统，因此不能用栈上的空间作为引用类型返回。如果以引用类型返回，返回值的生命周期必须不受函数的限制(即比函数生命周期长)。
//	system("pause");
//	return 0;
//}


//auto关键字
//int TestAuto()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = TestAuto();
//	auto f = 10;
//		
//	cout << typeid(b).name() << endl;//int  //输出变量类型名称
//	cout << typeid(c).name() << endl;//char
//	cout << typeid(d).name() << endl;//int
//	cout << typeid(f).name() << endl;//int
//
//	//auto e; 无法通过编译，使用auto定义变量时必须对其进行初始化
//	system("pause");
//	return 0;
//}

//范围for
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6 };
//	for (auto tmp : arr)
//		cout << tmp << " ";
//	cout << endl;
//	for (auto& tmp : arr)
//		cout << tmp << " ";
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6 };
//	for (int i = 0; i < 6; ++i)
//	{
//		arr[i] *= 2;
//	}
//	//预期打印：2 4 6 8 10 12
//	for (int i = 0; i < 6; ++i)
//	{
//		cout << arr[i] << ' ';
//	}
//	cout << endl;
//	for (auto &tmp : arr)//若此处为auto tmp:arr,则以下预期达不到，实际打印：2 4 6 8 10；原因：tmp的改变不会引起arr的改变；解决：引用取别名让tmp成为arr的别名
//	{
//		tmp *= 2;
//	}
//	//预期打印：4 8 12 16 20 24
//	for (auto tmp : arr)
//		cout << tmp << " ";
//	cout << endl;
//
//	system("pause");
//	return 0;
//}



//struct student
//{
//	void SetStudentInfo(const char* name, const char* gender, const int age)
//	{
//		strcpy(_name, name);
//		strcpy(_gender,gender);
//		_age = age;
//	}
//	void Print()
//	{
//		cout << _name << ' ' << _gender << ' ' << _age << endl;
//	}
//
//	char _name[20];
//	char _gender[20];
//	int _age;
//};
//
//int main()
//{
//	student first;
//	first.SetStudentInfo("张三", "男", 18);
//	first.Print();
//	system("pause");
//	return 0;
//}

//void Person::ShowInfo(const char* name, const char* gender, const int age)
//{
//	strcpy(_name, name);
//	strcpy(_gender, gender);
//	_age = age;
//}
//void Person::Print()
//{
//	cout << _name << ' ' << _gender << ' ' << _age << endl;
//}
//int main()
//{
//	Person first;
//	//计算大小时：只计算类中成员变量的大小即可
//	cout << sizeof(first) << endl;
//	first.ShowInfo("李四", "男", 18);
//	first.Print();
//	system("pause");
//	return 0;
//}

//class A1 {
//public:
//	void f1(){}
//private:
//	int _a;
//};
//// 类中仅有成员函数
//class A2 {
//public:
//	void f2() {}
//};
//// 类中什么都没有---空类
//class A3
//{};
//int main()
//{
//	cout << sizeof(A1) << sizeof(A2) << sizeof(A3) << endl;  
//	system("pause");
//	return 0;
//}

//class Date
//{
//public:
//	// 如果用户显式定义了构造函数，编译器将不再生成
//	//实现一个全缺省的默认构造函数
//	Date (int year = 2020, int month = 10, int day = 12)
//	{
//	_year = year;
//	_month = month;
//	_day = day;
//	}
//	//实现无参数的默认构造函数
//	//Date()
//	//{
//	//	_year = 2012;
//	//	_month = 10;
//	//	_day = 12;
//	//}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int  main()
//{
//	// 没有定义构造函数，对象也可以创建成功，因此此处调用的是编译器生成的默认构造函数
//	
//	//Date d(2020, 10, 12);
//	//没有写构造函数的情况，编译器自动生成
//	//Date d;
//	//实现全缺省的构造函数，参数可以想传几个传几个(在范围之内)，但必须时从左向右依次传参
//	Date d(2019);
//
//		system("pause");
//		return 0;
//}
//

//class String
//{
//public:
//	String(const char* str = "小曹")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		cout << "~String()我被调用了" << endl;
//		free(_str);
//	}
//private:
//	char* _str;
//};
//class Person
//{
//public:
//	String _name;
//	int _age;
//};
//int main()
//{
//	Person p;
//	system("pause");
//	return 0;
//}

////拷贝构造
//class Data
//{
//public:
//	Data(int year = 2020, int month = 10, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//拷贝构造函数
//	//在这里如果参数给Data d会造成无穷递归的拷贝构造
//	//原因Data d相当于又创建一个Data类型，然后又会调用一个新的拷贝Data (Data d),就这样无限循环
//	//改进：引用传参，让变量变为d的别名
//	//优化：在前边再加上const，让其权限缩小为只读，以防止写失误的情况
//	Data(Data& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		//d._day=_day;//错将变量的值赋给d
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Data d;
//	//调用拷贝构造函数让d1的值等于d
//	//拷贝构造的俩种调用方法
//	Data d1(d);
//	Data d2 = d;
//
//
//	system("pause");
//	return 0;
//}

////class Date
////{
////public:
////	Date(int year = 1900, int month = 1, int day = 1)
////	{
////		_year = year;
////		_month = month;
////		_day = day;
////	}
////
////	// bool operator==(Date* this, const Date& d2)
////	// 这里需要注意的是，左操作数是this指向的调用函数的对象
////	bool operator==(const Date& d2)
////	{
////		return _year == d2._year
////			&& _month == d2._month
////			&& _day == d2._day;
////	}
	//比较俩个日期的大小 
	//代码一，比较垃圾
	//bool operator>(const Date& d2)
	//{
	//	if (_year == d2._year&& _month == d2._month&& _day == d2._day)
	//		return false;
	//	if (_year > d2._year)
	//		return true;
	//	else
	//	{
	//		if (_year == d2._year)
	//		{
	//			if (_month > d2._month)
	//				return true;
	//			else
	//			{
	//				if (_month == d2._month)
	//				{
	//					if (_day > d2._day)
	//						return true;
	//					else
	//						return false;
	//				}
	//			}
	//		}
	//		return false;
	//	}
	//}
//	//代码二
////	bool operator>(const Date& d2)
////	{
////		if (_year > d2._year)
////			return true;
////		else if (_year == d2._year && _month > d2._month)
////			return true;
////		else if (_year == d2._year && _month == d2._day && _day > d2._day)
////			return true;
////
////		return false;
////	}
////private:
////	int _year;
////	int _month;
////	int _day;
////};
////void Test()
////{
////	Date d1(2018, 9, 27);
////	Date d2(2018, 9, 27);
////	cout << (d1 == d2) << endl;//不相等，返回0
////	//Date d1(2018, 9, 28);
////	//Date d2(2018, 9, 27);
////	//cout << (d1 > d2) << endl;//小于返回0，大于返回1
////}
////int main()
////{
////	Test();
////	system("pause");
////	return 0;
////}

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	Date d2(2018,10, 1);
//
//	// 这里d1调用的编译器生成operator=完成拷贝，d2和d1的值也是一样的。
//	d1 = d2;
//	//cout << d1 << endl;
//	system("pause");
//		return 0;
//}

//class String
//{
//public:
//	String(const char* str = "jack")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		cout << "~String()" << endl;
//			free(_str);
//	}
//private:
//	char* _str;
//};
//int main()
//{
//	String s1("hello");
//	String s2("world");
//	//浅拷贝析构函数同一块空间释放俩次所带来的问题
//	s1 = s2;//完成了赋值运算符重载，但程序在运行结束时崩溃
//
//	system("pause");
//	return 0;
//}

//class Data
//{
//public:
//	//Data(int year = 1900, int month = 1,int day=1)
//	Data(int year , int month , int day )
//		:_year(year),
//		_month(month),
//		_day(day)
//	{
//		//_year = year;
//		//_month = month;
//		//_day = day;
//	}
//	void Printf()
//	{
//		cout << _year << '-' << _month << '-' << _day << endl;
//	}
//private:
//		int _year;
//		int _month;
//		int _day;
//};
//
//int main()
//{
//	//Data d;
//	//d.Printf();
//
//	Data d1(2020,10,15);
//	d1.Printf();
//
//	Data d = d1;//拷贝构造
//	d.Printf();
//
//	system("pause");
//	return 0;
//}

//class A {
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//class B {
//public:
//	//可以将初始化列表理解为：对象成员变量定义的地方
//	B(int a, int ref)
//		:_aobj(a)
//		, _ref(ref)
//		, _n(10)
//	{}
//private:
//	//成员变量声明
//	A _aobj; // 没有默认构造函数
//	int& _ref; // 引用
//	const int _n; // const 
//};
//int main()
//{
//	B b(1,2);
//
//	system("pause");
//	return 0;
//}

//class Data
//{
//public:
//	Data(int a, int b)
//		:_b(b),
//		_a(b)
//	{
//		cout << _a << '-' << _b << endl;
//
//	}
//private:
//	int _a;
//	int _b;
//};
//int main()
//{
//	Data a(1,2);
//	//cout << a._a << '-' << a._b << endl;
//
//	system("pause");
//	return 0;
//}

//class Sum{
//public:
//	Sum(){
//		_sum += _i;
//		++_i;
//	}
//	static int Getsum(){
//		return _sum;
//	}
//	static void Init(){
//		_i = 1;
//		_sum = 0;
//	}
//private:
//	static int _i;
//	static int _sum;
//};
//int Sum::_sum = 0;
//int Sum::_i = 1;
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//Sum arr[n];
//		Sum::Init();
//		Sum* p = new Sum[n];
//		return Sum::Getsum();
//	}
//};
//int main()
//{
//	Solution st;
//	cout << st.Sum_Solution(5) << endl;
//	cout << st.Sum_Solution(5) << endl;
//
//	system("pause");
//	return 0;
//}

//class Data
//{
//public:
//	explicit Data(int year)
//		:_year(1)
//	{
//	}
//private:
//	int _year;
//};
//int main()
//{
//	//const Data& d = 2;//含有隐式类型转换
//	Data d1(2);
//	//Data d2 = 3;//同上
//
//	return 0;
//}


//重载<<与>>俩个输出输入流函数符号
//class Data
//{
//public:
//	Data(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	friend ostream& operator<<(ostream& _cout, const Data& d);
//	friend istream& operator>>(istream& _cin, Data& d);
//
//	//ostream& operator<<(ostream& _cout)
//	//{
//	//	_cout << _year << "-" << _month << "-" << _day;
//	//	return _cout;
//	//}
//private:
//	int _year = 0;
//	int _month = 1;
//	int _day = 1;
//};
//ostream& operator<<(ostream& _cout,const Data& d)//有返回值是为了支持连续输出
//{
//	_cout << d._year << "-" << d._month << "-" << d._day << endl;
//	return _cout;
//}
//istream& operator>>(istream& _cin, Data& d)
//{
//	_cin >> d._year >> d._month >> d._day ;
//	return _cin;
//}
//int main()
//{
//	//验证重载正确的测试
//	//Data d(2017, 12, 24);
//	////d << cout;//没改之前
//	//cout << d;//改为友元函数之后的调用
//	//system("pause");
//
//	//支持连续输出后的测试
//	//Data d1(2020, 10, 15);
//	//Data d2(2020, 10, 16);
//
//	//cout << d1 << d2;//先输出d1，然后得到返回值后，再用cout函数的返回值调用cout函数来输出d2
//	//system("pause");
//
//	//输入与输出合并测试
//	Data d(2020, 10, 16);
//	cin >> d;
//	cout << d;
//	system("pause");
//
//	return 0;
//}

//class Data
//{
//	class Time
//	{
//	public:
//	private:
//		int hour;
//	};
//public:
//private:
//	int  year;
//	Time T;
//
//};
//
//int main()
//{
//	cout << sizeof(Data) << endl;//8
//
//	system("pause");
//	return 0;
//}

class Data
{
public:
	int GetMonthDay(int year, int month)
	{
		int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			arr[2] = 29;
		}
		return arr[month];
	}
	Data(int year, int month, int day)
		:_year(year),
		_month(month),
		_day(day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	bool operator>(const Data& d)
	{
		if (_year>d._year)
			return true;
		else if (_year == d._year&&_month>d._month)
			return true;
		else if (_year == d._year&&_month == d._month && _day>d._day)
			return true;
		return false;
	}
	Data operator++()
	{

		if (_day <= GetMonthDay(_year, _month))//
		{
			_day++;
			if (_day>GetMonthDay(_year, _month))
			{
				_day = 1;
				_month++;
			}
		}

		return *this;
	}
	int getOutDay()
	{
		Data d = *this;
		int tmp = (*this)._year;
		int n = 0;
		Data ret(tmp, 1, 1);
		while (!(ret>d))
		{
			++ret;
			++n;
		}
		return n;
	}
private:
	int _year;
	int _month;
	int _day;
};
int n = 0;
int main()
{
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		Data d(year, month, day);
		cout << d.getOutDay() << endl;
	}
	return 0;
}