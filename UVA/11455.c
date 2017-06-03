#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int a,b,c,d;
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        if(a>=b+c+d || b>=a+c+d || c>=a+b+d || d>=a+b+c)
        {
            printf("banana\n");
        }
        else if(a==b && b==c && c==d && d==a)
        {
            printf("square\n");
        }
        else if((a==b && c==d) || (a==c && b==d) || (a==d && b==c))
        {
            printf("rectangle\n");
        }
        else
        {
            printf("quadrangle\n");
        }
    }
    return 0;
}
