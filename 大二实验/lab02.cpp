//2(1)
#include <iostream>

using namespace std;


class Point
{
private:
    int x,y;

public:
    Point(int a, int b):x(a),y(b){}
    void set(int a,int b);
    int getx() const{return x;}     //const修饰成员函数，防止该函数修改成员函数
    int gety() const{return y;}


};
void Point::set(int a,int b)
{
    x = a;
    y = b;
}
void show(const Point &pt)
{
    cout<<pt.getx()<<" "<<pt.gety()<<endl;

}
int main()
{
    Point a[5]=
    {
        Point(0,0),
        Point(1,1),
        Point(2,2),
        Point(3,3),
        Point(4,4)
    };
    Point *p=a;
    p->set(5,9);
    a[3].set(6,8);
    for(int i=0;i<5;i++)
    {
        show(*p++);
    }

    return 0;

}




//2(2)
#include <iostream>
using namespace std;
class Date
{
private:
    int month,day,year;
public:
    Date(int m=1,int d=1,int y=2022);

    friend void show(const Date &p);

};
Date::Date(int m,int d,int y)
{
    this->month = m;
    this->day = d;
    this->year = y;

}
void show(const Date &p)
{
    cout<<p.month<<"/"<<p.day<<"/"<<p.year<<endl;

}


int main()
{
    Date d1(6,8,2008),d2(6,18),d3(5),d4;
    show(d1);
    show(d2);
    show(d3);
    show(d4);
    
    return 0;

}


//2(3)
#include <iostream>
using namespace std;
class Test 
{
private:
    static int count;
public:
    Test(){count++;}
    static void show() {cout<<"共有"<<count<<"个对象"<<endl;}

};

int Test::count=0;

int main()
{
    Test obj1,obj2,obj3;
    Test::show();

    return 0;
}


//2(4)
/*
#include <iostream>
using namespace std;

class Test
{
public:
    Test(){cout<<"构造函数"<<endl;}
    ~Test(){cout<<"析构函数"<<endl;}


};

void print()
{
    Test obj;
}

int main()
{
    //Test obj;
    print();

    return 0;
}
*/

//2(5)
#include <iostream>
using namespace std;
class People
{
private:
    int age;
    static int num;
    double height,weight;

public:
    People(int a,double h,double w) : age(a),height(h),weight(w){}
    void eatting(){weight+1.0;}
    void sport(){height+1.0;}
    void sleep()
    {
        age+=1.0; 
        weight+=1.0;
        height+=1.0;
    }

    void show()
    {
        cout<<age<<"岁"<<height<<"公斤"<<weight<<"cm"<<endl;
    }

    static void shownum();
};

int People::num=3;
void People::shownum()
{
    cout<<num<<"个人"<<endl;
}



int main()
{
    int n=3;
    People peo[3]={         //此处为什么不能用n代替3？？？
        People(17,170.0,55.0),
        People(18,171.1,62.1),
        People(19,173.2,55.0)
    };
    People *p=peo;
    People::shownum();
    for(int i=0;i<n;i++)
    {
        peo[i].show();
        peo[i].eatting();
        peo[i].sleep();
        peo[i].sport();
        peo[i].show();

    }

    return 0;
}