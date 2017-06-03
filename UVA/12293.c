#include<stdio.h>
int main()
{
    long long int n;
    while(scanf("%lld",&n)==1)
    {
        long long int m=1,i=0,j;
        if(n==0)
        {
            break;
        }
        while(m<n)
        {
            m=2*m+1;
        }
        if(m==n)
        {
            printf("Bob\n");
        }
        else if(m>n)
        {
            printf("Alice\n");
        }
    }
    return 0;
}

