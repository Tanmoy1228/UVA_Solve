#include<stdio.h>
int main()
{
    unsigned long long n;
    while(scanf("%llu",&n)!=EOF)
    {
        unsigned long long a,c,t;
        if(n==0)
        {
            break;
        }
        while(1)
        {
             t=n;
             c=0;
             while(t>0)
             {
                 a=t%10;
                 t=t/10;
                 c=c+a;
             }
             n=c;
             if(n<10)
             {
                 printf("%llu\n",n);
                 break;
             }
        }
    }
    return 0;
}
