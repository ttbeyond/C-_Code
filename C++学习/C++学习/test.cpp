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
//	printf("%d\n", N1::ADD);//û�д��Σ��ﲻ��Ԥ��Ч��
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
//	//int a = 9;//��ͬ�����ռ��еı��������ɳ�ͻ������ᵼ���ض���
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
//using N::a;       //��˭��˭
//using namespace N;//ȫ��
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
//	Fun() ;//4//ȱʡ����
//	Fun(3);//3
//
//	system("pause");
//	return 0;
//}

//using namespace std;
//void test1(int a = 1, int b = 2, int c = 3)//ȫȱʡ
//{
//	//a = 2;
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//
//}
//void test2(int a , int b = 4, int c = 5)//��ȱʡ
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

//����
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


//����
//int main()
//{
//	int a = 9;
//	int& aa = a;//��������& ������ = ����ʵ��
//	int& aaa = a;//һ���������ж������
//	//int& aaaa;//���ñ����ʼ��
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
//	cout << "Add(1, 2) is :" << ret << endl;//�����7
////ԭ�򣺣������������ʱ���뿪�������������ջ�Ͽռ��Ѿ�����ϵͳ����˲�����ջ�ϵĿռ���Ϊ�������ͷ��ء�������������ͷ��أ�����ֵ���������ڱ��벻�ܺ���������(���Ⱥ����������ڳ�)��
//	system("pause");
//	return 0;
//}


//auto�ؼ���
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
//	cout << typeid(b).name() << endl;//int  //���������������
//	cout << typeid(c).name() << endl;//char
//	cout << typeid(d).name() << endl;//int
//	cout << typeid(f).name() << endl;//int
//
//	//auto e; �޷�ͨ�����룬ʹ��auto�������ʱ���������г�ʼ��
//	system("pause");
//	return 0;
//}

//��Χfor
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
//	//Ԥ�ڴ�ӡ��2 4 6 8 10 12
//	for (int i = 0; i < 6; ++i)
//	{
//		cout << arr[i] << ' ';
//	}
//	cout << endl;
//	for (auto &tmp : arr)//���˴�Ϊauto tmp:arr,������Ԥ�ڴﲻ����ʵ�ʴ�ӡ��2 4 6 8 10��ԭ��tmp�ĸı䲻������arr�ĸı䣻���������ȡ������tmp��Ϊarr�ı���
//	{
//		tmp *= 2;
//	}
//	//Ԥ�ڴ�ӡ��4 8 12 16 20 24
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
//	first.SetStudentInfo("����", "��", 18);
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
//	//�����Сʱ��ֻ�������г�Ա�����Ĵ�С����
//	cout << sizeof(first) << endl;
//	first.ShowInfo("����", "��", 18);
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
//// ���н��г�Ա����
//class A2 {
//public:
//	void f2() {}
//};
//// ����ʲô��û��---����
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
//	// ����û���ʽ�����˹��캯��������������������
//	//ʵ��һ��ȫȱʡ��Ĭ�Ϲ��캯��
//	Date (int year = 2020, int month = 10, int day = 12)
//	{
//	_year = year;
//	_month = month;
//	_day = day;
//	}
//	//ʵ���޲�����Ĭ�Ϲ��캯��
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
//	// û�ж��幹�캯��������Ҳ���Դ����ɹ�����˴˴����õ��Ǳ��������ɵ�Ĭ�Ϲ��캯��
//	
//	//Date d(2020, 10, 12);
//	//û��д���캯����������������Զ�����
//	//Date d;
//	//ʵ��ȫȱʡ�Ĺ��캯�������������봫����������(�ڷ�Χ֮��)��������ʱ�����������δ���
//	Date d(2019);
//
//		system("pause");
//		return 0;
//}
//

//class String
//{
//public:
//	String(const char* str = "С��")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		cout << "~String()�ұ�������" << endl;
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

////��������
//class Data
//{
//public:
//	Data(int year = 2020, int month = 10, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//�������캯��
//	//���������������Data d���������ݹ�Ŀ�������
//	//ԭ��Data d�൱���ִ���һ��Data���ͣ�Ȼ���ֻ����һ���µĿ���Data (Data d),����������ѭ��
//	//�Ľ������ô��Σ��ñ�����Ϊd�ı���
//	//�Ż�����ǰ���ټ���const������Ȩ����СΪֻ�����Է�ֹдʧ������
//	Data(Data& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		//d._day=_day;//��������ֵ����d
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
//	//���ÿ������캯����d1��ֵ����d
//	//������������ֵ��÷���
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
////	// ������Ҫע����ǣ����������thisָ��ĵ��ú����Ķ���
////	bool operator==(const Date& d2)
////	{
////		return _year == d2._year
////			&& _month == d2._month
////			&& _day == d2._day;
////	}
	//�Ƚ��������ڵĴ�С 
	//����һ���Ƚ�����
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
//	//�����
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
////	cout << (d1 == d2) << endl;//����ȣ�����0
////	//Date d1(2018, 9, 28);
////	//Date d2(2018, 9, 27);
////	//cout << (d1 > d2) << endl;//С�ڷ���0�����ڷ���1
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
//	// ����d1���õı���������operator=��ɿ�����d2��d1��ֵҲ��һ���ġ�
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
//	//ǳ������������ͬһ��ռ��ͷ�����������������
//	s1 = s2;//����˸�ֵ��������أ������������н���ʱ����
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
//	Data d = d1;//��������
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
//	//���Խ���ʼ���б����Ϊ�������Ա��������ĵط�
//	B(int a, int ref)
//		:_aobj(a)
//		, _ref(ref)
//		, _n(10)
//	{}
//private:
//	//��Ա��������
//	A _aobj; // û��Ĭ�Ϲ��캯��
//	int& _ref; // ����
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
//	//const Data& d = 2;//������ʽ����ת��
//	Data d1(2);
//	//Data d2 = 3;//ͬ��
//
//	return 0;
//}


//����<<��>>���������������������
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
//ostream& operator<<(ostream& _cout,const Data& d)//�з���ֵ��Ϊ��֧���������
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
//	//��֤������ȷ�Ĳ���
//	//Data d(2017, 12, 24);
//	////d << cout;//û��֮ǰ
//	//cout << d;//��Ϊ��Ԫ����֮��ĵ���
//	//system("pause");
//
//	//֧�����������Ĳ���
//	//Data d1(2020, 10, 15);
//	//Data d2(2020, 10, 16);
//
//	//cout << d1 << d2;//�����d1��Ȼ��õ�����ֵ������cout�����ķ���ֵ����cout���������d2
//	//system("pause");
//
//	//����������ϲ�����
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