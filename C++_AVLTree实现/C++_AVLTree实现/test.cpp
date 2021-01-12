#include"AVLTree.h"

void test()
{
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };//有问题
	//正确输出：3，7，9，11，14，15，16，18，26
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> tree;
	for (auto e : a)
	{
		tree.Insert(make_pair(e, e));
	}

	tree.InOrder();

	cout << tree.IsBalance() << endl;
}

void main()
{
	test();
	system("pause");
}