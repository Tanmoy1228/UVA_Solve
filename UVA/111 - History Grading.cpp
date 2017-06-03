#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define sc(a) scanf("%lld",&a)

ll n,m,A[102],B[102],visit[102][102],dp[102][102];

ll LCA(ll i, ll j)
{
    if(i==n+1 || j==n+1)
        return 0;

    if(visit[i][j])
        return dp[i][j];

    ll ans,val1,val2;
    //cout<<A[i]<<" "<<B[j]<<endl;

    if(A[i]==B[j])
        ans=1+LCA(i+1,j+1);
    else
    {
        val1=LCA(i+1,j);
        val2=LCA(i,j+1);
        ans=max(val1,val2);
    }
    visit[i][j]=true;
    return dp[i][j]=ans;
}

int main()
{
    ll i,j,t=1,ans,a;

    sc(n);
    for(i=1;i<=n;i++)
        sc(a),A[a]=i;
    while(cin>>a)
    {
        B[a]=1;
        memset(visit,false,sizeof visit);
        for(i=2;i<=n;i++)
            sc(a),B[a]=i;

        ans=LCA(1,1);

        printf("%lld\n",ans);
    }
    return 0;
}
