#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct node
{
    bool endmark;
    node *next[11];
    node()
    {
        endmark=false;
        for(ll i=0; i<10; i++)
        {
            next[i]=false;
        }
    }
}* root;

bool inserts(string s)
{
    ll i,l=s.size();
    node *curr=root;
    //cout<<s<<endl;
    ll ok=-1;
    for(i=0; i<l; i++)
    {
        ll a=s[i]-'0';
        if(curr->next[a]==NULL)
        {
            curr->next[a]=new node();
            ok=1;
        }
        if(curr->endmark)
            return false;
        curr=curr->next[a];

    }
    curr->endmark=true;
    if(ok==-1)
        return false;
    else
        return true;
}

void del(node *cur)
{
    for(int i=0; i<10; i++)
        if(cur->next[i])
            del(cur->next[i]) ;
    delete(cur) ;
}

int main()
{
    ll n,m,t,i,j,ans;
    string s;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ans=0;
        root=new node();
        for(i=1; i<=n; i++)
        {
            cin>>s;
            bool bl=inserts(s);
            if(!bl)
            {
                ans=-1;
            }
        }
        if(ans==-1)
            printf("NO\n");
        else
            printf("YES\n");

        del(root);
    }
    return 0;
}
