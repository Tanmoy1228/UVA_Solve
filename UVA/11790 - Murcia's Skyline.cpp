#include<bits/stdc++.h>
using namespace std;
long long int A[10000009],B[10000009],I[10000009],L[10000009];
int main()
{
    long long int n,i,j,t,T,lis,l,h,m,ans1,ans2;
    scanf("%lld",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%lld",&n);
        for(i=1; i<=n; i++)
        {
            scanf("%lld",&A[i]);
            L[i]=0;
            I[i]=0;
        }
        for(i=1; i<=n; i++)
            scanf("%lld",&B[i]);
        ans1=0;
        ans2=0;
        L[1]=B[1];
        I[1]=B[1];
        for(i=1; i<=n; i++)
        {
            L[i]=max(L[i],B[i]);
            I[i]=max(I[i],B[i]);
            for(j=1+i; j<=n; j++)
            {
                if(A[j]<A[i])
                {
                    L[j]=max(L[j],L[i]+B[j]);
                }
                else if(A[j]>A[i])
                {
                    I[j]=max(I[j],I[i]+B[j]);
                }
            }
        }
        for(i=1; i<=n; i++)
        {
            ans1=max(ans1,I[i]);
            ans2=max(ans2,L[i]);
        }
        if(ans2>ans1)
            printf("Case %lld. Decreasing (%lld). Increasing (%lld).\n",t,ans2,ans1);
        else
            printf("Case %lld. Increasing (%lld). Decreasing (%lld).\n",t,ans1,ans2);
    }
    return 0;
}
