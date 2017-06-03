#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,i,j,l,a,b,maxi;
    string s;
    vector<long long int>v;
    while(getline(cin, s))
    {
        v.clear();
        l=s.length();
        a=0;
        b=0;
        for(i=0; i<l; i++)
        {
            if(s[i]==' ')
            {
                //cout<<a<<endl;
                if(b==1)
                    v.push_back((a*-1));
                else
                    v.push_back(a);
                a=0;
                b=0;
            }
            else if(s[i]=='-')
                b=1;
            else
            {
                a=a*10;
                a=a+s[i]-'0';
            }
        }
        n=v.size();
        maxi=0;
        maxi=-999999;
        a=1;
        for(i=0; i<n; i++)
        {
            //cout<<v[i]<<endl;
            b=min(b,v[i]);
        }
        for(j=0; j<n; j++)
        {
            a=1;
            for(i=j; i<n; i++)
            {
                a*=v[i];
                if(a>maxi)
                    maxi=a;
            }
        }
        printf("%lld\n",maxi);
    }
    return 0;
}
