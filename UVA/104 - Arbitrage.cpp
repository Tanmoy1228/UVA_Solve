#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define sc(a) scanf("%lld",&a)
int main()
{
    ll n,m,i,j,k,t=1,parent[35][35];
    double cost,CostArr[35][35];
    string s1,s2;
    map<string,ll>mp;
    while(sc(n) && n!=0)
    {
        mp.clear();
        memset(CostArr,0,sizeof CostArr);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(i==j)
                    continue;
                cin>>cost;
                CostArr[i][j]=cost;
            }
        }

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                parent[i][j]=i;
                if(i==j)
                    CostArr[i][j]=1.0;
            }
        }
        for(k=1; k<=n; k++)
        {
            for(i=1; i<=n; i++)
            {
                for(j=1; j<=n; j++)
                {
                    if(CostArr[i][j]*1.0<CostArr[i][k]*CostArr[k][j])
                        parent[i][j]=k;
                    CostArr[i][j]=max(CostArr[i][j]*1.0,CostArr[i][k]*CostArr[k][j]);
                }
            }
        }
        ll mark=0;
        for(i=1; i<=n; i++)
            if(CostArr[i][i]>1.0)
                mark=1;
        if(mark)
        {

        }
        else
            printf("Case %lld: No\n",t);
        t++;
    }
    return 0;
}

