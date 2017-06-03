#include<stdio.h>
int main()
{
    int t,T=1;
    scanf("%d",&t);
    while(T<=t)
    {
        long long int n,i,j,k,c=0,a[100000];
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        for(j=0;j<n-1;j++)
        {
            for(k=j+1;k<n;k++)
            {
                if(a[j]>a[k])
                {
                    c++;
                }
            }
        }
        printf("Optimal train swapping takes %lld swaps.\n",c);
        T++;
    }
    return 0;
}

