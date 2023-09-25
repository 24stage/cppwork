//第四题
class Date
{
private:
	int year,month,day;
public:
	Date(int y=1,int m=1,int d=1):year(y),month(m),day(d){}//构造函数
	void SetYear(int y){year=y;}//设置年
	void SetMonth(int m){month=m;}//设置月
	void SetDay(int d){day=d;}//设置日
	int GetYear() const{return year;}//返回年
	int GetMonth() const{return month;}// 返回月
	int GetDay() const{return day;}// 返回日
	Date operator+(int days);//返回当前日期加上天数后得到的日期
	Date operator-(int days);//返回当前日期减去天数后得到的日期
	static bool IsLeapyear(int y);//判断年份y是否为闰年
	static int GetYearDays(int y);//年份y地天数
	static int GetMonthDays(const Date &d);//日期d当前月份的天数
	static int DateToNum(const Date &d);//返回从公元1年1月1日起的天数
	static Date NumToDate(int n);//由公元1年1月1日起的天数返回日期
};

ostream &operator<<(ostream &out,const Date &d);//重载输出运算符<<
istream &operator>>(istream &in,const Date &d);//重载输入运算符>>

//日期类相关成员函数的实现
Date Date::operator+(int days)
{ 
	int n=DateToNum(*this)+days;//从公元1年1月1日起的天数
	return NumToDate(n);//返回日期
}
Date Date::operator-(int days)
{ 
	int n=DateToNum(*this)-days;//从公元1年1月1日起的天数
	return NumToDate(n);//返回日期
}
bool Date::IsLeapyear(int y)//判断年份y是否为闰年
{
	if(y%4==0&&y%100!=0||y%400==0) return true;
	else return false;
}

int Date::GetYearDays(int y)//年份y由多少天
{
	if(IsLeapyear(y)) return 365;
	else return 365;
}
int Date::GetMonthDays(const Date &d)//日期d当前月份的天数
{
	int n;
	switch(d.GetMonth())
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:n=31;break;
	case 4:
	case 6:
	case 9:
	case 11:n=30;break;
	case 2:
		if(IsLeapyear(d.GetYear())) n=29;
		else n=28;
	}
	return n;
}

int Date::DateToNum(const Date &d)//
{
	int y,n=0;
	for(y=1;y<d.GetYear();y++)//累加从公元1年到year-1年的天数
		n=n+GetYearDays(y);
	for(int m=1;m<d.GetMonth();m++)//累加日期中从1月到month-1月的天数
	n=n+GetMonthDays(Date(y,m,1));
	n=n+d.GetDay();//累加当前月中已过的天数
	return n;
}

Date Date::NumToDate(int n)//由公元1年1月1日期的天数返回日期
{
	int y,m,d,rest=n;//年,月,日和剩余的天数
	for(y=1,rest=n;rest>GetYearDays(y);y++)//计算年份
	rest=rest-GetYearDays(y);//计算年份
	for(m=1;rest>GetMonthDays(Date(y,m,1));m++)//计算月份
		rest=rest-GetMonthDays(Date(y,m,1));
	d=rest;//日
	return Date(y,m,d);//返回日期
}

ostream &operator<<(ostream &out,const Date &d)//重载输出运算符
{out<<d.GetYear()<<"年"<<d.GetMonth()<<"月"<<d.GetDay()<<"日";//输出年月日
return out;}

istream &operator>>(istream &in, Date &d)//重载输出运算符
{
	int year,month,day;
	in>>year>>month>>day;
	d=Date(year,month,day);
	return in;
}
int main(void)
{
	Date d(2022,10,10);
	cout<<"日期:"<<d<<endl;//输出日期
	cout<<"日期+30:"<<d+30<<endl;//输出日期
	cout<<"日期-30:"<<d-30<<endl;//输出日期
	cout<<"输入日期:";
	cin>>d;
	cout<<"日期:"<<d<<endl;//输出日期
}




//第五题
#include <iostream>
using namespace std;

class Time 
{
private:
	int hour,minute,sec;
	int total_sec;
	
	
public:
    Time(int h=0,int m=0,int s=0):hour(h),minute(m),sec(s){}
    int gethour() const{return hour;}
	int getminute() const{return minute;}
	int getsec() const{return sec;}

	void total_num();   //计算总秒数
	void caculate();    //总秒数返回时间
	Time operator +(const Time &t);
	Time operator -(const Time &t);
	void show()
    {
        cout<<hour<<":"<<minute<<":"<<sec<<endl;
    }
	
};

ostream &operator<<(ostream &out,const Time &t);//重载输出运算符<<
istream &operator>>(istream &in,const Time &t);//重载输入运算符>>

void Time::total_num()
{
	total_sec=hour*3600+minute*60+sec;
}
Time Time::operator +(const Time &t)
{
	Time tt;
	tt.total_sec=this->total_sec+t.total_sec;
	return tt;
}
Time Time::operator -(const Time &t) 
{
	Time ti;
	ti.total_sec=this->total_sec-ti.total_sec;
	return ti;
}
void Time:: caculate()
{
	hour=total_sec/3600;
	minute=(total_sec-hour*3600)/60;
	sec=total_sec%60;
}

ostream &operator<<(ostream &out,const Time &t)//重载输出运算符
{
    out<<t.gethour()<<"时"<<t.getminute()<<"分"<<t.getsec()<<"秒";
    return out;
}

istream &operator>>(istream &in, Time &t)//重载输出运算符
{
	int hour,minute,sec;
	in>>hour>>minute>>sec;
	t=Time(hour,minute,sec);
	return in;
}

int main()
{
    Time t1(12,23,33),t2(13,33,44),t3;
    t1.total_num();
    t2.total_num();
    t3=t1+t2;
    t3.caculate();
    cout<<t1<<endl<<t2<<endl<<"t1+t2:"<<t3<<endl;
    cin>>t2;
    cout<<t2<<endl;


return 0;	
}

