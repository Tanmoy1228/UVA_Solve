#include<stdio.h>
#include<math.h>
int main()
{
    long long int n;
    while(scanf("%lld",&n)==1)
    {
        long long int i,x,j,y=0,a,b,c=0;
        x=n;
        if(n==2 || n==1)
        {
            printf("%lld is prime.\n",n);
            continue;
        }
        for(i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                printf("%lld is not prime.\n",n);
                y=1;
                break;
            }
        }
        if(y==1)
        {
            continue;
        }
        else if(n<12)
        {
            printf("%lld is prime.\n",n);
            continue;
        }
        else if(i>sqrt(n))
        {
            while(x>0)
            {
                a=x%10;
                x=x/10;
                b=c*10;
                c=a+b;
            }
            if(c==n)
            {
                printf("%lld is prime.\n",n);
                continue;
            }
            for(j=2;j<=sqrt(c);j++)
            {
                if(c%j==0)
                {
                    printf("%lld is prime.\n",n);
                    break;
                }
            }
            if(j>sqrt(c))
            {
                printf("%lld is emirp.\n",n);
            }
        }
    }
    return 0;
}
