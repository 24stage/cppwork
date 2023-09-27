//5(1)
#include <iostream>
using namespace std;

template <class Elemtype>
Elemtype f(Elemtype x)
{
	Elemtype y;
	y=x*(Elemtype)5.8;
	return y;
}

int main()
{
	cout<<f(5)<<endl;
	cout<<f(5.0)<<endl;
	cout<<f<int>(5.0)<<endl;

	return 0;
}

//5(2)
#include <iostream>
using namespace std;

void show_max(int a,int b)
{
	int max=(a>b)?a:b;
	cout<<"调用int,maxvalue="<<max<<endl;

}
void show_max(double a,double b)
{
	double max=(a>b)?a:b;
	cout<<"调用double,maxvalue="<<max<<endl;

}
template<class elemtype1,class elemtype2>
void show_max(elemtype1 a,elemtype2 b)
{
	elemtype1 max=(a>(elemtype1)b)?a:(elemtype1)b;
	cout<<"调用函数模板,maxvalue="<<max<<endl;
}
int main()
{
	show_max(16,518);
	show_max(16.0,518.0);
	show_max(16.0,518);
	show_max(16,518.0);

	return 0;
}

//5(3)
#include <iostream>
using namespace std;

class A{
private:
	int a;
public:
	A(int x):a(x){}
	virtual void Show() const {cout<<a;}
};
template <class ElemType>
class B:public A
{
private:
	ElemType b;
public:
	B(int x,ElemType y):A(x),b(y){}
	void Show() const {
		A::Show();
		cout<<" "<<b<<endl;}
};

int main()
{
	B<char*>obj(8,"is my happy digit!");
	obj.Show();
	return 0;
}

//5(4)
#include <iostream>
using namespace std;
template<class ElemType>

ElemType Max(ElemType a, ElemType b)
{
	return (a>b)?a:b;//求a和b的最大值
}
int main()
{
	cout<<Max(16,518)<<endl;
	cout<<Max(16.8,518.0)<<endl;
	return 0;
}

//5(5)来喽
#include <iostream>
using namespace std;
template<class T>
class Array
{
private:
	T *array_f;
	int size;

public:
	Array(T a[],int s):array_f(a),size(s){}
	T max();
	T sum();
	void sort();	//排序
	void show();

};

template<class T>	//在类外定义成员函数需要重新声明模板
T Array<T>::max()
{
	T maxnum=array_f[0];
	for(int i=0;i<size;i++)
	{
		if(maxnum<array_f[i])
			maxnum=array_f[i];
	}
	return maxnum;
}

template<class T>
T Array<T>::sum()
{
	T sumnum=0;
	for(int i=0;i<size;i++)
		sumnum+=array_f[i];
	return sumnum;
}
template<class T>
void Array<T>::sort()	//冒泡排序
{
	int count=0;
	for(int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-1-i;j++)
		{
			if(array_f[j]>array_f[j+1])
			{
				T tem;
				tem=array_f[j];
				array_f[j]=array_f[j+1];
				array_f[j+1]=tem;
				count=1;
			}
		}
		if(count==0)	//如果某一次没有交换任何位置，说明已经排序完成
			break;
	}

}

template<class T>
void Array<T>::show()
{
	for(int i=0;i<size;i++)
		cout<<array_f[i]<<" ";
	cout<<endl;

}

int main()
{
	int a[]={6,2,1,4,5,3};
	Array<int>obj(a,6);
	cout<<"原数组：";
	obj.show();
	cout<<"最大值:"<<obj.max()<<endl;
	cout<<"元素和"<<obj.sum()<<endl;
	cout<<"排序后结果：";
	obj.sort();
	obj.show();


	return 0;
}

