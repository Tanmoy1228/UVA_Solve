#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    int i;
    for(i=1; i<=t; i++)
    {
        long long int a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        if((a+b>c) && (b+c>a) && (c+a>b))
        {
            if((a==b) && (b==c) && (c==a))
            {
                printf("Case %d: Equilateral\n", i);
            }
            else if((a==b) || (b==c) || (c==a))
            {
                printf("Case %d: Isosceles\n", i);
            }
            else if((a!=b) && (b!=c) && (c!=a))
            {
                printf("Case %d: Scalene\n", i);
            }
        }
        else
        {
            printf("Case %d: Invalid\n", i);
        }
    }
    return 0;
}
