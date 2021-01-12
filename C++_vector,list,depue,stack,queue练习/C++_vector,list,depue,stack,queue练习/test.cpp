//#include<iostream>
//#include<vector>
//
//using namespace std;

//void Print(const vector<int>& n)
//{
//	//正向const迭代器
//	vector<int>::const_iterator it = n.begin();
//	while (it != n.end())
//	{
//		cout << *it << ' ';
//		++it;
//	}
//	cout << endl;
//}
//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	//迭代器，正向遍历
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << ' ';
//		it++;
//	}
//	cout << endl;
//	
//	//使用迭代器修改数据
//	it = v.begin();//注意此处要更新it
//	while (it != v.end())
//	{
//		*it *= 2;
//		cout << *it << ' ';
//		it++;
//	}
//	cout << endl;
//
//	//使用迭代器逆向遍历并且打印
//	vector<int>::reverse_iterator rit = v.rbegin();
//	while (rit != v.rend())
//	{
//		cout << *rit << ' ';
//		++rit;
//	}
//	cout << endl;
//
//	Print(v);
//
//	return 0;
//}

////验证vactor的capaccity增长规律
////注意：在VS下使用PJ版STL，按1.5倍增长；在g++下使用SGI版STL，按2倍增长
//int main()
//{
//	size_t n = 0;
//	vector<int> arr;
//	n = arr.capacity();
//	cout << "making arr growing" << endl;
//	for (int i = 0; i < 100; ++i)
//	{
//		arr.push_back(i);
//		if (n != arr.capacity())
//		{
//			n = arr.capacity();//更新n
//            cout << "capacity was changed:" << n << endl;
//		}
//			
//	}
//	return 0;
//}

////使用resreve的效果与不实用的对比
//int main()
//{
//	//不使用
//	size_t n = 0;
//	vector<int> arr;
//	n = arr.capacity();
//	cout << "making arr growing" << endl;
//	for (int i = 0; i < 100; ++i)
//	{
//		arr.push_back(i);
//		if (n != arr.capacity())
//		{
//			n = arr.capacity();//更新n
//			cout << "capacity was changed:" << n << endl;
//		}
//
//	}
//	cout << endl;
//	cout << endl;
//	cout << endl;
//
//	//使用
//	//省去了很多增容带来的开销
//	size_t len = 0;
//	vector<int> arr1;
//	len = arr1.capacity();
//	arr1.reserve(100);
//	cout << "making arr growing" << endl;
//	for (int i = 0; i < 100; ++i)
//	{
//		arr1.push_back(i);
//		if (len != arr1.capacity())
//		{
//			len = arr1.capacity();
//			cout << " capacity was changed :" << len << endl;
//		}
//	}
//	return 0;
//}

////resize(n,x) 设置有效字符个数为n，空出的用x填充，不给默认用0填充
//int main()
//{
//	std::vector<int> myvector;
//	for (int i = 1; i<10; i++)
//		myvector.push_back(i);
//
//	myvector.resize(5);
//	for (int i = 0; i<myvector.size(); i++)
//		cout << ' ' << myvector[i];//1 2 3 4 5
//	cout << endl;
//
//	myvector.resize(8, 100);
//	for (int i = 0; i<myvector.size(); i++)
//		cout << ' ' << myvector[i];//1 2 3 4 5 100 100 100
//	cout << endl;
//
//	myvector.resize(12);
//	for (int i = 0; i<myvector.size(); i++)
//		cout << ' ' << myvector[i];//1 2 3 4 5 100 100 100 0 0 0 0
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5 };
//	vector<int> v(arr, arr+sizeof(arr) / sizeof(int));
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << ' ';
//		++it;
//	}
//	cout << endl;
//
//	v.pop_back();//尾删
//	v.pop_back();
//
//	it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << ' ';//1 2 3
//		++it;
//	}
//	cout << endl;
//
//	v.push_back(5);//尾插
//	v.push_back(5);
//
//	it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << ' ';//1 2 3
//		++it;
//	}
//	cout << endl;
//	return 0;
//}

////insert,erase,find 在vector的使用
//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5, 6 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//
//	//注意：find函数不是vector的接口函数，使用方法为：find(起始位置，结束位置，所需寻找的元素);
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//	while (pos != v.end())
//	{
//		cout << *pos << ' ';//3 4 5 6
//		++pos;
//	}
//	cout << endl;
//
//	//删除pos位置处的元素
//	pos = find(v.begin(), v.end(), 3);//找到3所在的位置
//	v.erase(pos);//删除
//
//	pos = v.begin();
//	while (pos != v.end())
//	{
//		cout << *pos << ' ';//1 2 4 5 6
//		++pos;
//	}
//	cout << endl;
//
//	//在pos位置处插入数据
//	pos = find(v.begin(), v.end(), 4);
//	v.insert(pos , 30);//插入30
//
//	pos = v.begin();
//	while (pos != v.end())
//	{
//		cout << *pos << ' ';//1 2 30 4 5 6
//		++pos;
//	}
//	cout << endl;
//	return 0;
//}

