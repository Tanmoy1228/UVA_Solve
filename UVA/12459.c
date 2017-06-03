#include<stdio.h>
int main()
{
    long long int n;
    while(scanf("%lld",&n)==1)
    {
        long long int i,m=1,f=0,l,t;
        if(n==0)
        {
            break;
        }
        for(i=1;i<=n;i++)
        {
            l=f;
            f=m+f;
            m=l;
            t=m+f;
        }
        printf("%lld\n",t);
    }
    return 0;
}
