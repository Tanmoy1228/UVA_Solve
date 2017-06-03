#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m))
    {
        if(n==0 && m==0)
        {
            break;
        }
        int i,j,k,fst,lst,length;
        int mat[102][102];
        int indegree[102]={0};
        int take[102]={0};
        //int ans[102]={0};
        vector<int>v[102],ans;
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&fst,&lst);
            mat[fst][lst]=1;

            indegree[lst]++;
            v[fst].push_back(lst);
        }
        for(k=1; k<n; k++)
        {
            if(!indegree[k])
            {
                ans.push_back(k);
            }
        }
        for(k=1; k<=n; k++)
        {
            for(i=1; i<=n; i++)
            {
                if(!take[i] && !indegree[i])
                {
                    length=v[i].size();
                    take[i]=1;
                    if(count(ans.begin(),ans.end(),i)==0)
                    {
                        ans.push_back(i);
                    }

                    for(j=0; j<length; j++)
                    {
                        //cout<<i<<" "<<v[i][j]<<endl;
                        indegree[v[i][j]]--;
                        if(!indegree[v[i][j]])
                        {
                            ans.push_back(v[i][j]);
                        }
                    }
                    break;
                }
            }
        }
        for(k=0; k<n-1; k++)
        {
            cout<<ans[k]<<" ";
        }
        cout<<ans[k]<<"\n";
    }
    return 0;
}
