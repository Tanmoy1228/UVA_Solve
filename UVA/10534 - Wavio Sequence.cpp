#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i,j,k,l,h,m,lis,A[10009],I[10009],L[10009],L1[10009],B[10009];
    //freopen("in.txt","r",stdin);
    while(scanf("%lld",&n)!=EOF)
    {
        for(i=1; i<=n; i++)
            scanf("%lld",&A[i]);
        lis=0;
        I[0]=-999999999;
        for(i=1; i<=n; i++)
            I[i]=999999999;
        for(i=1; i<=n; i++)
        {
            l=0;
            h=lis;
            while(l<=h)
            {
                m=(l+h)/2;
                if(I[m]<A[i])
                    l=m+1;
                else
                    h=m-1;
            }
            I[l]=A[i];
            L[i]=l;
            lis=max(l,lis);
        }
        lis=0;
        for(j=n,k=1; k<=n; j--,k++)
        {
            B[k]=A[j];
        }
        I[0]=-999999999;
        for(i=1; i<=n; i++)
            I[i]=999999999;
        for(i=1; i<=n; i++)
        {
            l=0;
            h=lis;
            while(l<=h)
            {
                m=(l+h)/2;
                if(I[m]<B[i])
                    l=m+1;
                else
                    h=m-1;
            }
            I[l]=B[i];
            L1[i]=l;
            lis=max(l,lis);
        }
        lis=0;
        for(i=1; i<=n; i++)
            lis=max(lis,min(L[i],L1[n-i+1]));
        printf("%lld\n",2*lis-1);
    }
    return 0;
}
