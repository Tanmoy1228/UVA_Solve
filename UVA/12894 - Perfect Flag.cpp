#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l,w,lp,wp,T,x0,y0,x1,y1,cx,cy,r,i;
    int lps,wps;
    cin>>T;
    for(i=0; i<T; i++)
    {
        cin>>x0>>y0>>x1>>y1>>cx>>cy>>r;
        l = x1-x0;
        w = y1-y0;
        lp= cx-x0;
        wp= cy-y0;
        lps= l/lp;
        wps= w/wp;


        if((l*9==20*lp) && (l*6==w*10)&& (w==2*wp) && (l==5*r))
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
