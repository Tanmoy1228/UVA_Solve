#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        map<string,int>m;
        map<int,string>mp;
        map<string,int>::iterator it;
        vector<int>pr,v[1000];
        queue<int>source;
        int taken[1000]= {0},distance[1000]= {0},parrent[1000]= {0};
        string s1,s2;
        int a,b,c=0,e,f,x,y,l,z=1,d,s,node;
        for(i=0; i<n; i++)
        {
            cin>>s1>>s2;
            if(m[s1]==0)
            {
                m[s1]=z;
                mp[z]=s1;
                z++;
            }
            if(m[s2]==0)
            {
                m[s2]=z;
                mp[z]=s2;
                z++;
            }
            a=m[s1];
            b=m[s2];
            v[a].push_back(b);
            v[b].push_back(a);
        }
//        for(it=m.begin();it!=m.end();it++)
//        {
//            cout<<it->first<<"    "<<it->second<<endl;
//        }
        cin>>s1>>s2;
        if(s1==s2)
        {
            cout<<s1<<" "<<s2<<endl;
            continue;
        }
        a=m[s1];
        b=m[s2];
        source.push(a);
        taken[a]=1;
        distance[a]=0;
        while(!source.empty())
        {
            y=source.front();
            taken[y]=1;
            l=v[y].size();
            for(i=0; i<l; i++)
            {
                x=v[y][i];
                if(!taken[x])
                {
                    source.push(x);
                    parrent[x]=y;
                    taken[x]=1;
                    distance[x]=distance[y]+1;
                    s=x;
                    if(x==b)
                    {
                        c=2;
                    }
                }
                if(c==2)
                {
                    break;
                }
            }
            if(c==2)
            {
                break;
            }
            source.pop();
        }
        if(c==2)
        {
            node=b;
            pr.push_back(node);
            while(node!=a)
            {
                node = parrent[node];
                pr.push_back(node);
            }
            d=pr.size();
            for(i=d-1; i>0; i--)
            {
                e=pr[i];
                f=pr[i-1];
                cout<<mp[e]<<" "<<mp[f]<<endl;
            }
            printf("\n");
            continue;
        }
        printf("No route\n\n");
    }
    return 0;
}
