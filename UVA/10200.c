#include<stdio.h>
#include<math.h>
bool a[100020000];
int main()
{
    long long int n=100020000,i,j,c=0,x,y,k,l;

    for(i=4;i<=n;i++)
    {
        check[i]=false;
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                check[i]=true;
                break;
            }
        }
    }
    while(scanf("%lld %lld",&x,&y)!=EOF)
    {
        double v;
        long long int z=0;
        for(k=x;k<=y;k++)
        {
            if(a[(k*k+k+41)]==false)
            {
                z++;
            }
        }
        v=(double)(1.0*(z*100)/(y-x+1));
        printf("%0.2lf\n",v);
        break;
    }
    return 0;
}
