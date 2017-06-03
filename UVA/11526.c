#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,i,j,k,w,x,a,b,c=0;
        scanf("%lld",&n);
        if(n<=0)
        {
            printf("0\n");
            continue;
        }
        x=n;
        k=sqrt(n);
        w=k+1;
        for(i=1; i<k; i++)
        {
            j=i+1;
            x=x+(n/j)+(((n/i)-(n/j))*i);
        }
        if((n/k)==k)
        {
            printf("%lld\n",x);
        }
        else if((w*w)-n==1)
        {
            x=x+(n-(k*k));
            printf("%lld\n",x);
        }
        else
        {
            printf("%lld\n",x+k);
        }
    }
    return 0;
}
