#include<stdio.h>
int main()
{
    long long int n;
    while(scanf("%lld",&n)!=EOF)
    {
        long long int a=1,b,c=0;
        if(n==0)
        {
            printf("0\n");
            continue;
        }
        while(n>1)
        {
            if(n==3)
            {
                c++;
                n=(n-1)/2;
            }
            else if(n%2==0)
            {
                n=n/2;
            }
            else
            {
                if((n+1)%4==0)
                {
                    c++;
                    n=(n+1)/2;
                }
                else if((n-1)%4==0)
                {
                    c++;
                    n=(n-1)/2;
                }
            }
            c++;
        }
        printf("%lld\n",c+1);

    }
    return 0;
}
