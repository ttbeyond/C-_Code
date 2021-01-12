#include<iostream>
using namespace std;

class Data
{
public:
	int GetMonthDay(int year, int month)const;
	//构造函数
	Data(int year = 0, int month = 1, int day = 1);

	//拷贝构造函数
	//Data d2(Data& d1)
	Data(const Data& d);

	//比较俩个日期的大小
	//d1<d2
	//实际编译器会将上边的代码转换为：d1.operator<(&d1,d2)
	//bool operator<(Data* this,const Data& d2)//下边的d相当于此处的d2，this指针指向d1
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

	//判断俩个日期是否相等
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
	Data operator-(int day)const;//几天前的日期
	Data& operator++();//默认为前置++
	Data operator++(int);//为了构成函数重载的一种格式规范(加上一个形参)

	Data& operator--();//默认为前置--
	Data operator--(int);//后置--
	int operator-(const Data& d)const;//日期减日期
	Data& operator=(const Data& d);
	void Print();
private:
	int _year;
	int _month;
	int _day;
};
