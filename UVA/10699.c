#include<stdio.h>
#include<math.h>
int main()
{
    long long int n,i,x,c,j;
    while(scanf("%lld",&n)!=EOF)
    {
        c=1;
        x=n;
        if(n==0)
        {
            break;
        }
        else
        {
            for(i=2;i<=sqrt(n);i++)
            {
                j=0;
                while(n%i==0)
                {
                    n=n/i;
                    j=1;
                }
                if(j==1)
                {
                    c++;
                }
            }
            printf("%lld : %lld\n",x,c);
        }
    }
    return 0;
}
