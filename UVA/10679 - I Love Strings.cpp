#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<string>vs;

struct NODE
{
    ll cnt,i;
    bool vis;
    NODE *next[60];
    vector<NODE *> out;
    NODE()
    {
        cnt=0;
        vis=false;
        out.clear();
        for(i=0;i<60;i++)
            next[i]=NULL;
    }

    ~NODE()
    {
        for(i=0;i<60;i++)
            if(next[i])
                delete(next[i]);
    }
};

NODE *root,*p;

void buildtrie()
{
    ll i,j,c;
    NODE *u,*w,*v;
    root=new NODE;
    queue< NODE* > q;

    /*usual trie part*/
    for(i=0;i<vs.size();i++)
    {
        p=root;
        for(j=0;j<vs[i].size();j++)
        {
            c=vs[i][j]-'A'+1;
            if(!p->next[c])
                p->next[c]=new NODE;
            p=p->next[c];
        }
    }

    /* Pushing the nodes adjacent to root into queue */
    for(i=0;i<60;i++)
    {
        if(root->next[i])
        {
            q.push(root->next[i]);
            root->next[i]->next[0]=root;
        }
        else
            root->next[i]=root;
    }

    while(!q.empty())
    {
        u=q.front();
        q.pop();

        for(i=1;i<60;i++)
        {
            if(u->next[i])
            {
                v=u->next[i];
                w=u->next[0];

                while(!w->next[i])
                    w=w->next[0];

                w=w->next[i];
                v->next[0]=w;
                w->out.push_back(v);
                q.push(v);
            }
        }
    }
}

void aho_corasick(string s)
{
    ll i,c;
    p=root;
    for(i=0;i<s.size();i++)
    {
        c=s[i]-'A'+1;
        while(!p->next[c])
            p=p->next[0];
        p=p->next[c];
        p->vis=true;
    }
}

int main()
{
    ll t,n,i,j,c;
    string s1,s2;
    scanf("%lld",&t);
    while(t--)
    {
        cin>>s1;
        scanf("%lld",&n);
        vs.clear();
        for(i=0;i<n;i++)
        {
            cin>>s2;
            vs.push_back(s2);
        }
        buildtrie();
        aho_corasick(s1);
        for(i=0;i<n;i++)
        {
            p=root;
            for(j=0;j<vs[i].size();j++)
            {
                c=vs[i][j]-'A'+1;
                p=p->next[c];
            }
            if(p->vis)
                printf("y\n");
            else
                printf("n\n");
        }
    }
    return 0;
}
