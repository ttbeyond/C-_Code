#include"Data.h"
int Data::GetMonthDay(int year, int month)const
{
	//把数组下标为0的位置用0填补，使其从第一月开始
	static int  MonthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	//判断闰年，并将2月的天数修正为29天
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		return 29;

	return MonthDay[month];
}

//构造函数
Data::Data(int year, int month, int day)
{
	if (year >= 0 && month >= 1 && month <= 12 && day >= 1 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "非法日期" << endl;
	}
}

//拷贝构造函数
//Data d2(Data& d1)
Data::Data(const Data& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

//判断d1<=d2
//d1.operator<=(&d1,d2);
bool Data::operator<=(const Data& d)const//bool operator(Data* this,const Data& d)
{
	//if (_year < d._year)
	//	return true;
	//else if (_year == d._year && _month < d._month)
	//	return true;
	//else if (_year == d._year && _month == d._month && _day <= d._day)
	//	return true;

	//return false;

	//复用代码
	return *this < d || *this == d;
}

//d1>d2
bool Data::operator>(const Data& d)const
{
	return !(*this <= d);
}

//d1>=d2
bool Data::operator>=(const Data& d)const
{
	return !(*this < d);
}

//d1!=d2
bool Data::operator!=(const Data& d)const
{
	return !(*this == d);
}

//d+n天 日期加一个天数
Data Data::operator+(int day)const
{
	//Data ret(*this);//用d1拷贝构造一个ret
	//ret._day += day;
	//while (ret._day > GetMonthDay(ret._year, ret._month))
	//{
	//	ret._day -= GetMonthDay(ret._year, ret._month);
	//	ret._month++;
	//    if (ret._month == 13)
	//       {
	// 	       ret._year++;
	//	       ret._month = 1;
	//       }
	//}

	//return ret;

	//复用加等的代码
	Data ret(*this);//用d1拷贝构造一个ret
	ret += day;

	return ret;
}

//d+=10
//日期加等，本身要变
Data& Data::operator+=(int day)
{
	//解决加负的天数时
	if (day < 0)
	{
		return *this -= -day;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}

	return *this;
}

//日期减天数，看几天前是几号
Data& Data::operator-=(int day)
{
	//处理减负数的情况
	if (day < 0)
	{
		return *this += -day;
	}
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}

		_day += GetMonthDay(_year, _month);
	}

	return *this;
}

//日期减天数
Data Data::operator-(int day)const
{
	//Data ret(*this);
	//ret._day -= day;

	//while (ret._day < 0 )
	//{
	//	--_month;
	//	if (ret._month == 0)
	//	{
	//		ret._month = 12;
	//		ret._year--;
	//	}

	//	_day += GetMonthDay(ret._year, ret._month);
	//}

	//return ret;

	//复用减等的代码
	Data ret(*this);
	ret -= day;
	return ret;
}

//++d1
Data& Data::operator++()//默认为前置++
{
	*this += 1;
	return *this;
}

//d1++//后置++
//返回d1
Data Data::operator++(int)//为了构成函数重载的一种格式规范(加上一个形参)
{
	Data ret(*this);
	*this += 1;
	return ret;
}

//返回--之后的值
Data& Data::operator--()//默认为前置--
{
	*this -= 1;
	return *this;
}

//返回减之前的值
Data Data::operator--(int)//后置--
{
	Data tmp(*this);
	*this -= 1;
	return tmp;
}

//日期减日期
//d1-d2
//思想：让小的日期一天一天的加，直到与大的日期相等即可
//省去了相减所要的借位等逻辑思考
int Data::operator-(const Data& d)const
{
	//Data max = *this;//拷贝构造一个新的对象
	//Data min = d;
	int flag = 1;
	Data max(*this);//拷贝构造一个新的对象//默认d1大
	Data min(d);

	if (max < min)
	{
		max = d;   //operator= 赋值
		min = *this;
		flag = -1;
	}

	int n = 0;
	while (max != min)
	{
		++min;
		++n;
	}

	return n*flag;
}

//实际也是拷贝构造
Data& Data::operator=(const Data& d)
{
	if (*this != d)//针对自己给自己赋值的避免//判断条件也可写为(this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

//打印
void Data::Print()
{
	cout << _year << '-' << _month << '-' << _day << endl;
}

int main()
{
	Data d1(2020, 10, 12);
	d1.Print();

	Data d2(2020, 10, 32);
	d2.Print();

	Data d3 = d1 + 10;
	d3.Print();

	d3 = d1 - 10;
	d3.Print();

	//Data d1(2020, 10, 12);
	//Data d2(2020, 10, 31);
	//cout << d1 - d2 << endl;
	//cout << d2 - d1 << endl;


	system("pause");
	return 0;
}