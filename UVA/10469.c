#include<stdio.h>
#include<math.h>
int main()
{
    unsigned long long n,m;
    while(scanf("%llu %llu",&n,&m)!=EOF)
    {
        if(n<0 || m<0)
        {
            break;
        }
        int a[1000],b[1000],c[1000],i,j,x,y,z,d=0;
        for(i=0;i<32;i++)
        {
            a[i]=0;
            b[i]=0;
        }
        while(n>0 || m>0)
        {
            x=n%2;
            y=m%2;
            a[i-1]=x;
            b[i-1]=y;
            i--;
            n=n/2;
            m=m/2;
        }
        for(j=31;j>=0;j--)
        {
            z=a[j]+b[j];
            if(z<2)
            {
                c[j]=z;
            }
            else
            {
                c[j]=0;
            }
        }
        for(i=0;i<32;i++)
        {
            d=c[i]*pow(2,(31-i))+d;
        }
        printf("%d\n",d);
    }
    return 0;
}
