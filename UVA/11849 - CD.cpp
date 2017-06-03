#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define ull unisgned long long
#define read freopen("Input.txt","r",stdin)
#define write freopen("out.txt","w",stdout)
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define PI acos(-1.0)
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define sf scanf
#define MAX 5*100000+4
using namespace std;
long long n,s,t, sum[MAX],x;
int main()
{
    ll n,m,i,j,a;
    set<ll>s;
    while(cin>>n>>m )
    {
        if(n==0 && m==0)
            break;
        s.clear();
        for(i=1;i<=n+m;i++)
        {
            cin>>a;
            s.insert(a);
        }
        cout<<n+m-s.size()<<endl;
        }


    return 0;
}
