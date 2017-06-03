#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main()
{
    ll t,T,n,m,i,j,ans,total,A[10];
    char s[1009];
    scanf("%lld",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%s",&s);
        n=strlen(s);
        total=0;
        memset(A,0,sizeof A);

        for(i=0;i<n;i++)
        {
            A[ (s[i]-'0')%3 ]++;
            total+= (s[i]-'0');
        }

        total%=3;

        if(total==0)
        {
            ans=(A[0])%2;
        }
        else if(A[total]>0)
        {
            ans=(A[0]+1)%2;
        }
        else
        {
            ans=0;
        }

        if(ans)
            printf("Case %lld: S\n",t,ans);
        else
            printf("Case %lld: T\n",t,ans);

    }
    return 0;
}

