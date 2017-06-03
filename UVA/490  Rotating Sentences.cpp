#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
    char a[10000];
    int l=0,i=0,j;
    vector<string>s[200],p;
    vector<string>::iterator z,y;
    while(scanf("%s",&a)!=EOF)
    {
        s[i].push_back(a);
        i++;
    }
    i=0;
    for(z=s[i].begin();z!=s[i].end();z++)
    {
        i=p.size();
        if(l<i)
        {
            l=i;
        }
    }
    for(j=0;j<l;j++)
    {
        for(z=s.end;z!=s.begin();z--)
        {
            p=*z;
            if(p[i])
            printf("%c",p[i]);
        }
        printf("\n");
    }
    return 0;
}
