#include"Data.h"
int Data::GetMonthDay(int year, int month)const
{
	//�������±�Ϊ0��λ����0���ʹ��ӵ�һ�¿�ʼ
	static int  MonthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	//�ж����꣬����2�µ���������Ϊ29��
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		return 29;

	return MonthDay[month];
}

//���캯��
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
		cout << "�Ƿ�����" << endl;
	}
}

//�������캯��
//Data d2(Data& d1)
Data::Data(const Data& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

//�ж�d1<=d2
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

	//���ô���
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

//d+n�� ���ڼ�һ������
Data Data::operator+(int day)const
{
	//Data ret(*this);//��d1��������һ��ret
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

	//���üӵȵĴ���
	Data ret(*this);//��d1��������һ��ret
	ret += day;

	return ret;
}

//d+=10
//���ڼӵȣ�����Ҫ��
Data& Data::operator+=(int day)
{
	//����Ӹ�������ʱ
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

//���ڼ�������������ǰ�Ǽ���
Data& Data::operator-=(int day)
{
	//��������������
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

//���ڼ�����
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

	//���ü��ȵĴ���
	Data ret(*this);
	ret -= day;
	return ret;
}

//++d1
Data& Data::operator++()//Ĭ��Ϊǰ��++
{
	*this += 1;
	return *this;
}

//d1++//����++
//����d1
Data Data::operator++(int)//Ϊ�˹��ɺ������ص�һ�ָ�ʽ�淶(����һ���β�)
{
	Data ret(*this);
	*this += 1;
	return ret;
}

//����--֮���ֵ
Data& Data::operator--()//Ĭ��Ϊǰ��--
{
	*this -= 1;
	return *this;
}

//���ؼ�֮ǰ��ֵ
Data Data::operator--(int)//����--
{
	Data tmp(*this);
	*this -= 1;
	return tmp;
}

//���ڼ�����
//d1-d2
//˼�룺��С������һ��һ��ļӣ�ֱ������������ȼ���
//ʡȥ�������Ҫ�Ľ�λ���߼�˼��
int Data::operator-(const Data& d)const
{
	//Data max = *this;//��������һ���µĶ���
	//Data min = d;
	int flag = 1;
	Data max(*this);//��������һ���µĶ���//Ĭ��d1��
	Data min(d);

	if (max < min)
	{
		max = d;   //operator= ��ֵ
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

//ʵ��Ҳ�ǿ�������
Data& Data::operator=(const Data& d)
{
	if (*this != d)//����Լ����Լ���ֵ�ı���//�ж�����Ҳ��дΪ(this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

//��ӡ
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