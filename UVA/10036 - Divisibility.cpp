#include<bits/stdc++.h>
using  namespace std;
#define ll long long int

ll n,m,arr[10005],dp[10005][105];

ll call(ll i, ll sum)
{
    if(i==n && sum%m==0)
        return 1;
    if(i>=n)
        return 0;
    if(dp[i][sum]!=-1)
        return dp[i][sum];
    ll a=call(i+1,((sum+arr[i])%m+m)%m);
    ll b=call(i+1,((sum-arr[i])%m+m)%m);
    dp[i][sum]=a||b;
    //cout<<i<<" "<<sum<<" "<<dp[i][sum]<<endl;
    return dp[i][sum];
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        memset(dp,-1,sizeof dp);
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        if(call(1,arr[0]%m))
            cout<<"Divisible\n";
        else
            cout<<"Not divisible\n";
    }
}
