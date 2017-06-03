#include<stdio.h>
int main()
{
    long long int n,m,x,y,i,j,z,c,ma;
    while(scanf("%lld %lld",&n,&m)!=EOF)
    {
        if(n==0 && m==0)
        {
            break;
        }
        if(n>m)
        {
            x=n;
            y=m;
        }
        else
        {
            x=m;
            y=n;
        }
        ma=0;
        for(i=y;i<=x;i++)
        {
            z=i;
            c=0;
             if(z==1)
                c=3;
            while(z!=1)
            {
                if(z%2==0)
                {
                    z=z/2;
                    c++;
                }
                else
                {
                    z=3*z+1;
                    c++;
                }
            }
            if(c>ma)
            {
                ma=c;
                j=i;
            }
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",y,x,j,ma);
    }
    return 0;
}
