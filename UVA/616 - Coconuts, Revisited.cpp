#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    long long int n,m,a,i,j,found;
    while(scanf("%lld",&n) && n>0)
    {
        m=sqrt(n)+1;
        found=0;
        for(i=m; i>0; i--)
        {
            a=n;
            for(j=0; j<i && a%i==1; j++)
            {
                a=a-1-a/i;
            }
            if(j==i && a%i==0)
            {
                found=1;
                break;
            }
        }
        if(found==0)
            printf("%lld coconuts, no solution\n",n);
        else
            printf("%lld coconuts, %lld people and 1 monkey\n",n,i);
    }
    return 0;
}
