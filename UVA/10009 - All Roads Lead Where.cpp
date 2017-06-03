#include<bits/stdc++.h>
using namespace std;
#define ll long long int
/*
1
6 1
Rome BUET
BUET TSC
TSC Sahbag
Sahbag Nilkhet
Nilkhet Katabon
Katabon ElephantRoad
ElephantRoad Rome

*/

map<string,ll>mp;
map<ll,string>mpp;
vector<ll>graph[100];
ll ans[100],last,fst;
bool visit[100];

void bfs(ll u)
{
    queue<ll>q;
    q.push(u);
    ll i,v,j;
    while(1)
    {
        u=q.front();
        q.pop();
        visit[u]=true;
        for(i=0; i<graph[u].size(); i++)
        {
            v=graph[u][i];
            //cout<<v<<endl;
            if(!visit[v])
            {
                q.push(v);
                ans[v]=u;
                if(v==fst)
                    return;
            }
        }
    }
}

int main()
{
    ll t,n,m,i,j;
    string s1,s2;

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        mp.clear();
        mpp.clear();

        for(i=0; i<=30; i++)
            graph[i].clear();
        for(i=1,j=1; i<=n; i++)
        {
            cin>>s1>>s2;
            if(mp.find(s1)==mp.end())
            {
                mp[s1]=j;
                mpp[j]=s1;
                j++;
            }
            if(mp.find(s2)==mp.end())
            {
                mp[s2]=j;
                mpp[j]=s2;
                j++;
            }
            graph[ mp[s1] ].push_back(mp[s2]);
            graph[ mp[s2] ].push_back(mp[s1]);
        }

        for(i=1; i<=m; i++)
        {
            cin>>s1>>s2;
            memset(visit,false,sizeof visit);
            memset(ans,-1,sizeof ans);
            fst=mp[s1];
            last=mp[s2];
            bfs(last);
            while(fst!=last)
            {
                s1=mpp[fst];
                //cout<<s1<<endl;
                printf("%c",s1[0]);
                fst=ans[fst];
            }
            s1=mpp[fst];
            printf("%c\n",s1[0]);

        }
        if(t!=0)
            printf("\n");

    }
    return 0;
}
