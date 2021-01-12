#pragma once
#include<iostream>
#include<vector>
#include<algorithm>  //sort�㷨��ͷ�ļ�
#include <functional>//�º�����ͷ�ļ�

using namespace std;

namespace txt_priority_queue
{
	//�º��� ��������
	//С��(���)
	template<class T>
	struct less
	{
		bool operator()(const T& x1, const T& x2)
		{
			return x1 < x2;
		}
	};
	//����(С��)
	template <class T>
	struct greater
	{
		bool operator()(const T& x1, const T& x2)
		{
			return x1 > x2;
		}
	};

	//Ĭ��Ϊ���//ԭ�򣺵�����ȱʡ����������less(С��)//�����С��//С���ô���
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
				//if (_con[child] > _con[parent])//�÷º�����˳��Ҫ��һ�£�����
			   if (_com(_con[parent],_con[child]))
				{
					swap(_con[child], _con[parent]);
					//��������
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
				//�ҳ����Һ��Ӵ���Ǹ�//Ĭ�����Ӵ�
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
			//�����Ѷ����β������//Ȼ����ɾ��//�����µ���
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
		//����
		priority_queue<int> q;//û�д���������������������Ĭ�ϵ�less�������˴��
		//����
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