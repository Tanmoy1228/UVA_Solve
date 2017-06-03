#include<stdio.h>
int main()
{
    long long int a, b, c;
    while(scanf("%lld %lld %lld", &a, &b, &c)==3)
    {
        if(a==0 || b==0 || c==0)
        {
            break;
        }
        else if(((a*a) == (b*b + c*c)) || ((b*b) == (a*a + c*c)) || ((c*c) == (a*a + b*b)))
        {
            printf("right\n");
        }
        else
        {
            printf("wrong\n");
        }
    }
    return 0;
}
