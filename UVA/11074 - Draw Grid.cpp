#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define ull unisgned long long
#define read freopen("Input.txt","r",stdin)
#define write freopen("out.txt","w",stdout)
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define PI acos(-1.0)
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define sf scanf
#define MAX 5*100000+4
using namespace std;
//long long n,s,t, sum[MAX],x;


int main()
{
    int T,S,N,total,t=1;
    while(cin>>S>>T>>N)
    {
        if(N==0 && T==0 && S==0)
            break;
        cout<<"Case "<<t<<":\n";
        t++;
        total=T*(N+1)+N*S;
        for(int h=1; h<=N; h++)
        {


            for(int j=1; j<=T; j++)
            {
                for(int i=1; i<=total; i++)
                {
                    cout<<"*";
                }
                cout<<endl;
            }
            for(int i=1; i<=S; i++)
            {
                for(int j=1; j<=N; j++)
                {
                    for(int k=1; k<=T; k++)
                    {
                        cout<<"*";
                    }
                    for(int k=1; k<=S; k++)
                    {
                        cout<<".";
                    }
                }
                for(int k=1; k<=T; k++)
                {
                    cout<<"*";
                }
                cout<<endl;
            }
        }
        for(int j=1; j<=T; j++)
        {
            for(int i=1; i<=total; i++)
            {
                cout<<"*";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    return 0;
}
