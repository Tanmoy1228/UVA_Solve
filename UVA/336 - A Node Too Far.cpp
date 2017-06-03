#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int main()
{
    int n,t=1;
    while(scanf("%d",&n)!=EOF)
    {
        int a,b,i,j,x,y,c=0,l;
        map<int,int>m;
        map<int,int>::iterator it,jt;
        vector<int>v[100];
        if(n==0)
        {
            break;
        }
        for(i=0; i<n; i++)
        {
            scanf("%d %d",&a,&b);
            if(m.count(a)==0)
            {
                m[a]=c;
                c++;
            }
            if(m.count(b)==0)
            {
                m[b]=c;
                c++;
            }
            v[m[a]].push_back(m[b]);
            v[m[b]].push_back(m[a]);
        }
//        for(it=m.begin(); it!=m.end(); it++)
//        {
//            printf("%d-----%d\n\n\n",it->first,it->second);
//        }
//        for(i=0; i<m.size(); i++)
//        {
//
//            for(j=0; j<v[i].size(); j++)
//            {
//                printf("%d-----%d\n",i,v[i][j]);
//            }
//        }
        while(scanf("%d %d",&x,&y)!=EOF)
        {
            int z=0,q,w,e,r,taken[100]= {0},visited[100]= {0};
            vector<int>source;
            if(x==0 && y==0)
            {
                break;
            }
            source.push_back(m[x]);
            for(i=0; i<y; i++)
            {
                l=source.size();
                for(j=0; j<l; j++)
                {
                    q=source[j];
                    w=v[q].size();
                    if(!visited[q])
                    {
                        for(e=0; e<w; e++)
                        {
                            r=v[q][e];
                            if(!taken[r])
                            {
                                source.push_back(r);
                                taken[r]=1;
                                z++;
                            }
                        }
                        visited[q]=1;
                    }
                }
            }
            if(taken[m[x]]==0)
            {
                taken[m[x]]=1;
                z++;
            }
            l=m.size();

            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",t,l-z,x,y);
            t++;

        }
    }
    return 0;
}
