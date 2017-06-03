#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000],a[1000];
    while(gets(s))
    {
        int l,i,j;
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            a[i]=s[i]-7;
        }
        for(j=0;j<l;j++)
        {
            printf("%c",a[j]);
        }
        printf("\n");
    }
    return 0;
}
