#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,dp[10005];

ll call(ll sum)
{
    ll ans=9999999;
    if(dp[sum]!=-1)
        return dp[sum];
    ll m = sqrt(sum);
    //cout<<m<<endl;
    for(ll i=m;i>0;i--)
    {
        ans=min(ans,call(sum-i*i)+1);
    }
    return dp[sum]=ans;
}

int main()
{
    ll t,i;
    cin>>t;
    memset(dp,-1,sizeof dp);
    dp[0]=0;
    dp[1]=dp[4]=1;
    dp[2]=dp[5]=2;
    dp[3]=dp[6]=3;
    i=call(10001);
    while(t--)
    {
        cin>>n;
        cout<<dp[n]<<endl;
    }
    return 0;
}
