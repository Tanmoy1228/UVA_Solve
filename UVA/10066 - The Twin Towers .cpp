#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define sc(a) scanf("%lld",&a)

ll n,m,visit[102][102],dp[102][102];
char A[102],B[102];

ll LCA(ll i, ll j)
{
    if(i==n || j==m)
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
    ll i,j,t=1,ans;
    while(1)
    {
        gets(A);
        if(A[0]=='#')
            break;
        gets(B);
        memset(visit,false,sizeof visit);

        n=strlen(A);
        m=strlen(B);

        ans=LCA(0,0);

        printf("Case #%lld: you can visit at most %lld cities.\n",t++,ans);
    }
    return 0;
}
