#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll visit[1000005];

bool allvisit(ll k)
{
    ll i;
    for(i=1; i<=k; i++)
        if(visit[i]>0)
            continue;
        else
            return false;
    return true;
}

int main()
{
    ll t,T,n,m,k,i,A[1000005],ans,a;
    deque< ll >dq;
    scanf("%lld",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%lld %lld %lld",&n,&m,&k);

        dq.clear();
        memset(visit,0,sizeof visit);
        memset(A,0,sizeof A);
        ans=10000000000;

        for(i=1;i<=min(n,(ll)3);i++)
            A[i]=i;
        for(i=4; i<=n; i++)
        {
            A[i]=(A[i-1]+A[i-2]+A[i-3])%m+1;
        }
        for(i=1; i<=n; i++)
        {
            dq.push_back(A[i]);
            visit[ A[i] ]++;
            while(!dq.empty() && allvisit(k))
            {
                a=dq.size();
                ans=min(ans,a);
                a=dq.front();
                visit[a]--;
                dq.pop_front();
            }
        }
        if(ans==10000000000)
            printf("Case %lld: sequence nai\n",t);
        else
            printf("Case %lld: %lld\n",t,ans);
    }
    return 0;
}
