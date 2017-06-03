#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll A[100009];

void calfact()
{
    ll i,m,j,k,a;
    m=1;
    A[0]=1;
    for(i=1; i<=10005; i++)
    {
        m=m*i;
        while(m%10==0)
        {
            m=m/10;
        }
        a=m%10;
        m=m%100000;
//        if(i>3100 && i<3200)
//        cout<<i<<" "<<m<<" "<<a<<endl;
        A[i]=a;
    }
    return;
}

int main()
{
    ll n,m,i,j,ans;

    memset(A,0,sizeof A);
    calfact();
    while(scanf("%lld",&n)!=EOF)
    {
        ans=0;

        printf("%5lld -> %lld\n",n,A[n]);
    }

    return 0;
}

