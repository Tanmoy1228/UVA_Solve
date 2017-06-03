#include<stdio.h>
int main()
{
    long long int n, k;
    while(scanf("%lld", &n)==1)
    {
        if(n<0)
        {
            break;
        }
        else
        {
            k = n*(n+1)/2+1;
            printf("%lld\n", k);
        }
    }
    return 0;
}
