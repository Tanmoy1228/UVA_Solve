#include<stdio.h>
#include<math.h>
int main()
{
    long long int n;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==0)
        {
            break;
        }
        long long int i,c=0;
        for(i=1;i<=n;i++)
        {
            c=c+pow(i,2);
        }
        printf("%lld\n",c);
    }
    return 0;
}
