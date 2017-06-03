#include<stdio.h>
#include<math.h>
int main()
{
    int t=1,T;
    scanf("%d",&T);
    while(t<=T)
    {
        unsigned long long n,s,j=0,i;
        scanf("%llu",&n);
        s=sqrt(n);
        printf("Case #%d: %llu",t,n);
        for(i=2;i<=s;i++)
        {
            if(n%i==0)
            {
                printf(" = %llu * %llu",i,n/i);
                j++;
            }
            if(j==2)
            {
                break;
            }
        }
        printf("\n");
        t++;
    }
    return 0;
}
