#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,m,t,i,j,err,a,b,total;
    while(cin>>n>>m>>t)
    {
        if(m<n)
            swap(n,m);
        err=t;
        total=0;
        ll x,y;
        for(i=0;i<=t/n;i++)
        {
            a=t-i*n;
            b=a/m;
//            if(t-(i*n+b*m)==0)
//                total=max(total,b+i);
            if(err==t-(i*n+b*m))
                total=max(total,b+i);
            if(err>t-(i*n+b*m))
            {
                total=i+b;
                err=t-(i*n+b*m);
                x=b;
                y=i;
            }
        }

        for(i=0;i<=t/m;i++)
        {
            a=t-i*m;
            b=a/n;
            if(err==t-(i*m+b*n))
                total=max(total,b+i);
            if(err>t-(i*m+b*n))
            {
                total=i+b;
                err=t-(i*m+b*n);
                x=i;
                y=b;
            }
        }
        //cout<<x<<" "<<y<<endl;
        if(err==0)
        cout<<total<<endl;
        else
            cout<<total<<" "<<err<<endl;

    }
    return 0;
}
