#include<bits/stdc++.h>
#define ll long long int
#define MAX 10000009
using namespace std;

struct node
{
    bool endmark;
    ll num;
    node *next[3];
    node()
    {
        endmark=false;
        num=0;
        for(int i=0; i<2; i++)
            next[i]=NULL;
    }
}*root;

void insert(string s)
{
    ll i,len,id;
    node *curr=root;
    len=s.size();
    for(i=0;i<len;i++)
    {
        id = s[i]-'0' ;
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
        curr->num++;
    }
    curr->endmark=true;
}

ll  search(string s)
{
    ll i,len,id,ans=0;
    node *curr=root;
    len=s.size();
    for(i=0;i<len;i++)
    {
        id = s[i]-'0' ;
        if(curr->next[id]==NULL)
            return max(ans,(curr->num+1)*i);
        curr=curr->next[id];
        ans=max(ans,(curr->num+1)*(i+1) );
    }
    return ans;
}

void del(node *cur)
{
    for(int i=0; i<2; i++)
        if(cur->next[i])
            del(cur->next[i]) ;
    delete(cur) ;
}

int main()
{
    ll n,m,i,j,t,total,a,ans;
    string s;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ans=0;
        root=new node();
        cin>>s;
        ans=s.size();
        insert(s);

        for(i=1;i<n;i++)
        {
            cin>>s;
            ans=max(ans,search(s));
            insert(s);
            a=s.size();
            ans=max(ans,a);
        }
        //ans=max(ans,search(root,0));
        printf("%lld\n",ans);
        del(root);
    }

    return 0;
}
/*
5
10101000
10101101
10101111
10111100
10111111
*/

