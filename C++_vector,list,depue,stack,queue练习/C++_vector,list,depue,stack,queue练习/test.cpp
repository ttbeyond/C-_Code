//#include<iostream>
//#include<vector>
//
//using namespace std;

//void Print(const vector<int>& n)
//{
//	//����const������
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
//	//���������������
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << ' ';
//		it++;
//	}
//	cout << endl;
//	
//	//ʹ�õ������޸�����
//	it = v.begin();//ע��˴�Ҫ����it
//	while (it != v.end())
//	{
//		*it *= 2;
//		cout << *it << ' ';
//		it++;
//	}
//	cout << endl;
//
//	//ʹ�õ���������������Ҵ�ӡ
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

////��֤vactor��capaccity��������
////ע�⣺��VS��ʹ��PJ��STL����1.5����������g++��ʹ��SGI��STL����2������
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
//			n = arr.capacity();//����n
//            cout << "capacity was changed:" << n << endl;
//		}
//			
//	}
//	return 0;
//}

////ʹ��resreve��Ч���벻ʵ�õĶԱ�
//int main()
//{
//	//��ʹ��
//	size_t n = 0;
//	vector<int> arr;
//	n = arr.capacity();
//	cout << "making arr growing" << endl;
//	for (int i = 0; i < 100; ++i)
//	{
//		arr.push_back(i);
//		if (n != arr.capacity())
//		{
//			n = arr.capacity();//����n
//			cout << "capacity was changed:" << n << endl;
//		}
//
//	}
//	cout << endl;
//	cout << endl;
//	cout << endl;
//
//	//ʹ��
//	//ʡȥ�˺ܶ����ݴ����Ŀ���
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

////resize(n,x) ������Ч�ַ�����Ϊn���ճ�����x��䣬����Ĭ����0���
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
//	v.pop_back();//βɾ
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
//	v.push_back(5);//β��
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

////insert,erase,find ��vector��ʹ��
//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5, 6 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//
//	//ע�⣺find��������vector�Ľӿں�����ʹ�÷���Ϊ��find(��ʼλ�ã�����λ�ã�����Ѱ�ҵ�Ԫ��);
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//	while (pos != v.end())
//	{
//		cout << *pos << ' ';//3 4 5 6
//		++pos;
//	}
//	cout << endl;
//
//	//ɾ��posλ�ô���Ԫ��
//	pos = find(v.begin(), v.end(), 3);//�ҵ�3���ڵ�λ��
//	v.erase(pos);//ɾ��
//
//	pos = v.begin();
//	while (pos != v.end())
//	{
//		cout << *pos << ' ';//1 2 4 5 6
//		++pos;
//	}
//	cout << endl;
//
//	//��posλ�ô���������
//	pos = find(v.begin(), v.end(), 4);
//	v.insert(pos , 30);//����30
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

////vector�����ֱ�����ʽ
//int main()
//{
//	char str[] = "asdf";
//	vector<char> v(str, str + sizeof(str));
//
//	//[],��������ʽ����
//	for (int i = 0; i < v.size(); ++i)
//	{
//		cout << v[i] << ' ';
//	}
//	cout << endl;
//
//	//swap��ʹ�ã���������������ߵ�����
//	vector<char> ch;
//	ch.swap(v);//�ȼ���ch.swap(ch,v),����������thisָ���Ե�ʣ���chʡ����
//
//	//ʹ�õ�������ӡ����֮��Ľ��
//	cout << "ch������";
//	vector<char>::iterator it = ch.begin();
//	while (it != ch.end())
//	{
//		cout << *it << ' ';
//		++it;
//	}
//	cout << endl;
//
//	cout << "v�����ݣ�";
//	it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << ' ';
//	}
//	cout <<"v�Ĵ�С��"<< v.size() << endl;
//
//	//��Χfor����
//	for (auto a : ch)
//	{
//		cout << a << ' ';
//	}
//	cout << endl;
//	return 0;
//}

////���ݵ��µ�����ʧЧ����
////insert,erase��push_back�ȵ���posλ�õ�����ʧЧ����
////insert�ڲ�����ԭ�������ݵ�����£�����������ʧЧ��һ����Ҫ���ݱ��ʧЧ
////��erase��ʹ�û�ֱ�ӵ���posλ�ô�������ʧЧ
//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//
//	v.erase(pos);
//	cout << *pos << endl;//�������
//
//	pos = find(v.begin(), v.end(), 4);
//
//	v.insert(pos, 33);
//	cout << *pos << endl;//�������������
//
//	for (int i = 100; i > 0; --i)//�������
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
//	// ʵ��ɾ��v�е�����ż��
//	// ����ĳ����������������ż����erase����itʧЧ
//	// ��ʧЧ�ĵ���������++it���ᵼ�³������
//	//vector<int>::iterator it = v.begin();
//	//while (it != v.end())
//	//{
//	//	if (*it % 2 == 0)
//	//		v.erase(it);
//	//	++it;
//	//}
//	// ���ϳ���Ҫ�ĳ�����������erase�᷵��ɾ��λ�õ���һ��λ��
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

