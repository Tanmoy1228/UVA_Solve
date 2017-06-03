#include<bits/stdc++.h>
using namespace std;
vector<char>str,v;
vector<int>check[26];
map<char,int>m,taken;
map<int,char>m1;
int j,no=5;
void call()
{
    int i;
    if(v.size()==j)
    {
        no=1;
        for(i=0;i<j-1;i++)
            cout<<v[i]<<" ";
        cout<<v[i]<<endl;
        return;
    }
    for(i=0;i<j;i++)
    {
        if(taken[str[i]]!=1)
        {
            int z=9,l;
            l=check[m[str[i]]].size();

            if(l==0)
            {
                taken[str[i]]=1;
                v.push_back(str[i]);
                call();
                taken[str[i]]=0;
                v.pop_back();
            }
            for(int k=0;k<l;k++)
            {
                if(count(v.begin(),v.end(), m1[check[m[str[i]]][k]])>0)
                {
                    z=1;
                }
                else
                {
                    z=0;
                    break;
                }
            }
            if(z==1)
            {
                taken[str[i]]=1;
                v.push_back(str[i]);
                call();
                taken[str[i]]=0;
                v.pop_back();
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    getchar();
    while(t--)
    {
        char c[250];
        int length,i;
        no=5;
        gets(c);
        length=strlen(c);
        if(length==0)
        {
            continue;
            t--;
        }

        for(i=0,j=0;i<length;i=i+2,j++)
        {
            str.push_back(c[i]);
            m[c[i]]=j;
            m1[j]=c[i];
            taken[c[i]]=0;
        }
        str[j]='\0';
        sort(str.begin(),str.begin()+j);
        gets(c);
        length=strlen(c);
        for(i=2;i<length;i=i+4)
        {
            check[m[c[i]]].push_back(m[c[i-2]]);
        }
        call();
        if(no!=1)
        {
            printf("NO\n");
        }
        if(t)
            cout<<endl;
        v.clear();
        str.clear();
        m.clear();
        m1.clear();
        getchar();
        for(i=0;i<=j+2;i++)
            check[i].clear();
    }
    return 0;
}
//4
//
//z a b c d e
//a b c d z a a e
//
//z a m n a q
//q a a n m z z q
//
//a b c d
//a c b d
//
//p o q a b c d e r
//p o q a b c d e r e d p a o r q r c r b
