#include<iostream>
#include<cstring>
#include<string>
#include<set>
int main()
{
    set<string>dic;
    string s;
    char sr[1000];
    int i,l;
    while(scasnf("%s",c)!=EOF)
    {
        l=strlen(c);
        for(i=0;i<l;i++)
        {
            if(c[i]>='A' && c[i]<='Z')
            {
                c[i]=c[i]+32;
            }
        }
        s=c;
        l=s.size();
        for(i=0;i<l;i++)
        {
            dic.push(s[i]);
        }
        for(i=0;i<l;i++)
        {
            cout<<s[i]<<endl;
        }
    }
    s.clear();
    return 0;
}
