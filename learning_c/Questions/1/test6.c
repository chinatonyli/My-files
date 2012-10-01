#include<stdio.h>
#include<string.h>
#define size 50
void Intersection(char* dest,char* str1,char* str2)//dest是目标串，用以放后两个串元素的交集
{
    int i,j,k,m=0,flag=0;
    int len1=strlen(str1),len2=strlen(str2);
    for(i=0;i<len1;i++)
    {
        for(j=0;j<len2;j++)
        {
            if(str2[j]==str1[i])   //如果str2中有str1的元素，置flag为 1
            {
                flag=1;
                break;
            }
        }
        for(k=0;k<strlen(dest);k++)
            if(str1[i]==dest[k])   //如果该元素已在dest中出现，置flag为 0
            {
                 flag=0;
                 break;
            }

        if(flag)   //如果flag为1，把该元素放在目标串中
        {
            dest[m++]=str1[i];
            str2[j]=str2[--len2];//为了减少循环次数，可以把str2中的末一个元素放在str2[j]中，并把len2自减1，此步不必要
        }

        flag=0;
    }

}
int main()//测试一下
{
    char str1[size],str2[size],dest[size]="";
    puts("请输入两个字符串：");
    gets(str1);
    gets(str2);

    Intersection(dest,str1,str2);
    puts("两个串中元素的交集是：");
    puts(dest);
    return 0;
}
