#include<stdio.h>
int main()
{
    long long int n=2000,i,j,k,l,m,a[100000];
    m=sqrt(n);
    for(i=4;i<n;i=i+2)
    {
        a[i]=1;
    }
    for(i=3;i<m;i++)
    {
        for(j=i*i;j<n;j=j+i)
        {
            a[j]=1;
        }
    }
    for(i=1;i<n;i++)
    {
        if(a[i]!=1)
        {
            printf("%lld   ",i);
        }
    }
    return 0;
}
