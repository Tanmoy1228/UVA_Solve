#include<stdio.h>
long long int gcd(long long int x, long long int y);
int main()
{
    long long int n;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==0)
        {
            break;
        }
        long long int i,j,G=0;
        for(i=1;i<n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                G=G+gcd(i,j);
            }
        }
        printf("%lld\n",G);
    }
    return 0;
}
long long int gcd(long long int x, long long int y)
{
    long long int a,b,c;
    c=x;
    b=y;
    while(1)
    {
        a=b%c;
        if(a==0)
        {
            break;
        }
        b=c;
        c=a;
    }
    return c;
}
