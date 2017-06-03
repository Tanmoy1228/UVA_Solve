#include<stdio.h>
int main()
{
    long long int n;
    while(scanf("%lld",&n)==1)
    {
        unsigned long long a;
        if(n<0)
        {
            break;
        }
        else if(n==1)
        {
            printf("0%%\n");
            continue;
        }
        else
        {
            a=25*n;
            printf("%llu%%\n",a);
        }
    }
    return 0;
}
