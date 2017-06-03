#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll Rank[109][200009];
struct info
{
    ll idx,tup[2];
    bool operator< (const info &a) const
    {
        if(tup[0]==a.tup[0])
            return tup[1]<a.tup[1];
        else
            return tup[0]<a.tup[0];
    }
};

info arr[200005];

void Suffix_Array(string s)
{
    ll n,i,a,b,step,jump;
    s=s+s+'|';
    n=s.size();

    for(i=0; i<n; i++)
    {
        Rank[0][i]=s[i]-'a'+1;

        arr[i].tup[0]=0;
        arr[i].tup[1]=0;
    }

    for(step=1,jump=1; jump<=n; step++,jump=jump*2)
    {
        for(i=0; i<n; i++)
        {
            a=Rank[step-1][i]; // what i was in prev step
            if(i+jump<n)
                b=Rank[step-1][i+jump];
            else
                b=-1;

            arr[i].idx=i;
            arr[i].tup[0]=a;
            arr[i].tup[1]=b;
        }
        sort(arr,arr+n);

        Rank[step][arr[0].idx]=0;
        for(i=1; i<n; i++)
        {
            if(arr[i].tup[0]==arr[i-1].tup[0] && arr[i].tup[1]==arr[i-1].tup[1])
                Rank[step][arr[i].idx]=Rank[step][arr[i-1].idx];
            else
                Rank[step][arr[i].idx]=i;
        }
    }
}

int main()
{
    ll t,n,m,i,j;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        n=s.size();
        Suffix_Array(s);
        cout<<arr[0].idx+1<<endl;
    }
    return 0;
}

