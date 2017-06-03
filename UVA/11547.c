#include<stdio.h>
#include<math.h>
int main()
{
    int t=1,T;
    scanf("%d",&T);
    while(t<=T)
    {
        long long int n,a,b;
        scanf("%lld",&n);
        a=(n*63+7492)*5-498;
        a=fabs(a);
        b=(a/10)%10;
        printf("%lld\n",b);
        t++;
    }
    return 0;
}
