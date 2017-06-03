#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        unsigned long long int a,n,b,x,c,d=0;
        scanf("%llu",&n);
        x=n;
        while(1)
        {
            c=0;
            while(n>0)
            {
                a=n%10;
                b=c*10;
                c=a+b;
                n=n/10;
            }
            if(x==c)
            {
                printf("%llu %llu\n",d,c);
                break;
            }
            n=x+c;
            x=x+c;
            d++;
        }
    }
    return 0;
}