//list��ϰ
#include<iostream>
#include<list>

using namespace std;

//int main()
//{
//	list<int> l;        //����յ�list����
//	list<int> l1(4, 10);//����list�����а���4��ֵΪ10��Ԫ��
//	list<int> l2(l1);   //��l1��������l2
//	l = l2;             //��ֵ���������
//
//	for (auto e : l)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//
//	//������arrΪ���������乹��l3
//	int arr[] = { 1, 2, 3, 45, 6 };
//	list<int> l3(arr, arr + sizeof(arr) / sizeof(int));
//	for (auto e : l3)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//
//	list<int> l4(l3.begin(), l3.end());//��l3��[begin(),end() )����ҿ������乹�촦l4
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
//	//�������������//�ɶ���д
//	list<int>::iterator it = l.begin();
//	while (it != l.end())
//	{
//		cout << *it << ' ';
//		++it;
//	}
//	cout << endl;
//
//	//�������������//�ɶ���д
//	list<int>::reverse_iterator it1 = l.rbegin();
//	while (it1 != l.rend())
//	{
//		cout << *it1 << ' ';
//		++it1;
//	}
//	cout << endl;
//
//	//const�������������//�ɶ�
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
//		cout << "list�ѿ�"<< endl;
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
//	//��ͷ��β�ֱ��Ϊ10��70
//	l.front() = 10;
//	l.back() = 70;
//
//	for (auto e : l)
//		cout << e << ' ';
//	cout << endl;
//
//	//const�������front()const
//	const int n = l.front();
//	cout << n << endl;
//
//	return 0;
//}


//list����ɾ�Ĳ�
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
//	//ͷ���β��
//	l.push_back(8);
//	l.push_front(0);
//	Print(l);
//	//ͷɾβɾ
//	l.pop_back();
//	l.pop_front();
//	Print(l);
//
//	//��posλ�ô�����20
//	//ע�⣺posָ���λ��ΪԪ��2��λ�ã�һֱ���䣬������pos֮ǰ��ɾ����pos֮��
//	auto pos = ++l.begin();
//	l.insert(pos, 20);
//	Print(l);
//
//	//��posλ�ô�����5��50
//	l.insert(pos, 5, 50);
//	Print(l);
//
//	//��posλ�ô�����[v.begin(),v.end() )�����Ԫ��
//	vector<int> v{ 11, 22, 33 };
//	l.insert(pos, v.begin(), v.end());
//	Print(l);
//
//	//ɾ��posλ�ô���ֵ
//	l.erase(pos);
//	Print(l);
//
//	//ɾ��һ����Χ֮�ڵ�Ԫ��
//	l.erase(++l.begin(), --l.end());
//	Print(l);
//	return 0;
//}

//resize()������ЧԪ�ظ�����Ĭ����0���
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
//	list<int> l(arr, arr + sizeof(arr) / sizeof(int));
//
//	Print(l);
//
//	//resize()��ʹ��Ч��
//	l.resize(10);
//	Print(l);
//
//	//���Ԫ����30���
//	l.resize(20,30);
//	Print(l);
//
//	//����ЧԪ�ظ�Ϊ5��
//	l.resize(5);
//	Print(l);
//	return 0;
//}

//swap()��clear()��ʹ��
//clear()�����ЧԪ�غ�size��Ϊ0,����������ָ���λ�û��ᱻ���棬�Ա�Ҫ�������
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
//	//����(��ͬ���ͣ�
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

//list�� erase()���ܵ��µ�����ʧЧ
//ԭ��erase()ɾ������posλ�õ�ֵ������������itָ����������ֵ�ı���
//Ҳ�����ԭ��push_back(),���ᵼ�µ�������ʧЧ
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
//		//erase()����ɾ������Ǹ�Ԫ��ԭ����λ��
//		it = l1.erase(it);//��ͬ��l1.erase(it++);
//		//it++
//		
//	}
//	return 0;
//}


