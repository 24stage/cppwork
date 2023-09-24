/*3(1)

#include <iostream>
using namespace std;

class A
{
public:
    A(){cout<<"构造A"<<endl;}
    ~A(){cout<<"析构A"<<endl;}

};

class B:public A
{
public:
    B(){cout<<"构造B"<<endl;}
    ~B(){cout<<"析构B"<<endl;}
};

class C:public B
{
public:
    C(){cout<<"构造C"<<endl;}
    ~C(){cout<<"析构C"<<endl;}
};

int main()
{
    C obj;
    return 0;
}
//3(2)
#include <iostream>
using namespace std;

class A
{
protected:
    int a;
public:
    A(int x):a(x){}
    void show() const{cout<<a<<endl;}

};

class B
{
protected:
    int b;
public:
    B(int x):b(x){}
    void show() const{cout<<b<<endl;}
};

class C:public A,public B
{
public:
    C(int x,int y):A(x),B(y){}
    void show() const {cout<<a<<","<<b<<endl;}
};

int main()
{
    C obj(5,18);
    obj.show();
    obj.A::show();
    obj.B::show();
    

    return 0;
};
//3(3)
#include <iostream>
using namespace std;

class A
{
private:
    int a;
public:
    A(int x):a(x){}
    void show() const{cout<<a<<endl;}

};

class B:public A
{
protected:
    int b;
public:
    B(int x,int y):A(x),b(y){}
    void show() const 
    {
        A::show();
        cout<<b<<endl;

    }
};


int main()
{
    B obj(5,18);
    obj.show();

    return 0;
};


3(4)
#include <iostream>//预处理命令
using namespace std;//使用标准命名空间std

class Base
{
private:
	//数据成员：
	int m;
public:
	//公有函数
	Base(int a):m(a){}//构造函数
	Base(const Base &copy):m(copy.m){}//复制构造函数
	void Show() const{cout<<"m:"<<m<<endl;}//显示m的值
};

//派生类Derived
class Derived:private Base
{
protected:
	//数据成员：
	int n;
public:
	//公有函数
	Derived(int a,int b):Base(a){n=b;}//构造函数
	void Show() const
	{
		Base::Show();//调用基类Base的成员函数Show()
		cout<<"n:"<<n<<endl;//显示n的值
	}
};

int main(void)//主函数main(void)
{
	Derived obj(10,18);//定义对象
	obj.Show();
	

	return 0;
}


3(5)
#include <iostream>
#include <string>
using namespace std;

class Person 
{
protected:
    int age;
    string name;
    string sex;
public:
    Person(int a,const string &n,const string &s):age(a),name(n),sex(s){}
    void show()
    {
        cout<<"age:"<<age<<endl;
        cout<<"naem:"<<name<<endl;
        cout<<"sex:"<<sex<<endl;
    }
};

class Teacher:public Person
{
protected:
    string title;
public:
    Teacher(int a,const string &n,const string &s,const string &t):Person(a,n,s),title(t){}
    void show()
    {
        Person::show();
        cout<<"title:"<<title<<endl;

    }
};
class Cadre:public Person
{
protected:
    string post;
public:
    Cadre(int a,const string &n,const string &s,const string &p):Person(a,n,s),post(p){}
     void show()
    {
        Person::show();
        cout<<"post:"<<post<<endl;

    }
};

class TeacherCardre :public Teacher,public Cadre
{
private:
    int wages;
public:
    TeacherCardre(int a,const string &n,const string &s,const string &t,const string &p,int w):Teacher(a,n,s,t),Cadre(a,n,s,p),wages(w){}//此处Cadre也必须包含a,n,s
    void show()
    {
        Teacher::show();
        cout<<"title:"<<Cadre::post<<endl;
        cout<<"wages:"<<wages<<endl;
    
    }
};
int main()
{
    TeacherCardre obj{18,"Bob","male","教师","语文",8000};
    obj.show();


    return 0;
}










*/
