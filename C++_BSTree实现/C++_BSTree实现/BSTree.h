#pragma once
#include<iostream>
using namespace std;

////key模型
//template<class K>
//struct BSTreeNode
//{
//	BSTreeNode<K>* _left;
//	BSTreeNode<K>* _right;
//
//	K _key;//关键字
//
//	BSTreeNode(const K& key)
//		:_left(nullptr)
//		, _right(nullptr)
//		, _key(key)
//	{}
//};
//
//template<class K>
//class BSTree
//{
//	typedef BSTreeNode<K> Node;
//public:
//	bool Insert(const K& key)
//	{
//		if (_root == nullptr)
//		{
//			_root = new Node(key);
//			return true;
//		}
//
//		//找插入位置
//		//注意：搜索二叉树不允许数据冗余(即：一个数只能出现一次)
//		Node* parent = nullptr;//保存cur的父节点，为了后边的链接做准备
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (cur->_key>key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else
//			{
//				return false;
//			}
//		}
//
//		cur = new Node(key);//插入
//		//链接起来
//		if (parent->_key < key)
//		{
//			parent->_right = cur;
//		}
//		else
//		{
//			parent->_left = cur;
//		}
//		return true;
//	}
//
//	//删除节点
//	bool Erase(const K& key)
//	{
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (cur->_key>key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else
//			{
//				//找到了//开始删除
//				//三种情况
//				//1.cur的左为空 2.右为空 3.左右都不为空
//				if (cur->_left == nullptr)
//				{
//					if (cur == _root)
//					{
//						_root = cur->_right;
//					}
//					else
//					{
//						if (parent->_right == cur)
//							parent->_right = cur->_right;
//						else
//							parent->_left = cur->_right;
//					}
//
//					delete cur;
//				}
//				else if (cur->_right == nullptr)
//				{
//					if (cur == _root)
//					{
//						_root = cur->_left;
//					}
//					else
//					{
//					   if (parent->_left == cur)
//						   parent->_left = cur->_left;
//					   else
//						   parent->_right = cur->_left;
//					}
//
//
//					delete cur;
//				}
//				else
//				{
//					Node* rightMinParent = cur;
//					Node* rightMin = cur->_right;
//					while (rightMin->_left)
//					{
//						rightMinParent = rightMin;
//						rightMin = rightMin->_left;
//					}
//
//					//替换根节点
//					cur->_key = rightMin->_key;
//					//转换成删除rightMin节点
//					//rightMin有右孩子的情况就直接让其与rightMin的父节点链接起来
//					//没有就相当于给rightMin的左孩子置空了。
//					if (rightMin == rightMinParent->_left)
//						rightMinParent->_left = rightMin->_right;
//					else
//						rightMinParent->_right = rightMin->_right;
//
//					//删除rightMin，即可达到目的
//					delete rightMin;
//				}
//
//				return true;
//			}
//		}
//		//找不到的情况
//		//删除失败
//		return false;
//	}
//
//	//查找元素
//	bool Find(const K& key)
//	{
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key > key)
//			{
//				cur = cur->_left;
//			}
//			else if (cur->_key < key)
//			{
//				cur = cur->_right;
//			}
//			else//相等//找到的情况
//				return true;
//		}
//
//		//找不到的情况
//		return false;
//	}
//
//	//中序遍历
//	void _InOrder(Node* root)
//	{
//		if (root == nullptr)
//			return;
//		
//		_InOrder(root->_left);
//		cout << root->_key << " ";
//		_InOrder(root->_right);
//
//	}
//	void InOrder()
//	{
//		_InOrder(_root);
//		cout << endl;
//	}
//private:
//	Node* _root = nullptr;
//
//};

//key-value模型
#include<string>
template<class K,class V>
struct BSTreeNode
{
	BSTreeNode<K,V>* _left;
	BSTreeNode<K,V>* _right;

	K _key;//关键字
	V _value;

	BSTreeNode(const K& key,const V& value)
		:_left(nullptr)
		, _right(nullptr)
		, _key(key)
		, _value(value)
	{}
};

template<class K,class V>
class BSTree
{
	typedef BSTreeNode<K,V> Node;
public:
	bool Insert(const K& key,const V& value)
	{
		if (_root == nullptr)
		{
			_root = new Node(key, value);
			return true;
		}

		//找插入位置
		//注意：搜索二叉树不允许数据冗余(即：一个数只能出现一次)
		Node* parent = nullptr;//保存cur的父节点，为了后边的链接做准备
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key>key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(key, value);//插入
		//链接起来
		if (parent->_key < key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}

	//删除节点
	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key>key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//找到了//开始删除
				//三种情况
				//1.cur的左为空 2.右为空 3.左右都不为空
				if (cur->_left == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_right == cur)
							parent->_right = cur->_right;
						else
							parent->_left = cur->_right;
					}

					delete cur;
				}
				else if (cur->_right == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_left == cur)
							parent->_left = cur->_left;
						else
							parent->_right = cur->_left;
					}


					delete cur;
				}
				else
				{
					Node* rightMinParent = cur;
					Node* rightMin = cur->_right;
					while (rightMin->_left)
					{
						rightMinParent = rightMin;
						rightMin = rightMin->_left;
					}

					//替换根节点
					cur->_key = rightMin->_key;
					//转换成删除rightMin节点
					//rightMin有右孩子的情况就直接让其与rightMin的父节点链接起来
					//没有就相当于给rightMin的左孩子置空了。
					if (rightMin == rightMinParent->_left)
						rightMinParent->_left = rightMin->_right;
					else
						rightMinParent->_right = rightMin->_right;

					//删除rightMin，即可达到目的
					delete rightMin;
				}

				return true;
			}
		}
		//找不到的情况
		//删除失败
		return false;
	}

	//查找元素
	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else//相等//找到的情况
				return cur;
		}

		//找不到的情况
		return nullptr;
	}

	//中序遍历
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_key << " " << _root->_value << endl;
		_InOrder(root->_right);

	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
private:
	Node* _root = nullptr;

};