////vector的三种遍历形式
//int main()
//{
//	char str[] = "asdf";
//	vector<char> v(str, str + sizeof(str));
//
//	//[],以数组形式遍历
//	for (int i = 0; i < v.size(); ++i)
//	{
//		cout << v[i] << ' ';
//	}
//	cout << endl;
//
//	//swap的使用：交换俩个容器里边的数据
//	vector<char> ch;
//	ch.swap(v);//等价于ch.swap(ch,v),但是由于又this指针的缘故，把ch省略了
//
//	//使用迭代器打印交换之后的结果
//	cout << "ch的数据";
//	vector<char>::iterator it = ch.begin();
//	while (it != ch.end())
//	{
//		cout << *it << ' ';
//		++it;
//	}
//	cout << endl;
//
//	cout << "v的数据：";
//	it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << ' ';
//	}
//	cout <<"v的大小："<< v.size() << endl;
//
//	//范围for遍历
//	for (auto a : ch)
//	{
//		cout << a << ' ';
//	}
//	cout << endl;
//	return 0;
//}

////增容导致迭代器失效问题
////insert,erase，push_back等导致pos位置迭代器失效问题
////insert在不需用原数组增容的情况下，迭代器不会失效，一但需要增容便会失效
////而erase的使用会直接导致pos位置处迭代器失效
//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//
//	v.erase(pos);
//	cout << *pos << endl;//程序崩掉
//
//	pos = find(v.begin(), v.end(), 4);
//
//	v.insert(pos, 33);
//	cout << *pos << endl;//这俩句程序正常
//
//	for (int i = 100; i > 0; --i)//程序崩掉
//	{
//       v.insert(pos, 33);
//	}
//	cout << *pos << endl;
//	return 0;
//}

//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5, 6, 7 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	// 实现删除v中的所有偶数
//	// 下面的程序会崩溃掉，如果是偶数，erase导致it失效
//	// 对失效的迭代器进行++it，会导致程序崩溃
//	//vector<int>::iterator it = v.begin();
//	//while (it != v.end())
//	//{
//	//	if (*it % 2 == 0)
//	//		v.erase(it);
//	//	++it;
//	//}
//	// 以上程序要改成下面这样，erase会返回删除位置的下一个位置
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//			it = v.erase(it);
//		else
//		{
//			cout << *it << ' ';
//            ++it;
//		}	
//	}
//	cout << endl;
//	return 0;
//}

//list练习
#include<iostream>
#include<list>

using namespace std;

//int main()
//{
//	list<int> l;        //构造空的list对象
//	list<int> l1(4, 10);//构造list对象中包含4个值为10的元素
//	list<int> l2(l1);   //用l1拷贝构造l2
//	l = l2;             //赋值运算符重载
//
//	for (auto e : l)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//
//	//以数组arr为迭代器区间构造l3
//	int arr[] = { 1, 2, 3, 45, 6 };
//	list<int> l3(arr, arr + sizeof(arr) / sizeof(int));
//	for (auto e : l3)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//
//	list<int> l4(l3.begin(), l3.end());//用l3的[begin(),end() )左闭右开的区间构造处l4
//	for (auto e : l4)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//	return 0;
//}


//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
//	list<int> l(arr, arr + sizeof(arr) / sizeof(int));
//
//	//迭代器正向遍历//可读可写
//	list<int>::iterator it = l.begin();
//	while (it != l.end())
//	{
//		cout << *it << ' ';
//		++it;
//	}
//	cout << endl;
//
//	//迭代器反向遍历//可读可写
//	list<int>::reverse_iterator it1 = l.rbegin();
//	while (it1 != l.rend())
//	{
//		cout << *it1 << ' ';
//		++it1;
//	}
//	cout << endl;
//
//	//const反向迭代器遍历//可读
//	list<int>::const_reverse_iterator cit = l.rbegin();
//	while (cit != l.rend())
//	{
//		cout << *cit << ' ';
//		++cit;
//	}
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
//	list<int> l(arr, arr + sizeof(arr) / sizeof(int));
//	
//	cout << l.size() << endl;//7
//
//	if (l.empty())
//		cout << "list已空"<< endl;
//	else
//	{
//		for (auto e : l)
//			cout << e << ' ';
//		cout << endl;
//	}
//	return 0;
//}


