#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int a,b,c,d,i,j=0;
        scanf("%lld %lld %lld",&a,&b,&c);
        d=a+b;
        while(d>=c)
        {
            i=d/c;
            d=(d%c)+i;
            j=j+i;
        }
        d=d+1;
        printf("%lld\n",j);

    }
    return 0;
}
