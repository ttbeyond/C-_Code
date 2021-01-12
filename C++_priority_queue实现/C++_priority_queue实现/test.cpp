#include"priority_queue.h"

//sort使用仿函数的练习
void test_sort()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	v.push_back(12);
	v.push_back(9);

	//默认排升序
	//sort(v.begin(), v.end());

	//要排降序，则需利用仿函数的第三个参数greater<int>
	//使用方法一：
	//greater<int> gt;
	//sort(v.begin(), v.end(), gt);

	//方法二：(一般用这个)
	sort(v.begin(), v.end(), greater<int>());
	for (auto e : v)
	{
		cout << e << ' ';
	}
	cout << endl;
}
int main()
{
	//txt_priority_queue::test1();
	test_sort();
	return 0;
}