//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
//	list<int> l(arr, arr + sizeof(arr) / sizeof(int));
//
//	for (auto e : l)
//		cout << e << ' ';
//	cout << endl;
//
//	//将头与尾分别改为10，70
//	l.front() = 10;
//	l.back() = 70;
//
//	for (auto e : l)
//		cout << e << ' ';
//	cout << endl;
//
//	//const对象调用front()const
//	const int n = l.front();
//	cout << n << endl;
//
//	return 0;
//}


//list的增删改查
#include<vector>
void Print(list<int>& l)
{
	for (auto e : l)
	{
		cout << e << ' ';
	}
	cout << endl;
}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
//	list<int> l(arr, arr + sizeof(arr) / sizeof(int));
//
//	Print(l);
//
//	//头插和尾插
//	l.push_back(8);
//	l.push_front(0);
//	Print(l);
//	//头删尾删
//	l.pop_back();
//	l.pop_front();
//	Print(l);
//
//	//在pos位置处插入20
//	//注意：pos指向的位置为元素2的位置，一直不变，插入在pos之前，删除在pos之上
//	auto pos = ++l.begin();
//	l.insert(pos, 20);
//	Print(l);
//
//	//在pos位置处插入5个50
//	l.insert(pos, 5, 50);
//	Print(l);
//
//	//在pos位置处插入[v.begin(),v.end() )区间的元素
//	vector<int> v{ 11, 22, 33 };
//	l.insert(pos, v.begin(), v.end());
//	Print(l);
//
//	//删除pos位置处的值
//	l.erase(pos);
//	Print(l);
//
//	//删除一个范围之内的元素
//	l.erase(++l.begin(), --l.end());
//	Print(l);
//	return 0;
//}

//resize()重置有效元素个数，默认用0填充
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
//	list<int> l(arr, arr + sizeof(arr) / sizeof(int));
//
//	Print(l);
//
//	//resize()的使用效果
//	l.resize(10);
//	Print(l);
//
//	//多出元素用30填充
//	l.resize(20,30);
//	Print(l);
//
//	//将有效元素改为5个
//	l.resize(5);
//	Print(l);
//	return 0;
//}

//swap()与clear()的使用
//clear()清空有效元素后，size变为0,但其类似于指针的位置还会被保存，以备要添加数据
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
//	list<int> l1(arr, arr + sizeof(arr) / sizeof(int));
//	Print(l1);
//
//	int a[] = { 7, 6, 5, 4, 3, 2, 1 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	list<int> l2(v.begin(), v.end());
//	Print(l2);
//
//	//交换(相同类型）
//	l1.swap(l2);
//	Print(l1);
//	Print(l2);
//
//	l2.clear();
//	Print(l2);
//	cout << l2.size() << endl;//0
//
//	l2.push_back(1);
//	Print(l2);
//	return 0;
//}

//list的 erase()可能导致迭代器失效
//原因：erase()删除的是pos位置的值，而迭代器的it指向的正是这个值的本身
//也是因此原因，push_back(),不会导致迭代器的失效
//int main()
//{
//	list<int> l1(5, 10);
//	Print(l1);
//
//	//list<int>::iterator it = l1.begin();
//	//while (it != l1.end())
//	//{
//	//	l1.erase(it);
//	//	it++;
//	//}
//
//	list<int>::iterator it = l1.begin();
//	while (it != l1.end())
//	{
//		//erase()返回删除后的那个元素原本的位置
//		it = l1.erase(it);//等同于l1.erase(it++);
//		//it++
//		
//	}
//	return 0;
//}


