#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,m;
        scanf("%lld %lld",&n,&m);
        printf("%lld\n",(n/3)*(m/3));
    }
    return 0;
}
