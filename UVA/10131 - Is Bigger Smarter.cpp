#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,n,i=1,j,A[2009],I[2009],L[2009],B[2009],l,h,m,lis,top;
    vector< pair< long long int,pair< long long int,long long int> > > v;
    while(scanf("%lld %lld",&a,&b)!=EOF)
    {
        v.push_back(make_pair(a,make_pair(b,i)));
        i++;
    }
    n=i-1;
    sort(v.begin(),v.begin()+n);
    lis=0;
    I[0]=99999999999;
    for(i=1; i<=n; i++)
        I[i]=-9999999999;
    for(i=0; i<n; i++)
    {
        l=0;
        h=lis;
        while(l<=h)
        {
            m=(l+h)/2;
            if(I[m]>v[i].second.first && (v[i].first>v[m].first || m==0))
                l=m+1;
            else
                h=m-1;
        }
        I[l]=v[i].second.first;
        B[i]=l;
        lis=max(l,lis);
    }
//    for(i=0;i<n;i++)
//        cout<<B[i]<<" ";
//    cout<<endl;
    for(i=0,j=0; i<n; i++)
        if(B[i]>B[j])
            j=i;
    top=B[j];
    L[top]=j;
    for(i=j-1; i>=0; i--)
    {
        if(v[i].second.first>v[j].second.first && B[i]+1==B[j])
        {
            top--;
            L[top]=i;
            j=i;
        }
    }
    printf("%lld\n",lis);
    for(i=1; i<=lis; i++)
        printf("%lld\n",v[L[i]].second.second);

    return 0;
}

