#include<bits/stdc++.h>
using  namespace std;
#define ll long long int

ll n,m,arr[105],dp[105][3200*100];
char dir[105];

ll call(ll i, ll sum)
{
    if(i==n && sum==m)
        return 1;
    if(i>=n)
        return 0;
    if(dp[i][sum]!=-1)
        return dp[i][sum];

    ll d=0;
    ll a=call(i+1,sum+arr[i]);
    ll b=call(i+1,sum-arr[i]);
    ll c=call(i+1,sum*arr[i]);
    if(sum%arr[i]==0)
        d=call(i+1,sum/arr[i]);

    if(a==1)
        dir[i]='+';
    if(b==1)
        dir[i]='-';
    if(c==1)
        dir[i]='*';
    if(d==1)
        dir[i]='/';

    dp[i][sum]=(a||b) || (c||d);
    //cout<<i<<" "<<sum<<" "<<dp[i][sum]<<endl;
    return dp[i][sum];
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(dp,-1,sizeof dp);
        for(ll i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        cin>>m;
        if(call(1,arr[0]))
        {
            cout<<arr[0];
            for(ll i=1; i<n; i++)
                cout<<dir[i]<<arr[i];
            cout<<"="<<m<<endl;
        }
        else
            cout<<"NO EXPRESSION\n";

    }
}

