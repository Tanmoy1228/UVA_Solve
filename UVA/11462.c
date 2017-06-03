#include<stdio.h>
long long int a[2000099],b[100];
int main()
{
    unsigned long long n;
    while(scanf("%llu",&n)!=EOF)
    {
        if(n==0)
        {
            break;
        }
        unsigned long long i,j,k;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        for(j=1;j<=100;j++)
        {
            b[j]=0;
        }
        for(j=1;j<=100;j++)
        {
            for(i=0;i<n;i++)
            {
                if(a[i]==j)
                {
                    b[j]++;
                }
            }
        }
        for(j=1;j<=100;j++)
        {
            if(b[j])
            {
                for(k=1;k<=b[j];k++)
                {
                    printf("%llu ",j);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
