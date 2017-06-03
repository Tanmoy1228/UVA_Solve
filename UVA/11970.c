#include<stdio.h>
#include<math.h>
int main()
{
    int t=1,T;
    scanf("%d",&T);
    while(t<=T)
    {
        long long int n,j=0,k,i,l,m;
        int a[100];
        scanf("%lld",&n);
        printf("Case %d: ",t);
        m=sqrt(n);
        for(i=sqrt(n);i>0;i--)
        {
            if((i*i==n-i) && (i%l==0))
            {
                a[j]=i;
                j++;
            }
        }
        for(k=0;k<j-1;k++)
        {
            printf("%d ",a[k]);
        }
        printf("%d\n",a[k]);
        t++;
    }
    return 0;
}
