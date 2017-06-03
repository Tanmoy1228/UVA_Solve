#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,a[10000],i,j,k,c=0,l;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[i]>a[j])
                {
                    k=a[i];
                    a[i]=a[j];
                    a[j]=k;
                }
            }
        }
        if(n%2==0)
        {
            l=n/2;
        }
        else
        {
            l=(n-1)/2;
        }
        for(i=0;i<n;i++)
        {
            c=c+fabs(a[i]-a[l]);
        }
        printf("%d\n",c);
    }
    return 0;
}
