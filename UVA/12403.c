#include<stdio.h>
#include<string.h>
int main()
{
    long long int t,c=0;
    scanf("%lld",&t);
    while(t--)
    {
        char s[100];
        long long int n;
        scanf("%s",s);
        if(strcmp(s,"donate")==0)
        {
            scanf("%lld",&n);
            c=c+n;
        }
        else if(strcmp(s,"report")==0)
        {
            printf("%lld\n",c);
        }
    }
    return 0;
}
