#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
int main()
{
    char s[10000],c[10000];
    set<string>dic;
    set<string>::iterator g;
    long long int i,l,j=0,k;
    while(scanf("%s",s)!=EOF)
    {
        l=strlen(s);
        j=0;
        for(i=0;i<l;i++)
        {

            if(s[i]>='A' && s[i]<='Z')
            {
                c[j]=s[i]+32;
                j++;
            }
            else if(s[i]>='a' && s[i]<='z')
            {
                c[j]=s[i];
                j++;
            }
            else
            {
                c[j]='\0';
                if(strlen(c))
                dic.insert(c);
                j=0;
            }
            if(s[i+1]=='\0')
            {
                c[j]='\0';
                if(strlen(c))
                dic.insert(c);
            }
        }
    }
    for(g=dic.begin();g!=dic.end();g++)
    {
        cout<<*g<<endl;
    }
    return 0;
}

