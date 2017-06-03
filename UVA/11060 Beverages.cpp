#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    int t=1,n,m;
    while(scanf("%d",&n)!=EOF)
    {
        getchar();
        int i,j,k,counter=1;
        int take[102]={0};
        int indegree[102]={0};
        int ans[102]={0};
        char B[100],B1[100],B2[100];
        map<string,int>m1;
        map<int,string>m2;
        queue<int>q;
        vector<int>v[102];
        for(i=1;i<=n;i++)
        {
            gets(B);
            m1[B]=counter;
            m2[counter]=B;
            counter++;
        }
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        {
            scanf("%s %s",B1,B2);
            v[m1[B1]].push_back(m1[B2]);
            indegree[m1[B2]]++;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(!take[j] && !indegree[j])
                {
                    ans[i]=j;
                    //cout<<j<<" "<<m2[j]<<endl;
                    take[j]=1;
                    int length=v[j].size();
                    for(k=0;k<length;k++)
                    {
                        indegree[v[j][k]]--;
                        //cout<<m2[j]<<" "<<m2[v[j][k]]<<"\n";
                    }
                    break;
                }
            }
        }

        printf("Case #%d: Dilbert should drink beverages in this order:",t);
        for(i=1;i<=n;i++)
        {
            k=ans[i];
            cout<<" "<<m2[k];
        }
        cout<<".\n\n";
        t++;
        m1.clear();
        m2.clear();
        for(i=1;i<=n;i++)
        v[i].clear();
        //getchar();
    }
    return 0;
}
