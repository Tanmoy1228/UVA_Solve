#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,k,dp[105][105];

ll call(ll i, ll sum)
{
    if(i==k && sum==n)
        return 1;
    if(i>=k || sum>n)
        return 0;
    if(dp[i][sum]!=-1)
        return dp[i][sum];
    ll total=0;
    for(ll j=0;j<=n;j++)
    {
        total=(total+call(i+1,sum+j)%1000000)%1000000;
    }
    //cout<<i<<" "<<sum<<" "<<total<<endl;
    return dp[i][sum]=total%1000000;
}

int main()
{
    while(cin>>n>>k)
    {
        if(n==0 && k==0)
            break;
        memset(dp,-1,sizeof dp);
        cout<<call(0,0)<<endl;
    }
    return 0;
}
