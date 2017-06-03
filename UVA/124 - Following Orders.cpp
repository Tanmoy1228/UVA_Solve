#include<bits/stdc++.h>
using namespace std;
map<char,int>m;
map<int,char>m1;
map<char,int>taken;
vector<char>v,str;
vector<int>check[26];
int length,j;
//char str[26];
void call()
{
    int i,l;
    if(v.size()==j)
    {
        for(i=0; i<j; i++)
            printf("%c",v[i]);
        cout<<endl;
        return;
    }
    for(i=0; i<j; i++)
    {
        if(taken[str[i]]!=1)
        {
            l=check[m[str[i]]].size();
            int z=5;
            if(l==0)
            {
                taken[str[i]]=1;
                v.push_back(str[i]);
                call();
                v.pop_back();
                taken[str[i]]=0;
            }

            for(int k=0;k<l;k++)
            {
                if(count(v.begin(),v.end(),m1[check[m[str[i]]][k]])>0)
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
                v.pop_back();
                taken[str[i]]=0;
            }
        }
    }
}
int main()
{
    char c[50],s[26];
    int t=0;
    while(gets(c))
    {
        int i=0;
        m.clear();
        m1.clear();
        taken.clear();
        v.clear();
        str.clear();
        for(i=0; i<j+2; i++)
            check[i].clear();
        length=strlen(c);
        if(length==0)
            break;
        for(i=0,j=0; i<length; i=i+2,j++)
        {
            str.push_back(c[i]);
            m[str[j]]=j;
            m1[j]=str[j];
            taken[str[j]]=0;
        }
        str[j]='\0';
        sort(str.begin(),str.begin()+j);
        gets(c);
        length=strlen(c);
        for(i=2; i<length; i=i+4)
        {
            check[m[c[i]]].push_back(m[c[i-2]]);
        }
        if(t!=0)
            cout<<endl;
        call();
        t++;
    }
    return 0;
}
