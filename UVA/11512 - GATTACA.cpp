//For sorting the suffix of an array
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

struct info
{
    ll idx,tup[2];
    bool operator< (const info &a) const //sort on basis tup[0] then tup[1]
    {
        if(tup[0]==a.tup[0])
            return tup[1]<a.tup[1];
        else
            return tup[0]<a.tup[0];
    }
};

ll Rank[109][2009];
info arr[2005];

void Suffix_Array(string s)
{
    ll n,i,j,a,b,step,jump,id1,id2,LCP[2009];
    n=s.size();

    for(i=0; i<n; i++)
    {
        Rank[0][i]=s[i]-'a'+1; //rank suffixes according to 1st char

        arr[i].tup[0]=0;
        arr[i].tup[1]=0;
    }
    Rank[0][i]=100;
    n++;

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

    //LCP for storing longest common prefix of suffix array
    LCP[0] = 0;

    for(i = 1; i < n; i++)
    {
        id1 = arr[i - 1].idx;
        id2 = arr[i].idx;
        if(id1==id2)
        {
            LCP[i]=n-id1;
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
    }
    ll ans=0;

    for(i=0; i<n; i++)
        ans=max(ans,LCP[i]);
    i=0;
    ll m=0;
    if(ans==0)
    {
        printf("No repetitions found!\n");
        return;
    }
    while(i<n)
    {
        j=0;
        while(ans==LCP[ i ])
        {
            j++;
            i++;
        }
        if(j>m)
        {
            m=j;
            a=i-1;
            //cout<<arr[i-1].idx<<" "<<ans<<endl;
        }
        i++;
    }
    string s1;
    s1="";
    for(i=arr[a].idx;i<arr[a].idx+ans;i++)
    {
        s1+=s[i];
    }
    cout<<s1<<" "<<m+1<<endl;
}

int main()
{
    ll t,n,m,i,j;
    string s;
    scanf("%lld",&t);
    while(t--)
    {
        cin>>s;
        Suffix_Array(s);
    }
    return 0;
}

