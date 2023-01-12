#include <stdio.h> 
#include <stdlib.h>
int main()
{
    int num,sum=0;
    scanf("%d",&num);
    while(num)
    {
        sum=sum*10+num%10;  //数字反转的算法
        num/=10;
    }
    printf("%d",sum);


    system("pause");
    return 0;
}
