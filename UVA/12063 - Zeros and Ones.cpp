#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

ll n,m,k,a,b;
ll s[20];
ll dp[65][33][3][101];

ll rec(ll pos,ll one, ll isone, ll val)
{
    ll ret,i,j,ended;

    if(one>n/2 || (pos-one)>n/2)
        return 0;

    if(pos==n)
    {
        if(val==0)
            return 1;
        else
            return 0;
    }

    if(dp[pos][one][isone][val]!=-1)
        return dp[pos][one][isone][val];

    ret=0;
    ret+=rec(pos+1,one+1,1,((2*val)+1)%k);
    ret+=rec(pos+1,one,0,((2*val))%k);
//    cout<<pos<<" "<<one<<" "<<(pos+1LL-one)<<endl;
//    cout<<pos<<" "<<one<<" "<<isone<<" "<<val<<" "<<ret<<endl;

    return dp[pos][one][isone][val]=ret;
}


int main()
{
    ll t,T,i,j,ans;
    scanf("%lld",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%lld %lld",&n,&k);

        memset(dp,-1,sizeof dp);
        ans=0;
        if(k==1)
            ans=powl(2,n-1);
        if(n%2==0 && k>0)
            ans=rec(1,1,1,1);

        printf("Case %lld: %lld\n",t,ans);
    }
    return 0;
}



