#include<bits/stdc++.h>
#define ll long long int
#define MAX 10000009
using namespace std;
int main()
{
    ll n,m,i,j,t,total;
    scanf("%lld",&t);
    getchar();
    getchar();
    string s;
    map<string,ll>mp;
    map<string,ll>::iterator mt;

    while(t--)
    {
        double ans=0;
        total=0;
        mp.clear();
        while(getline(cin,s) && s.size()>0)
        {
            mp[s]++;
            total++;
        }
        for(mt=mp.begin();mt!=mp.end();mt++)
        {
            s=mt->first;
            ans=mt->second;
            ans=(ans/total*1.0)*100.0;
            cout<<s;
            printf(" %0.4lf\n",ans);
        }
        if(t!=0)
            printf("\n");
    }

    return 0;
}

