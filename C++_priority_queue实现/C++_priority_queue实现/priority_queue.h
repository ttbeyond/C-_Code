#pragma once
#include<iostream>
#include<vector>
#include<algorithm>  //sort算法的头文件
#include <functional>//仿函数的头文件

using namespace std;

namespace txt_priority_queue
{
	//仿函数 函数对象
	//小于(大堆)
	template<class T>
	struct less
	{
		bool operator()(const T& x1, const T& x2)
		{
			return x1 < x2;
		}
	};
	//大于(小堆)
	template <class T>
	struct greater
	{
		bool operator()(const T& x1, const T& x2)
		{
			return x1 > x2;
		}
	};

	//默认为大堆//原因：第三个缺省参数给的是less(小于)//大堆用小于//小堆用大于
	template<class T, class Container = vector<T>,class Compare = less<T>>
	class priority_queue
	{
	public:
		Compare _com;
		void AdJustUp(int child)
		{
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[child] > _con[parent])//用仿函数，顺序要换一下，如下
			   if (_com(_con[parent],_con[child]))
				{
					swap(_con[child], _con[parent]);
					//更新数据
					child = parent;
					parent = (child - 1) / 2;
				}
				else
					break;
			}

		}
		void AdJustDown(int root)
		{
			int parent = root;
			int child = parent * 2 + 1;
			while (child < _con.size())
			{
				//找出左右孩子大的那个//默认左孩子大
				/*if (child + 1 < _con.size() && _con[child + 1] > _con[child])*/
				if (child + 1 < _con.size() && _com(_con[child],_con[child+1]))
				{
					++child;
				}

				//if (_con[child]>_con[parent])
				if (_com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
					break;
			}
		}
		void push(const T& x)
		{
			_con.push_back(x);
			AdJustUp(_con.size() - 1);
		}

		void pop()
		{
			//交换堆顶与堆尾的数据//然后在删除//在向下调堆
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();

			AdJustDown(0);
		}

		T& top()
		{
			return _con[0];
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};

	void test1()
	{
		//降序
		priority_queue<int> q;//没有传第三个参数，于是用了默认的less，构建了大堆
		//升序
		//priority_queue<int,vector<int>,greater<int>> q;
		q.push(3);
		q.push(1);
		q.push(9);
		q.push(4);
		q.push(2);

		while (!q.empty())
		{
			cout << q.top() << ' ';
			q.pop();
		}
		cout << endl;
	}
}