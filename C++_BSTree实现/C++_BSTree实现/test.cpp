#include"BSTree.h"

//void test_key_model()
//{
//	BSTree<int> t;
//	int arr[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
//	for (auto e : arr)
//	{
//		t.Insert(e);
//	}
//
//	t.InOrder();
//
//	t.Erase(7);
//	t.InOrder();
//
//	t.Erase(2);
//	t.InOrder();
//
//	t.Erase(8);
//	t.Erase(1);
//	t.InOrder();
//
//	t.Erase(5);
//	t.InOrder();
//
//	for (auto e : arr)
//	{
//		t.Erase(e);
//		t.InOrder();
//	}
//}

//中英字典互译
void test_key_val_model1()
{
	BSTree<string, string> dict;
	dict.Insert("model", "模型");
	dict.Insert("string", "字符串");
	dict.Insert("insert", "插入");
	dict.Insert("BSTree", "二叉搜索树");

	string str;
	while (cin >> str)
	{
		BSTreeNode<string, string>* ret = dict.Find(str);
		if (ret)
		{
			cout << ret->_value << endl;
		}
		else
			cout << "无此单词" << endl;
	}
}

//统计次数
void test_key_val_model2()
{
	string strArr[] = { "西瓜", "葡萄", "香蕉", "苹果", "梨子", "西瓜", "葡萄", "香蕉", "苹果", "梨子" };
	BSTree<string, int> countTree;
	for (auto str : strArr)
	{
		BSTreeNode<string, int>* ret = countTree.Find(str);
		if (ret == nullptr)
			countTree.Insert(str, 1);
		else
			ret->_value++;
	}
	countTree.InOrder();
}
int main()
{
	//test_key_model();
	test_key_val_model2();

	system("pause");
	return 0;
}