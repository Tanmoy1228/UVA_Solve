#include<stdio.h>
#define mx 100000
long long int b[mx];
int main()
{
    long long int n,a[]={1,5,10,25,50},i,j,k;

    b[0]=1;
    for(i=0; i<5; i++)
    {
        for(j=a[i],k=0; j<=7489; j++,k++)
        {
            b[j]=b[j]+b[k];
        }
    }
    while(scanf("%lld",&n)!=EOF)
    {
        printf("%lld\n",b[n]);
    }
    return 0;
}
