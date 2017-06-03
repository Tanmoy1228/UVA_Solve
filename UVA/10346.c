#include<stdio.h>
int main()
{
    long long int n, k;
    while(scanf("%lld %lld", &n, &k)!=EOF)
    {
        long long int j, i;
        i=n;
        while(n>=k)
        {
            j = n%k;
            n = n/k;
            i = i+n;
            n = n+j;
        }
        printf("%lld\n", i);
    }
    return 0;
}


