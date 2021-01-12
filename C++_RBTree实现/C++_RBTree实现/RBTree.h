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
		//1.���������Ĺ�����в���
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

		//�����ڵ�����
		cur->_col = RED;
		while (parent && parent->_col == RED)
		{
			//������ĵ����ؼ�������
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				//���һ��uncle������Ϊ��
				//�������uncle������
				//�������uncle������Ϊ��
				if (uncle && uncle->_col == RED)
				{
					//��ɫ
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//�������ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else//���������
				{
					//���������˫����Ϊ����
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(parent, cur);
					}

					//�ڶ������(ps���п����ǵ����ֱ������)
					RotateR(grandfather);
					grandfather->_col = RED;
					parent->_col = BLACK;

					break;
				}
			}
			else
			{
				//���ϱ�if�ķ����෴
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					//uncle������Ϊ��
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//uncle�����ڻ��ߴ�����Ϊ��
					//��ת+��ɫ
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
		cout << root->_kv.first << "��" << root->_kv.second << endl;
		_InOrder(root->_right);
	}
	void InOrder(Node* root)
	{
		_InOrder(_root);
	}
private:
	Node* _root = nullptr;
};