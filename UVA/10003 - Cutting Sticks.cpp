#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll arr[55],dp[55][55];

ll call(ll left, ll right)
{
    if(left+1==right)
        return 0;
    if(dp[left][right]!=-1)
        return dp[left][right];
    ll cost,mini=pow(10,12);
    for(ll i=left+1;i<right;i++)
    {
        cost=call(left,i)+call(i,right)+arr[right]-arr[left];
        mini=min(mini,cost);
    }
    return dp[left][right]=mini;

}

int main()
{
    ll n,m,i,ans;
    while(cin>>n && n)
    {
        memset(dp,-1,sizeof dp);
        cin>>m;
        for(i=1;i<=m;i++)
            cin>>arr[i];
        arr[0]=0;
        arr[m+1]=n;
        ans=call(0,m+1);
        printf("The minimum cutting is %lld.\n",ans);
    }
    return 0;
}
