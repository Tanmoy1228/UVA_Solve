#include<bits/stdc++.h>
using namespace std;
vector<long long int> v;
long long int l,dp[25][210];
long long int knapsak(long long int i,long long int n)
{
    long long int r1=0,r2=0;
    if(i>=l)
        return 0;

    if(n-v[i]==0)
        return dp[i][n]=1;
    if(dp[i][n]!=-1)
        return dp[i][n];
    if(n-v[i]>0)
        r1=knapsak(i+1,n-v[i]);
    r2=knapsak(i+1,n);
    return dp[i][n]=r1+r2;
}

int main()
{
    long long int n,m,i,j,t,T,a;

    scanf("%lld",&T);
    getchar();
    for(t=1;t<=T;t++)
    {
        v.clear();
        memset(dp,-1,sizeof dp);
        char s[1000];
        gets(s);
        l=strlen(s);
        a=0;
        for(i=0;i<l;i++)
        {
            if(s[i]==' ')
            {
                v.push_back(a);
                a=0;
            }
            else
            {
                a=a*10;
                a=a+s[i]-'0';
            }
        }
        v.push_back(a);
        a=0;
        l=v.size();
        for(i=0;i<l;i++)
            a+=v[i];
        if(a%2==1)
        {
            cout<<"NO\n";
            continue;
        }
        if(knapsak(0,a/2))
           cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
