#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,a,b,c,i;
    map<long long int, long long int>m;
    while(cin>>n)
    {
        cin>>a;
        m.clear();
        for(i=1; i<=a; i++)
        {
            cin>>c;
            m[c]=1;
        }
        cin>>b;
        for(i=1; i<=b; i++)
        {
            cin>>c;
            m[c]=1;
        }
        c=0;
        for(i=1; i<=n; i++)
        {
            if(m[i]!=1)
            {
                c=1;
                break;
            }
        }
        if(c==1)
            cout<<"Oh, my keyboard!\n";
        else if(c==0)
            cout<<"I become the guy.\n";
    }
    return 0;
}
