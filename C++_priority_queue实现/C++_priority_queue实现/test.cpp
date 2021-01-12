#include"priority_queue.h"

//sortʹ�÷º�������ϰ
void test_sort()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	v.push_back(12);
	v.push_back(9);

	//Ĭ��������
	//sort(v.begin(), v.end());

	//Ҫ�Ž����������÷º����ĵ���������greater<int>
	//ʹ�÷���һ��
	//greater<int> gt;
	//sort(v.begin(), v.end(), gt);

	//��������(һ�������)
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