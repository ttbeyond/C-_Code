#include<iostream>
using namespace std;

//template<class T>
//bool Isequal( T& x1,  T& x2)
//{
//	cout << "ģ�����" << endl;
//	return x1 == x2;
//}
//template<>
//bool Isequal<char*>( char*& x1, char*& x2)
//{
//	cout << "char*ȫ�ػ�" << endl;
//	if (strcmp(x1, x2) > 0)
//		return true;
//	return false;
//}
//template<>
//bool Isequal<char>(char& x1, char& x2)
//{
//	cout << "char��ȫ�ػ�" << endl;
//	return x1 == x2;
//}
//void test2()
//{
//   char* p1 = "asdf";
//   char* p2 = "zxcv";
//   //char*ȫ�ػ�����
//   if (Isequal(p1, p2))
//	   cout << "���" << endl;
//   else
//	   cout << "�����" << endl;
//
//   //ģ�����
//   int a = 3, b = 3;
//   if (Isequal(a, b))
//	   cout << "���" << endl;
//   else
//	   cout << "�����" << endl;
//
//   //charȫ�ػ�����
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

//����ģ��ȫ�ػ�
//template<class T1>
//bool isequal(T1& left, T1& right)
//{
//	cout << "ģ�����" << endl;
//	return left == right;
//}
//template<>
//bool isequal<char*>(char*& left, char*& right)
//{
//	cout << "char*ȫ�ػ�" << endl;
//		if (strcmp(left, right) > 0)
//			return true;
//		return false;
//}
//template<>
//bool isequal<int>(int& left, int& right)
//{
//	cout << "intȫ�ػ�" << endl;
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

//��ģ���ȫ�ػ���ƫ�ػ�
//template<typename T1,typename T2>
//class txt
//{
//public:
//	txt()
//	{
//		cout << "��ģ�����" << endl;
//	}
//private:
//	T1 _x1;
//	T2 _x2;
//	
//};
//
////��ģ��ȫ�ػ�
//template<>
//class txt<int, char>
//{
//public:
//	txt()
//	{
//		cout << "int��char��ȫ�ػ�����" << endl;
//	}
//private:
//	char _x1;
//	char _x2;
//};

//��ģ��ƫ�ػ�
//�����ػ�������һ�������ػ�Ϊint
//template<class T1>
//class txt<int, T1>
//{
//public:
//	txt()
//	{
//		cout << "��һ������Ϊint��ƫ�ػ�����" << endl;
//	}
//private:
//	T1 _x1;
//	T1 _x2;
//};
//
////��ģ�������һ�����Ƶ�ƫ�ػ�����
//template<class T1,class T2>
//class txt<T1&,T2&>
//{
//public:
//	txt()
//	{
//		cout << "������ƫ�ػ�Ϊ���õĵ���" << endl;
//	}
//private:
//	T1 _x1;
//	T2 _x2;
//};
//
//int main()
//{
//	txt<int, int> x1;  //��һ������Ϊint��ƫ�ػ�����
//	txt<int, char> x2; //int��char��ȫ�ػ�����
//	txt<char, int> x3; //��ģ�����
//	txt<int&, int&> x4;//������ƫ�ػ�Ϊ���õĵ���
//
//	return 0;
//}

//�̳���ϰ
//#include<string>
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "������" << _name << endl;
//		cout << "���䣺" << _age << endl;
//	}
//private:
//	string _name = "txt";
//	int _age = 23;
//};

////StudentΪ����(Ҳ�ɳ�����������)��PersonΪ����(Ҳ��Ϊ������)
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
//		cout << " ����:" << _name << endl;
//		cout << " ���֤��:" << Person::_num << endl;
//		cout << " ѧ��:" << _num << endl;
//	}
//protected:
//	string _name = "С����"; // ����
//	int _num = 111; // ���֤��
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		cout << " ���֤��:" << Person::_num << endl;
//		cout << " ѧ��:" << _num << endl;
//	}
//protected:
//	int _num = 999; // ѧ��
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
////���ּ̳з�ʽ����̳л���ĳ�Ա���������ڷ���Ȩ��
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
//	//first = one;//���벻��
//	Person* second = &first;
//	Person &third = first;
//
//	//�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
//	Person* p = &first;
//	Student *pp = (Student*)p;
//
//	return 0;
//}

