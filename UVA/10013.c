#include<stdio.h>
long long int a[2100000];
char s[2100000];
int main()
{
    long long int t,n,m,k,i;
    scanf("%lld",&t);
    while(t--)
    {
        long long int x=0,b=0,y,j=0;
        scanf("%lld",&k);
        for(i=0;i<k;i++)
        {
            scanf("%lld %lld",&n,&m);
            a[j]=n;
            j++;
            a[j]=m;
            j++;
        }
        for(i=j-1;i>=0;i=i-2)
        {
            x=a[i]+a[i-1]+x;
            y=x%10;
            s[b]=y+'0';
            b++;
            x=x/10;
        }
        for(i=b-1;i>=0;i--)
        {
            printf("%c",s[i]);
        }
        printf("\n");
        if(t>0)
        {
            printf("\n");
        }
    }
    return 0;
}
