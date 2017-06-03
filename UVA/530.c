#include<stdio.h>
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0 && m==0)
        {
            break;
        }
        unsigned long long i,j,k=1,l=1,x,y,z,a,b=0;
        z=n-m;
        l=n;
        if(z>=m)
        {
            x=z;
            y=m;
        }
        else
        {
            x=m;
            y=z;
        }
        for(i=1;i<=y;i++,l--)
        {
            k=k*l;
            k=k/i;
        }
        printf("%llu\n",k);
    }
    return 0;
}

