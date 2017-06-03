/////////////////////// All Is Well /////////////////////////

#include <bits/stdc++.h>

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define CIN   ios_base::sync_with_stdio(0); cin.tie(0)
#define getint(n) scanf("%d", &n)
#define pb(a) push_back(a)
#define ll long long int
#define ull unsigned long long int
#define dd double
#define SZ(a) int(a.size())
#define read() freopen("input.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define pi acos(-1.0)
#define pf printf
#define sf scanf
#define mp make_pair
#define paii pair<int, int>
#define padd pair<dd, dd>
#define pall pair<ll, ll>
#define fr first
#define sc second
#define CASE(n) printf("Case %d: ",++n)
#define CASE_COUT cout<<"Case "<<++cas<<": "
#define inf 1000000000
#define EPS 1e-9

using namespace std;

vector<ll>data;
ll mapa[1005],pos[1005],cum[1005];

int main()
{
    ll a,c,m,x,q,n;
    while(sf("%lld %lld %lld %lld %lld %lld",&a,&c,&m,&x,&q,&n)==6)
    {
        mem(pos,-1);
        mem(mapa,0);
        data.clear();
        data.pb(-1);
        data.pb(x);
        pos[x]=1;
        mapa[x]=1;
        ll val=x;
        ll i;
        for(i=2;i<=n;i++)
        {
            val=((val*a) + c)%m;
            //cout<<val<<endl;
            if(pos[val]!=-1)
            {
                break;
            }
            mapa[val]++;
            data.pb(val);
            pos[val]=i;
        }
        ll lef=pos[val],rig=i-1;
        ll len=rig-lef+1;
        ll baki=n-i+1;
        ll cont=baki/len;
        ll jamela=baki%len;
        for(ll j=lef;j<=rig;j++)
        {
            //pf("fdf %d\n",data[j]);
            mapa[data[j]]+=cont;
        }
        for(ll j=lef,pp=0;pp<jamela;pp++,j++)
        {
            mapa[data[j]]++;
        }
        sort(all(data));
//        loop(j,data.size())
//        pf("%lld\n",mapa[data[j]]);
        cum[0]=0;
        loop(i,data.size())
        {
            cum[i]=cum[i-1]+mapa[data[i]];
        }
        while(q--)
        {
            ll kk;
            sf("%lld",&kk);
            ll cnt=0;
            int ans=lower_bound(cum,cum+data.size(),kk)-cum;
            pf("%lld\n",data[ans]);
        }
    }

    return 0;
}
