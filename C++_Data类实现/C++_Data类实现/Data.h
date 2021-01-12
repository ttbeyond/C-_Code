#include<iostream>
using namespace std;

class Data
{
public:
	int GetMonthDay(int year, int month)const;
	//���캯��
	Data(int year = 0, int month = 1, int day = 1);

	//�������캯��
	//Data d2(Data& d1)
	Data(const Data& d);

	//�Ƚ��������ڵĴ�С
	//d1<d2
	//ʵ�ʱ������Ὣ�ϱߵĴ���ת��Ϊ��d1.operator<(&d1,d2)
	//bool operator<(Data* this,const Data& d2)//�±ߵ�d�൱�ڴ˴���d2��thisָ��ָ��d1
	inline bool operator<(const Data& d)const
	{
		if (_year < d._year)
			return true;
		else if (_year == d._year && _month < d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day < d._day)
			return true;

		return false;
	}

	//�ж����������Ƿ����
	inline bool operator==(const Data& d)const
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}
	bool operator<=(const Data& d)const;//bool operator(Data* this,const Data& d)
	bool operator>(const Data& d)const;
	bool operator>=(const Data& d)const;
	bool operator!=(const Data& d)const;

	Data operator+(int day)const;
	Data& operator+=(int day);
	Data& operator-=(int day);
	Data operator-(int day)const;//����ǰ������
	Data& operator++();//Ĭ��Ϊǰ��++
	Data operator++(int);//Ϊ�˹��ɺ������ص�һ�ָ�ʽ�淶(����һ���β�)

	Data& operator--();//Ĭ��Ϊǰ��--
	Data operator--(int);//����--
	int operator-(const Data& d)const;//���ڼ�����
	Data& operator=(const Data& d);
	void Print();
private:
	int _year;
	int _month;
	int _day;
};
