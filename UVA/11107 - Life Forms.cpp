///For sorting the suffix of an array
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

struct info
{
    ll idx,tup[2],no;
    bool operator< (const info &a) const ///sort on basis tup[0] then tup[1]
    {
        if(tup[0]==a.tup[0])
            return tup[1]<a.tup[1];
        else
            return tup[0]<a.tup[0];
    }
};

ll Rank[109][200009],m,k,A[200009];;
info arr[200005];

bool valid(ll n)
{
    ll i,a,b;
    b=0;
    bool visit[109];
    memset(visit,false,sizeof visit);
    //cout<<n-m+1<<" "<<n<<endl;
    for(i=n-m+1;i<=n;i++)
    {
        a=arr[i].idx;
        a=A[a];
        visit[a]=true;
    }
    for(i=1;i<=k;i++)
    {
        if(visit[i])
            b++;
    }
    cout<<b<<endl;
    if(b<m)
        return false;
    return true;
}

void Suffix_Array(string s)
{
    ll n,i,j,a,b,step,jump,id1,id2,LCP[200009],ans;
    set<string>se;
    set<string>:: iterator st;
    string s1;
    se.clear();
    n=s.size();

    m++;
    m=ceil(m/2.0);
    //cout<<m<<endl;

    for(i=0; i<n; i++)
    {
        Rank[0][i]=abs(s[i]-'a'+1); ///rank suffixes according to 1st char

        //cout<<Rank[0][i]<<" "<<(int) s[i]<<endl;
        arr[i].tup[0]=0;
        arr[i].tup[1]=0;
    }

    for(step=1,jump=1; jump<=n; step++,jump=jump*2)
    {
        for(i=0; i<n; i++)
        {
            a=Rank[step-1][i]; /// what i was in prev step
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

    ///when two or more string is added we store the string no in arr[i].no
    /*
    for(i=0; i<n; i++)
    {
        if(arr[i].idx<x+1)
            arr[i].no=1;
        else if(arr[i].idx<x+1+y+1)
            arr[i].no=2;
        else
            arr[i].no=3;
    }
    */

    ///LCP for storing longest common prefix of suffix array
    memset(LCP,0,sizeof LCP);

    for(i=0;i<s.size();i++)
        cout<<i<<" "<<s[i]<<endl;

    for(i = m-1; i < n; i++)
    {
        id1 = arr[i-m+1].idx;
        id2 = arr[i].idx;
        cout<<i<<"  "<<id1<<" "<<id2<<endl;
        if(!valid(i))
            continue;
        if(id1==id2)
        {
            LCP[i]=n-id1;///for circle
            continue;
        }
        LCP[i] = 0;
        for(j = step - 1; j >= 0; j--)
        {
            if(Rank[j][id1] == Rank[j][id2])
            {
                LCP[i] += (1 << j);
                id1 += (1 << j);
                id2 += (1 << j);
            }
        }
        if(LCP[i])
            cout<<i<<" "<<id1<<" "<<id2<<endl;
        cout<<endl;
    }
    ans=0;
    for(i=1;i<n;i++)
        ans=max(ans,LCP[i]);
    //cout<<ans<<endl;
    if(ans==0)
    {
        cout<<"?"<<endl;
        return;
    }
    for(i=0;i<n;i++)
    {
        if(ans==LCP[i])
        {
            id1=arr[i].idx;
            s1="";
            for(j=id1;j<ans+id1;j++)
                s1+=s[j];
            se.insert(s1);
        }
    }
    for(st=se.begin();st!=se.end();st++)
        cout<<*st<<endl;
}

int main()
{
    ll t,n,i=0,j;
    string s,s1;
    while(cin>>m && m)
    {
        s="";
        j=0;
        k=m;
        if(i!=0)
            cout<<endl;
        for(i=1;i<=m;i++)
        {
            cin>>s1;
            s1=s1+(char) (130+i);
            s+=s1;
            for(;j<s.size();j++)
                A[j]=i;
        }
        Suffix_Array(s);
        //cout<<arr[0].idx<<endl;
    }
    return 0;
}