//deque��ϰ
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
////����
//void test1()
//{
//	//����յ�q1
//	deque<int> q1;
//	//��5��ֵΪ10��Ԫ�ع���q2
//	deque<int> q2(5, 10);
//	//��arr���鹹��q3
//	int arr[] = { 1, 2, 3, 4, 5 };
//	deque<int> q3(arr,arr+5);
//	//��q3��������q4
//	deque<int>q4(q3);
//
//	Print(q1);
//	Print(q2);
//	Print(q3);
//	Print(q4);
//}
//
////����������
//void test2()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
//	deque<int> q(arr, arr + sizeof(arr) / sizeof(int));
//
//	//�������//�ɶ���д
//	deque<int>::iterator it = q.begin();
//	while (it != q.end())
//	{
//		cout << *it << ' ';
//		++it;
//	}
//	cout << endl;
//
//	//�������//�ɶ���д
//	deque<int>::reverse_iterator rit = q.rbegin();
//	while (rit != q.rend())
//	{
//		cout << *rit << ' ';
//		++rit;
//	}
//	cout << endl;
//
//	//����const����//ֻ�ɶ�
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
////��������
//void test3()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
//	deque<int> q(arr, arr + sizeof(arr) / sizeof(int));
//
//	//�鿴��ЧԪ�ظ���
//	cout << "��ЧԪ���У�" << q.size() << endl;
//	Print(q);
//
//	//����ЧԪ�ظ�����Ϊ15�����������1���
//	//Ĭ����0���
//	q.resize(15,1);
//	cout << "��ЧԪ���У�" << q.size() << endl;
//	Print(q);
//
//	//����ЧԪ�ظ�Ϊ0����Ȼ���п�(dequeΪ��)
//	q.resize(0);
//	if (q.empty())
//		cout << "deque is empty" << endl;
//	else
//		cout << "deque is not empty" << endl;
//}
//
////Ԫ�ط��ʲ�����[],front(),back()���пɶ���д��
//           //��ֻ�ɶ�(const)������Ȩ�޵����أ�Ԫ����ʲôȨ�ޣ�����ʱ�͵��Ǹ�Ȩ�޵�
//void test4()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
//	deque<int> q(arr, arr + sizeof(arr) / sizeof(int));
//
//	//֧��������һ�����������
//	for (size_t i = 0; i < q.size(); ++i)
//	{
//		cout << q[i] << ' ';
//	}
//	cout << endl;
//
//	//�ɶ���д
//	q[2] = 30;
//	Print(q);
//
//	//��ȡͷ����β����Ԫ�ز��޸�
//	q.front() = 10;
//	q.back() = 80;
//	Print(q);
//}
//
////�޸Ĳ���֮����ɾ������
//void test5()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
//	deque<int> q(arr, arr + sizeof(arr) / sizeof(int));
//
//	//ͷ��β��
//	q.push_back(9);
//	q.push_front(0);
//	Print(q);
//
//	//ͷɾβɾ
//	q.pop_back();
//	q.pop_front();
//	Print(q);
//
//	//��begin()λ�ò���0
//	q.insert(q.begin(), 0);
//	Print(q);
//
//	//��begin()λ�ò���5��1
//	q.insert(q.begin(), 5, 1);
//	Print(q);
//
//	//ɾ�����һ��Ԫ��
//	//end()Ϊ���һ��λ�õ���һ��λ��
//	q.erase(q.end()-1);
//	Print(q);
//
//	//ɾ��[begin()+2,end()-3) �������ֿ������ڵ�Ԫ��
//	q.erase(q.begin() + 2, q.end() - 3);
//	Print(q);
//}
//
////����������emplace����
//void test6()
//{
//	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
//	deque<int> q1(arr1, arr1 + sizeof(arr1) / sizeof(int));
//	int arr2[] = { 4, 3, 2, 1 };
//	deque<int> q2(arr2, arr2 + sizeof(arr2) / sizeof(int));
//
//	//����q1��q2
//	q1.swap(q2);
//	Print(q1);
//	Print(q2);
//
//	//���q1
//	q1.clear();
//	Print(q1);
//
//	//ע�⣺�����������push_back��emplace_back,������ͷ�壬Ч����ͬ
//	//����������Զ���������emplace��Ч�ʸ���
//	//ԭ��emplace������ֱ����ͷ����β������Ԫ�أ���push_back,push_front�����Ƚ�Ԫ�ع���ã�Ȼ���ٿ�����ͷ������β��
//
//	//ʹ��emplace_front/emplace_back���в���
//	q2.emplace_back(9);
//	q2.emplace_front(0);
//	Print(q2);
//
//	//ʹ��emplace������λ�ò���
//	q2.emplace(q2.begin() + 3, 30);
//	Print(q2);
//}
//
////��deque�������ÿ⺯��
////����Ч�ʱȽϵ���(��Ϊdeque�����ԭ��)
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

//stackջ��ϰ
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