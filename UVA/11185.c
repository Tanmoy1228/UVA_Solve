#include<stdio.h>
int main()
{
    long long int n,i;
    while(scanf("%lld",&n)!=EOF)
    {
        long long int i=0,j,a[100];
        if(n<0)
        {
            break;
        }
        else
        {
            while(n>=3)
            {
                a[i]=n%3;
                n=n/3;
                i++;
            }
            a[i]=n;
            for(j=i;j>=0;j--)
            {
                printf("%lld",a[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
