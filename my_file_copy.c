#include <stdio.h>
#include <stdlib.h>
int main()
{
    int c;
    FILE *pf1,*pf2;
    char name1[80]={"D:\\ctest\\my_file1.txt"},name2[80]={"D:\\ctest\\my_file2.txt"};
   // gets(name1);                                                                                                                                                        
   // gets(name2);
    if((pf1=fopen(name1,"r"))==NULL)
    {
        printf("error");
        exit(0);
    }
    if((pf2=fopen(name2,"w"))==NULL)
    {
        printf("error");
        exit(0);
    }
    while(!feof(pf1))       //一个问题：用(c=fgetc(pf1))!=EOF会出现乱码
    {
        c=fgetc(pf1);
        fputc(c,pf2);
    }
    fclose(pf1);
    fclose(pf2);

    system("pause");
    return 0;
}
