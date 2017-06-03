#include<stdio.h>
long long int fun(long long int a);
int main()
{
    int t=1,T;
    scanf("%d",&T);
    while(t<=T)
    {
        long long int n,x,i,j=0,k,z=0;
        int a[10000];
        scanf("%lld",&n);
        x=n;
        i=n;
        while(i>0)
        {
            i=fun(i);
            a[j]=i;
            if(i==1)
            {
                printf("Case #%d: %lld is a Happy number.\n",t,x);
                break;
            }
            else if(i==n)
            {
                printf("Case #%d: %lld is an Unhappy number.\n",t,x);
                break;
            }
            else
            {
                for(k=0;k<j;k++)
                {
                    if(a[k]==i)
                    {
                        printf("Case #%d: %lld is an Unhappy number.\n",t,x);
                        z=1;
                        break;
                    }
                }
            }
            j++;
            if(z==1)
                break;
        }
        t++;
    }
    return 0;
}
long long int fun(long long int a)
{
    long long int b,c,d=0;
    while(a>0)
    {
        b=a%10;
        c=b*b;
        d=d+c;
        a=a/10;
    }
    return d;
}
