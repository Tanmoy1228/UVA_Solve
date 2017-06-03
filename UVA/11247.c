#include<stdio.h>
int main()
{
    long long int m,x;
    while(scanf("%lld %lld",&m,&x)!=EOF)
    {
        long long int b,v;
        if(m==0 && x==0)
        {
            break;
        }
        if(x>=100 || m==1 || x==0)
        {
            printf("Not found\n");
            continue;
        }

        v=100*(m-1)/(100-x);
        if(100*(m-1)%(100-x)==0)
            v--;
        if(v<m)
        {
            printf("Not found\n");
            continue;
        }
        printf("%lld\n",v);
    }
    return 0;
}
