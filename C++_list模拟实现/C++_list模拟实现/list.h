#pragma once
#include<iostream>
#include<assert.h>

using namespace std;

namespace txt_list
{
	//定义一个模板节点信息
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
	//定义迭代器模板
	template<class T,class Ref,class Ptr>
	//template< T, T&, T*>//类型与上相对应
	//Ref 看类型是否为const对象，是const对象返回const的，不是const的返回非const的
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
		//重载->
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
		//前置--
		Self_iterator& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		//后置--
		Self_iterator& operator--(int)
		{
			Self_iterator tmp(*this);
			//_node = _node->_prev;
			--(*this);//复用一下前置--的代码
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


	//链表模板
	template<class T>
	class list
	{
		//将节点信息模板重新命名为Node，增强代码可读性
		typedef __listnode<T> Node;
        
	public:
		//将迭代器模板重新命名为iterator，增强代码可读性
		typedef __list_iterator<T,T&,T*> iterator;
		//const迭代器
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			//迭代器的end()返回的为尾部的下一个位置，也就是此链表中的头
			return iterator(_head);
		}
		//const迭代器
		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end()const
		{
			return const_iterator(_head);
		}
		//构造(双向带头循环链表)
		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		//拷贝构造(深拷贝)
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
			//也可以用范围for完成
			//for (auto e : lt)
			//	push_back(e);
		}
		//赋值
		//lt1=lt2
		//list<T>& operator=(const list<T>& lt)
		//{
		//	if (this != &lt)
		//	{
		//		clear();//清空lt1，对lt1在原本就有元素情况的考虑

		//		//将lt2里的内容依次赋给lt1
		//		for (auto e : lt)
		//			push_back(e);
		//	}

		//	return *this;
		//}
		//赋值现代写法
		//lt1=lt2
		list<T>& operator=(list<T> lt)//传值：拷贝构造出一个lt2
		{
			swap(_head, lt._head);
			//交换之后，lt实际已经为原来的this，而因其是局部变量，
			//在函数运行完毕之后就会调用析构函数释放，也就刚好达到了传统写法中先要清空this的目的
			return *this;
		}
		//析构
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		//清理有效元素
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				erase(it++);//与下同理
				//it = erase(it);
			}
		}
		//链表本身有节点还是无节点插入的逻辑都一样
		//原因：构造函数给的的就是一个带头的链表
		//头插
		void push_back(const T& x)
		{
			//Node* newnode = new Node(x);//创建新节点
			//Node* tail = _head->_prev;//找到尾节点，让下边的关系更加明了

			//tail->_next = newnode;
			//newnode->_prev = tail;
			//_head->_prev = newnode;
			//newnode->_next = _head;
			insert(end(), x);
		}
		////尾删
		void pop_back()
		{
			//erase(iterator(_head->_head));
			erase(--end());
		}
		////头插
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		////头删
		void pop_front()
		{
			erase(begin());
		}
		//任意位置插入
		void insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);
			//三者关系：prev->newnode->cur
			//链起来
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}
		//任意位置删除
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

		//大小
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
		//判空
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
			//采用对象.的形式访问Data类//但一般使用下边的方式进行访问
			//cout << (*it)._year << "-" << (*it)._month << '-' << (*it)._day << endl;

			//这里本应是it->->_year,但是为了保证可读性，编译器在此做出了优化处理,it->->其实可解释为lt->Data()->_year
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