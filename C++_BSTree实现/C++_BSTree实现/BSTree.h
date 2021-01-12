#pragma once
#include<iostream>
using namespace std;

////keyģ��
//template<class K>
//struct BSTreeNode
//{
//	BSTreeNode<K>* _left;
//	BSTreeNode<K>* _right;
//
//	K _key;//�ؼ���
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
//		//�Ҳ���λ��
//		//ע�⣺������������������������(����һ����ֻ�ܳ���һ��)
//		Node* parent = nullptr;//����cur�ĸ��ڵ㣬Ϊ�˺�ߵ�������׼��
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
//		cur = new Node(key);//����
//		//��������
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
//	//ɾ���ڵ�
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
//				//�ҵ���//��ʼɾ��
//				//�������
//				//1.cur����Ϊ�� 2.��Ϊ�� 3.���Ҷ���Ϊ��
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
//					//�滻���ڵ�
//					cur->_key = rightMin->_key;
//					//ת����ɾ��rightMin�ڵ�
//					//rightMin���Һ��ӵ������ֱ��������rightMin�ĸ��ڵ���������
//					//û�о��൱�ڸ�rightMin�������ÿ��ˡ�
//					if (rightMin == rightMinParent->_left)
//						rightMinParent->_left = rightMin->_right;
//					else
//						rightMinParent->_right = rightMin->_right;
//
//					//ɾ��rightMin�����ɴﵽĿ��
//					delete rightMin;
//				}
//
//				return true;
//			}
//		}
//		//�Ҳ��������
//		//ɾ��ʧ��
//		return false;
//	}
//
//	//����Ԫ��
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
//			else//���//�ҵ������
//				return true;
//		}
//
//		//�Ҳ��������
//		return false;
//	}
//
//	//�������
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

//key-valueģ��
#include<string>
template<class K,class V>
struct BSTreeNode
{
	BSTreeNode<K,V>* _left;
	BSTreeNode<K,V>* _right;

	K _key;//�ؼ���
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

		//�Ҳ���λ��
		//ע�⣺������������������������(����һ����ֻ�ܳ���һ��)
		Node* parent = nullptr;//����cur�ĸ��ڵ㣬Ϊ�˺�ߵ�������׼��
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

		cur = new Node(key, value);//����
		//��������
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

	//ɾ���ڵ�
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
				//�ҵ���//��ʼɾ��
				//�������
				//1.cur����Ϊ�� 2.��Ϊ�� 3.���Ҷ���Ϊ��
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

					//�滻���ڵ�
					cur->_key = rightMin->_key;
					//ת����ɾ��rightMin�ڵ�
					//rightMin���Һ��ӵ������ֱ��������rightMin�ĸ��ڵ���������
					//û�о��൱�ڸ�rightMin�������ÿ��ˡ�
					if (rightMin == rightMinParent->_left)
						rightMinParent->_left = rightMin->_right;
					else
						rightMinParent->_right = rightMin->_right;

					//ɾ��rightMin�����ɴﵽĿ��
					delete rightMin;
				}

				return true;
			}
		}
		//�Ҳ��������
		//ɾ��ʧ��
		return false;
	}

	//����Ԫ��
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
			else//���//�ҵ������
				return cur;
		}

		//�Ҳ��������
		return nullptr;
	}

	//�������
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