#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll n,t,p,dp[75][75];

ll call(ll i, ll j)
{
    ll a=0,k;

    if(i>n || j>t)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    if(j==t)
        return 1;

    for(k=0;k<=t-j;k++)
        a+=call(i+1,j+k);

    return dp[i][j]=a;
}

int main()
{
    ll testcase;
    cin>>testcase;
    while(testcase--)
    {
        cin>>n>>t>>p;
        memset(dp,-1,sizeof dp);
        t=t-n*p;
        cout<<call(0,0)<<endl;
    }
    return 0;
}
