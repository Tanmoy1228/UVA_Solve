#include<stdio.h>
int main()
{
    unsigned long long n;
    while(scanf("%llu",&n)!=EOF)
    {
        unsigned long long i,fe=1,f=0,m=0,total=0;
        if(n==-1)
        {
            break;
        }
        for(i=0;i<=n;i++)
        {
            m=total;
            total=m+f+1;
            f=m;
        }
        printf("%llu %llu\n",m,total);
    }
    return 0;
}
