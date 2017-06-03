#include<stdio.h>
int main()
{
    long long int t=1;
    unsigned long long b,s;
    while(scanf("%llu %llu",&b,&s)!=EOF)
    {
        if(b==0 && s==0)
        {
            break;
        }
        if(b==1 || b==0)
        {
            printf("Case %lld: :-\n",t);
        }
        else if(b<=s)
        {
            printf("Case %lld: :-|\n",t);
        }
        else if(b>s)
        {
            printf("Case %lld: :-(\n",t);
        }
        t++;
    }
    return 0;
}
