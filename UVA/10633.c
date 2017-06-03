#include<stdio.h>
int main()
{
    unsigned long long n;
    while(scanf("%llu",&n)==1)
    {
        unsigned long long x;
        if(n==0)
        {
            break;
        }
        else if(n<9)
        {
            printf("%llu\n",n);
        }
        else if(n>=9)
        {
            x=(n*10)/9;
            if(n%9==0)
            {
                printf("%llu %llu\n",x-1,x);
            }
            else
            {
                printf("%llu\n",x);
            }
        }
    }
    return 0;
}
