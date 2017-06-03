#include<stdio.h>
int main()
{
    unsigned long long n,m;
    while(scanf("%llu %llu",&n,&m)!=EOF)
    {
        unsigned long long i,c=0;
        if(n<=0 || m<=0)
        {
            break;
        }
        for(i=n;i<=m;i++)
        {
            c=c+i;
            if(c>=m)
            {
                printf("%llu\n",i);
                break;
            }
        }
    }
    return 0;
}
