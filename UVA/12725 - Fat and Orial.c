#include<stdio.h>
int main()
{
    long long int t,T=1,a,b;
    double n,m,i,j,k;
    scanf("%lld",&t);
    while(T<=t)
    {
        scanf("%lf %lf %lld %lld",&n,&m,&a,&b);
        i=m*(a+b);
        j=n*a;
        k=(i-j)/b;
        if(k>10.00 || k<0.00)
        {
            printf("Case #%lld: Impossible\n",T);

        }
        else
        {
            printf("Case #%lld: %0.2lf\n",T,k);
        }
        T++;
    }
    return 0;
}
