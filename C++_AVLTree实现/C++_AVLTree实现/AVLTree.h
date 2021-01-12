#pragma once
#include<iostream>
#include<map>
using namespace std;

template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	int _bf;       //balance factor(平衡因子)
	pair<K, V> _kv;

	AVLTreeNode(const pair<K,V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _bf(0)
	{}
};

template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const pair<K,V>& kv)
	{
		//1.先按照搜索树的规则进行插入
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first <= kv.first)
			{
				parent = cur;
				cur = cur->_right;
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

		//更新平衡因子
		while (parent)
		{
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}

			if (parent->_bf==0)
			{
              //说明parent所在的子树高度不变，更新结束
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				//说明parent所在的子树高度改变了，需要继续向上更新
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//parent所在的子树出现了不平衡现象，需要进行旋转处理
				//1.旋转的前提是保持他依旧是搜索二叉树
				//2.旋转成平衡树
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)
					{
						RotateL(parent);
					}	
					else if (cur->_bf == -1)
					{
						//右左双旋
						RotateRL(parent);
					}
				}
				else if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						RotateR(parent);
					}
					else if (cur->_bf == 1)
					{
						//左右双旋
						RotateLR(parent);
					}
				}

				//3.旋转完成后，parent所在的树的高度恢复到了插入节点前的高度
				//如果是子树，对上一层没有影响，更新结束
				break;
			}
		}

		return true;
	}

	//左单旋
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subR;

		//1.原来parent是这棵树的根，现在subR是根
		//2.parent为根的树只是整棵树的一个子树，改变链接关系之后，要让subR顶替他的位置
		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subR;
			else
				ppNode->_right = subR;
			
			subR->_parent = ppNode;
		}

		parent->_bf = subR->_bf = 0;
	}

	//右单旋
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subL;

		if (_root == nullptr)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subL;
			else
			    ppNode->_right = subL;

			subL->_parent = ppNode;
		}

		subL->_bf = parent->_bf = 0;
	}

	//右左双旋
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else if (bf == 1)
		{
			subR->_bf = 0;
			parent->_bf = -1;
			subRL->_bf = 0;
		}
		else if (bf == 0)
		{
			subR->_bf = 0;
			parent->_bf = 0;
			subRL->_bf = 0;
		}
	}
	//左右双旋
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(subL);
		RotateR(parent);

		if (bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
			subLR->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
	}
	//中序遍历
		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;
			
			_InOrder(root->_left);
			cout << root->_kv.first << " " << root->_kv.second << endl;
			_InOrder(root->_right);
	
		}
		void InOrder()
		{
			_InOrder(_root);
		}
	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;

		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		return abs(leftHeight - rightHeight) < 2
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);

	}
	bool IsBalance()
	{
		return _IsBalance(_root);
	}

	int Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
private:
	Node* _root = nullptr;
};