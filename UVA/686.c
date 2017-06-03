#include<stdio.h>
int main()
{
    long long int n;
    while(scanf("%lld",&n)==1)
    {
        if(n==0)
        {
            break;
        }
        long long int x=0,a,b,i,y=0,j,q[100000];
        for(a=3;a<=n;a=a+2)
        {
            if(a<=7)
            {
                q[x]=a;
                x++;
            }
            else if(a>7)
            {
                for(b=3;b<a;b=b+2)
                {
                    if(a%b==0)
                    {
                        break;
                    }
                }
                if(a==b)
                {
                    q[x]=a;
                    x++;
                }
            }
        }
        for(i=0;i<x;i++)
        {
            for(j=x-1;j>=0;j--)
            {
                if(q[i]+q[j]==n)
                {
                    y++;
                    break;
                }
            }
        }
        printf("%lld\n",(y+1)/2);
    }
    return 0;
}

