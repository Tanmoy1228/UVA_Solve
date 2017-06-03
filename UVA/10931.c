#include<stdio.h>
int main()
{
    long long int n;
    while(scanf("%lld",&n)==1)
    {
        long long int i,j=0,k,l,m=0,a[10000],b[10000];
        if(n==0)
        {
            break;
        }
        while(n>0)
        {
            a[j]=n%2;
            j++;
            n=n/2;
        }
        for(k=0;k<j;k++)
        {
            b[k]=a[j-1-k];
        }
        printf("The parity of ");
        for(l=0;l<k;l++)
        {
            if(b[l]==1)
            {
                m++;
            }
            printf("%lld",b[l]);
        }
        printf(" is %lld (mod 2).\n",m);
    }
    return 0;
}
