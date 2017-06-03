//For sorting the suffix of an array
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

struct info
{
    ll idx,tup[2],pos;
    bool operator< (const info &a) const ///sort on basis tup[0] then tup[1]
    {
        if(tup[0]==a.tup[0])
            return tup[1]<a.tup[1];
        else
            return tup[0]<a.tup[0];
    }
};

ll Rank[109][200009];
info arr[200005];

void Suffix_Array(string s1, string s2)
{
    ll n,m,i,j,a,b,ans,step,jump,id1,id2,LCP[200009];
    string s;
    s=s1+'@'+s2;
    m=s1.size();
    n=s.size();
    ans=0;
    memset(Rank,-1,sizeof Rank);
    memset(arr,0,sizeof arr);

    for(i=0; i<n; i++)
    {
        Rank[0][i]=s[i]-'a'+1; ///rank suffixes according to 1st char

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

    for(i=0;i<n;i++)
    {
        if(arr[i].idx<m)
            arr[i].pos=1;
        else
            arr[i].pos=2;
    }

    ///LCP for storing longest common prefix of suffix array
    LCP[0] = 0;

    for(i = 1; i < n; i++)
    {
        id1 = arr[i - 1].idx;
        id2 = arr[i].idx;
        LCP[i] = 0;
        if(arr[i].pos==arr[i-1].pos)
            continue;
        if(id1==id2)
        {
            LCP[i]=n-id1;
            continue;
        }
        for(j = step - 1; j >= 0; j--)
        {
            if(Rank[j][id1] == Rank[j][id2] && Rank[j][id2])
            {
                LCP[i] += (1 << j);
                id1 += (1 << j);
                id2 += (1 << j);
            }
        }
    }


    for(i=0; i<n; i++)
        ans=max(ans,LCP[i]);

    if(ans==0)
    {
        printf("No common sequence.\n");
        return;
    }

    set<string>se;
    set<string>::iterator st;
    se.clear();
    for(i=0; i<n; i++)
    {
        if(ans==LCP[i])
        {
            s1="";
            for(j=arr[i-1].idx; j<arr[i-1].idx+ans; j++)
            {
                s1+=s[j];
            }
            se.insert(s1);
        }
    }
    for(st=se.begin(); st!=se.end(); st++)
        cout<<*st<<endl;
}

int main()
{
    ll n,m,i,j,t=1;
    char s1[500],s2[500];
    //freopen("in.txt","r",stdin);
    while(gets(s1))
    {
        gets(s2);
        if(t>1)
            printf("\n");
        Suffix_Array(s1,s2);
        getchar();
        t++;
    }
    return 0;
}