//deque练习
//#include<iostream>
//#include<deque>
//
//using namespace std;
//
//void Print(const deque<int>& q )
//{
//	for (auto e : q)
//		cout << e << ' ';
//	cout << endl;
//}
////构造
//void test1()
//{
//	//构造空的q1
//	deque<int> q1;
//	//用5个值为10的元素构造q2
//	deque<int> q2(5, 10);
//	//用arr数组构造q3
//	int arr[] = { 1, 2, 3, 4, 5 };
//	deque<int> q3(arr,arr+5);
//	//用q3拷贝构造q4
//	deque<int>q4(q3);
//
//	Print(q1);
//	Print(q2);
//	Print(q3);
//	Print(q4);
//}
//
////迭代器遍历
//void test2()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
//	deque<int> q(arr, arr + sizeof(arr) / sizeof(int));
//
//	//正向遍历//可读可写
//	deque<int>::iterator it = q.begin();
//	while (it != q.end())
//	{
//		cout << *it << ' ';
//		++it;
//	}
//	cout << endl;
//
//	//反向遍历//可读可写
//	deque<int>::reverse_iterator rit = q.rbegin();
//	while (rit != q.rend())
//	{
//		cout << *rit << ' ';
//		++rit;
//	}
//	cout << endl;
//
//	//反向const遍历//只可读
//	deque<int>::const_reverse_iterator c_r_it = q.rbegin();
//	while (c_r_it != q.rend())
//	{
//		cout << *c_r_it << ' ';
//		++c_r_it;
//	}
//	cout << endl;
//
//}
//
////容量操作
//void test3()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
//	deque<int> q(arr, arr + sizeof(arr) / sizeof(int));
//
//	//查看有效元素个数
//	cout << "有效元素有：" << q.size() << endl;
//	Print(q);
//
//	//将有效元素个数改为15个，多出的用1填充
//	//默认用0填充
//	q.resize(15,1);
//	cout << "有效元素有：" << q.size() << endl;
//	Print(q);
//
//	//将有效元素改为0个，然后判空(deque为空)
//	q.resize(0);
//	if (q.empty())
//		cout << "deque is empty" << endl;
//	else
//		cout << "deque is not empty" << endl;
//}
//
////元素访问操作，[],front(),back()都有可读可写的
//           //与只可读(const)这俩种权限的重载，元素是什么权限，调用时就掉那个权限的
//void test4()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
//	deque<int> q(arr, arr + sizeof(arr) / sizeof(int));
//
//	//支持像数组一样的随机访问
//	for (size_t i = 0; i < q.size(); ++i)
//	{
//		cout << q[i] << ' ';
//	}
//	cout << endl;
//
//	//可读可写
//	q[2] = 30;
//	Print(q);
//
//	//获取头部与尾部的元素并修改
//	q.front() = 10;
//	q.back() = 80;
//	Print(q);
//}
//
////修改操作之插入删除操作
//void test5()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
//	deque<int> q(arr, arr + sizeof(arr) / sizeof(int));
//
//	//头插尾插
//	q.push_back(9);
//	q.push_front(0);
//	Print(q);
//
//	//头删尾删
//	q.pop_back();
//	q.pop_front();
//	Print(q);
//
//	//在begin()位置插入0
//	q.insert(q.begin(), 0);
//	Print(q);
//
//	//在begin()位置插入5个1
//	q.insert(q.begin(), 5, 1);
//	Print(q);
//
//	//删除最后一个元素
//	//end()为最后一个位置的下一个位置
//	q.erase(q.end()-1);
//	Print(q);
//
//	//删除[begin()+2,end()-3) 这个左闭又开区间内的元素
//	q.erase(q.begin() + 2, q.end() - 3);
//	Print(q);
//}
//
////交换操作与emplace操作
//void test6()
//{
//	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
//	deque<int> q1(arr1, arr1 + sizeof(arr1) / sizeof(int));
//	int arr2[] = { 4, 3, 2, 1 };
//	deque<int> q2(arr2, arr2 + sizeof(arr2) / sizeof(int));
//
//	//交换q1，q2
//	q1.swap(q2);
//	Print(q1);
//	Print(q2);
//
//	//清空q1
//	q1.clear();
//	Print(q1);
//
//	//注意：针对内置类型push_back与emplace_back,俩个的头插，效率相同
//	//但若是针对自定义类型则：emplace的效率更高
//	//原因：emplace操作会直接在头部或尾部构造元素，而push_back,push_front则是先将元素构造好，然后再拷贝到头部或者尾部
//
//	//使用emplace_front/emplace_back进行插入
//	q2.emplace_back(9);
//	q2.emplace_front(0);
//	Print(q2);
//
//	//使用emplace在任意位置插入
//	q2.emplace(q2.begin() + 3, 30);
//	Print(q2);
//}
//
////对deque排序，利用库函数
////但其效率比较低下(因为deque本身的原因)
//#include<algorithm>
//void test7()
//{
//	int arr1[] = { 1, 4, 2, 5, 3, 8, 6, 7 };
//	deque<int> q1(arr1, arr1 + sizeof(arr1) / sizeof(int));
//    Print(q1);
//
//	sort(q1.begin(), q1.end());
//	Print(q1);
//}
//int main()
//{
//	//test1();
//	//test2();
//	//test3();
//	//test4();
//	//test5();
//	//test6();
//	test7();
//
//	return 0;
//}

//stack栈练习
#include<iostream>
#include<stack>

using namespace std;

void test1()
{

}

int main()
{
	test1();

	return 0;
}