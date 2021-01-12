#pragma once;
#include<iostream>
using namespace std;

enum Colour
{
	BLACK,
	RED
};
template<class K,class V>
struct RBTreeNode
{
	RBTreeNode<K,V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	pair<K, V> _kv;

	Colour _col;

	RBTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(BLACK)
	{}
};

template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		//1.按搜索树的规则进行插入
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first>kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		//新增节点给红的
		cur->_col = RED;
		while (parent && parent->_col == RED)
		{
			//红黑树的调整关键看叔叔
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				//情况一：uncle存在且为红
				//情况二：uncle不存在
				//情况三：uncle存在且为黑
				if (uncle && uncle->_col == RED)
				{
					//变色
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续往上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else//情况二、三
				{
					//情况三：让双旋变为单旋
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(parent, cur);
					}

					//第二种情况(ps：有可能是第三种变过来的)
					RotateR(grandfather);
					grandfather->_col = RED;
					parent->_col = BLACK;

					break;
				}
			}
			else
			{
				//与上边if的方向相反
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					//uncle存在且为红
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//uncle不存在或者存在且为黑
					//旋转+变色
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						RotateRL(grandfather);
						grandfather->_col = RED;
						cur->_col = BLACK;
					}

					break;
				}
			}
		}

		_root->_col = BLACK;

		return true;
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
        	return;
		_InOrder(root->_left);
		cout << root->_kv.first << "：" << root->_kv.second << endl;
		_InOrder(root->_right);
	}
	void InOrder(Node* root)
	{
		_InOrder(_root);
	}
private:
	Node* _root = nullptr;
};