//�Ĵ�Ĭ�Ϻ�������˳��
//#include<string>
//class Person
//{
//public:
//	Person(const char* name="txt")
//		:_name(name)
//	{
//		cout << "���๹��" << endl;
//	}
//	Person(const Person& name)
//		:_name(name._name)
//	{
//		cout << "���࿽������" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		cout << "���ำֵ����" << endl;
//		if (this != &p)
//		{
//			_name = p._name;
//		}
//		return *this;
//	}
//	~Person()
//	{
//		cout << "��������" << endl;
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
//		cout << "���๹��" << endl;
//	}
//	Student(const Student& s)
//		:Person(s)
//		, _ID(s._ID)
//	{
//		cout << "���࿽������" << endl;
//	}
//	Student& operator=(const Student& s)
//	{
//		cout << "���ิ������" << endl;
//		if (this != &s)
//		{
//			Person::operator=(s);//���û���ĸ�ֵ(��ײ�ᷢ����Ƭ��ֵ)
//			_ID = s._ID;
//		}
//		return *this;
//	}
//	~Student()
//	{
//		cout << "��������" << endl;
//	}
//private:
//	int _ID;
//};
//
//int main()
//{
//  //���û����ʾ���û���Ĺ��캯������������Զ����ã��ͻᵼ�£�
//  //����Ķ�����ʵ�����ֲ����ϵ����󣬴˴�Ԥ������Ϊtong����ʵ�����ɵ�����Ϊtxt
//	Student a1("tong", 170);
//
//	Student a2(a1);//��������
//	Student a3 = a1;//��ֵ
//	return 0;
//}

//��Ԫ�������ɱ��̳�
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

//�̳е�stctic��Ա
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
//	B b;//���ȵ��û���Ĺ��캯�������_count���һ��
//	C c;//ͬ��
//	cout << " _count:" << A:: _count << endl;//�����3
//	A::_count = 0;
//	cout << " _count:" << A::_count << endl;//�����1
//}

//��̬��ϰ
//class A
//{
//public:
//	virtual void func()
//	{
//		cout << "�����麯��" << endl;
//	}
//};
//class B : public A
//{
//public :
//	virtual void func()
//	{
//		cout << "�����麯��" << endl;
//	}
//};
//void test(A& a)//���õĵ���
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

//Э��,��������Ϊ����ָ���������ָ��
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

////���淶����д
//class A{
//public:
//	virtual void f(){}
//};
//
//class B :public A{
//public:
//	void f(){}//û��дvirtual�ؼ���
//};

//����������д����
//class Person {
//public:
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//	//virtual ~Student() { cout << "~Student()" << endl; }//����д �������̬
//	virtual ~Student() { cout << "~Student()" << endl; }//��д �����̬
//};
//// ֻ��������Student������������д��Person�����������������delete��������������������ܹ��ɶ�
////̬�����ܱ�֤p1��p2ָ��Ķ�����ȷ�ĵ�������������
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


//�ӿں�����ϰ
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
//	virtual void func(int val = 0)//�ӿڼ̳�//��˴˴���ȱʡ������ʹ�û����
//	{
//		cout << "B:" << val << endl;
//	}
//};
//void main()
//{
//	A* b = new B;//���ɶ�̬��ָ�����B����˵��õ�ΪB�ĺ���
//
//	(*b).func();
//}

//������
//class A
//{
//public:
//	virtual void f() = 0;
//};
//class B :public A
//{
//public:
//	//�������д��B�Ͳ�����ʵ����������
//	virtual void f(){
//		cout << "����д��" << endl;
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
//		cout << "Benz-����" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-�ٿ�" << endl;
//	}
//};
//void main()
//{
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//	Car* pBMW = new BMW;
//	pBMW->Drive();
//}

//override��final�ؼ���
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
//		cout << "�﷨���󣬲��ܱ���д" << endl;
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

//�쳣
//double Division(int a, int b) {
//	// ��b == 0ʱ�׳��쳣
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
	// ��b == 0ʱ�׳��쳣
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}
void Func()
{
	// ������Կ������������0�����׳��쳣�����������arrayû�еõ��ͷš�
	// �������ﲶ���쳣�󲢲������쳣���쳣���ǽ������洦�����ﲶ������
	// �����׳�ȥ��
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