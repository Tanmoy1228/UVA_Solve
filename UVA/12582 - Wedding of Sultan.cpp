#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,T,n,i,j,a,b,l;
    scanf("%d",&T);
    getchar();
    for(t=1; t<=T; t++)
    {
        //char str[10000];
        string str;
        map<int , int >m;
        map<int , int >::iterator mt;
        vector<int>v;
        //scanf("%s",&str);
        cin>>str;
        m.clear();
        v.clear();
        for(i=0; i<str.length(); i++)
            v.push_back(str[i]-'0');
        l=str.length();
        for(i=0; i<v.size(); i++)
        {
            if(i<0)
                break;
            m[v[i]]++;
            //printf("%c\n",v[i]+'0');
            if(v[i]==v[i+1])
            {
                v.erase(v.begin()+i);
                v.erase(v.begin()+i);
                i=i-2;
            }
        }
        m[v[l-1]]--;
        printf("Case %d\n",t);
        for(mt=m.begin();mt!=m.end();mt++)
        {
            a=mt->first;
            b=mt->second;
            printf("%c = %d\n",a+'0',b);
        }
    }
    return 0;
}
