#include<stdio.h>
#include<math.h>
int main()
{
    long long int n,m,x,y,c;
    while(scanf("%lld",&n)!=EOF)
    {
        long long int l;
        if(n==0)
        {
            break;
        }
        l=sqrt(n);
        if(l*l==n)
        {
            if(l%2==0)
            {
                printf("%lld 1\n",l);
            }
            else if(l%2!=0)
            {
                printf("1 %lld\n",l);
            }
            continue;
        }
        m=l+1;
        c=(m*m+l*l+1)/2;
        x=y=m;
        if(m%2==0)
        {
            if(n>c)
            {
                y=y-(n-c);
            }
            else
            {
                x=x-(c-n);
            }
        }
        else
        {
            if(n>c)
            {
                x=x-(n-c);
            }
            else
            {
                y=y-(c-n);
            }
        }
        printf("%lld %lld\n",x,y);
    }
    return 0;
}
