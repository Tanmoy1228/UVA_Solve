#include<stdio.h>
#include<string.h>
int main()
{
    int t=1,T;
    char s[10000];
    scanf("%d",&T);
    while(t<=T)
    {
        long long int n,i,l=0;
        scanf("%lld",&n);
        scanf("%s",s);
        for(i=0;i<n;i++)
        {
            if(s[i]=='.')
            {
                l++;
            }
        }
        printf("Case %d: %lld\n",t,l/2);
        t++;
    }
    return 0;
}
