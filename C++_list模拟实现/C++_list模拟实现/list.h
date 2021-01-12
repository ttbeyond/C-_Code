#pragma once
#include<iostream>
#include<assert.h>

using namespace std;

namespace txt_list
{
	//����һ��ģ��ڵ���Ϣ
	template<class T>
	struct __listnode
	{
		__listnode<T>* _next;
		__listnode<T>* _prev;
		T _data;
        
		__listnode(const T& x = T())
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};
	//���������ģ��
	template<class T,class Ref,class Ptr>
	//template< T, T&, T*>//�����������Ӧ
	//Ref �������Ƿ�Ϊconst������const���󷵻�const�ģ�����const�ķ��ط�const��
	struct __list_iterator
	{
		typedef __listnode<T> Node;
		typedef __list_iterator<T, Ref, Ptr> Self_iterator;
		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{}

		//*it
		Ref& operator*()
		{
			return _node->_data;
		}
		//����->
		//Ptr* operator->()
		//{
		//	return &_node->_data;
		//}
		T* operator->()
		{
			return &_node->_data;
		}
		//++it
		Self_iterator& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		//it++
		Self_iterator operator++(int)
		{
			Self_iterator tmp(*this);
			_node = _node->_next;

			return tmp;
		}
		//ǰ��--
		Self_iterator& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		//����--
		Self_iterator& operator--(int)
		{
			Self_iterator tmp(*this);
			//_node = _node->_prev;
			--(*this);//����һ��ǰ��--�Ĵ���
			return tmp;
		}
        //it!=end()
		bool operator!=(Self_iterator& it)
		{
			return _node != it._node;
		}
		bool operator==(const Self_iterator& it)
		{
			return _node == it._node;
		}
	};


	//����ģ��
	template<class T>
	class list
	{
		//���ڵ���Ϣģ����������ΪNode����ǿ����ɶ���
		typedef __listnode<T> Node;
        
	public:
		//��������ģ����������Ϊiterator����ǿ����ɶ���
		typedef __list_iterator<T,T&,T*> iterator;
		//const������
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			//��������end()���ص�Ϊβ������һ��λ�ã�Ҳ���Ǵ������е�ͷ
			return iterator(_head);
		}
		//const������
		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end()const
		{
			return const_iterator(_head);
		}
		//����(˫���ͷѭ������)
		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		//��������(���)
		//lt2(lt1)
		list(const list<T>& lt)
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;

			const_iterator it = lt.begin();
			while (it != end())
			{
				push_back(*it);
				++it;
			}
			//Ҳ�����÷�Χfor���
			//for (auto e : lt)
			//	push_back(e);
		}
		//��ֵ
		//lt1=lt2
		//list<T>& operator=(const list<T>& lt)
		//{
		//	if (this != &lt)
		//	{
		//		clear();//���lt1����lt1��ԭ������Ԫ������Ŀ���

		//		//��lt2����������θ���lt1
		//		for (auto e : lt)
		//			push_back(e);
		//	}

		//	return *this;
		//}
		//��ֵ�ִ�д��
		//lt1=lt2
		list<T>& operator=(list<T> lt)//��ֵ�����������һ��lt2
		{
			swap(_head, lt._head);
			//����֮��ltʵ���Ѿ�Ϊԭ����this���������Ǿֲ�������
			//�ں����������֮��ͻ�������������ͷţ�Ҳ�͸պôﵽ�˴�ͳд������Ҫ���this��Ŀ��
			return *this;
		}
		//����
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		//������ЧԪ��
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				erase(it++);//����ͬ��
				//it = erase(it);
			}
		}
		//�������нڵ㻹���޽ڵ������߼���һ��
		//ԭ�򣺹��캯�����ĵľ���һ����ͷ������
		//ͷ��
		void push_back(const T& x)
		{
			//Node* newnode = new Node(x);//�����½ڵ�
			//Node* tail = _head->_prev;//�ҵ�β�ڵ㣬���±ߵĹ�ϵ��������

			//tail->_next = newnode;
			//newnode->_prev = tail;
			//_head->_prev = newnode;
			//newnode->_next = _head;
			insert(end(), x);
		}
		////βɾ
		void pop_back()
		{
			//erase(iterator(_head->_head));
			erase(--end());
		}
		////ͷ��
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		////ͷɾ
		void pop_front()
		{
			erase(begin());
		}
		//����λ�ò���
		void insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);
			//���߹�ϵ��prev->newnode->cur
			//������
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}
		//����λ��ɾ��
		void erase(iterator pos)
		{
			assert(pos != end());

			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			delete cur;

			prev->_next = next;
			next->_prev = prev;
		}

		//��С
		size_t size()const
		{
			size_t count = 0;
			Node* tmp = _head->_next;
			while (tmp != _head)
			{
				++count;
				tmp = tmp->_next;
			}
			return count;
		}
		//�п�
		bool empty()const
		{
			return _head->_next == _head;
		}
	private:
		Node* _head;
	};

	void test1()
	{
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);

		list<int>::iterator it = l1.begin();
		while (it != l1.end())
		{
			cout << *it << ' ';
			++it;
		}
		cout << endl;
	}
	struct Data
	{
		int _year = 2020;
		int _month = 10;
		int _day = 30;
	};
	void test2()
	{
		list<Data> lt;
		lt.push_back(Data());
		lt.push_back(Data());
        
		list<Data>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//���ö���.����ʽ����Data��//��һ��ʹ���±ߵķ�ʽ���з���
			//cout << (*it)._year << "-" << (*it)._month << '-' << (*it)._day << endl;

			//���ﱾӦ��it->->_year,����Ϊ�˱�֤�ɶ��ԣ��������ڴ��������Ż�����,it->->��ʵ�ɽ���Ϊlt->Data()->_year
			cout << it->_year << "-" << it->_month << '-' << it->_day << endl;
			++it;
		}
		cout << endl;

	}
	void test3()
	{
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);

		list<int>::iterator it = l1.begin();
		while (it != l1.end())
		{
			cout << *it << ' ';
			++it;
		}
		cout << endl;

		l1.pop_back();
		l1.pop_front();
		for (auto e : l1)
			cout << e << ' ';
		cout << endl;

		auto pos = l1.end();
		l1.insert(--pos, 5);
		for (auto e : l1)
			cout << e << ' ';
		cout << endl;

		cout << l1.size() << endl;

		l1.clear();
		cout << l1.empty() << endl;

	}
}