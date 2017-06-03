#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n,length,total_per;
char s[100];
vector<char>per;
int taken[105];

void per_call()
{
    int i;
    if(per.size()==n)
    {
        int j;
        for(j=0; j< n; j++)
        {
            printf("%c",per[j]);
        }
        printf("\n");
        return;
    }
    else
        for(i=0; i<length; i++)
        {
            if(!per.empty() && per[per.size()-1]>s[i])
                continue;
            if(taken[i]==0)
            {
                taken[i]=1;
                per.push_back(s[i]);
                per_call();
                taken[i]=0;
                per.pop_back();

                while(s[i]==s[i+1])
                {
                    i++;
                }
            }
        }
        return;
}

int main()
{
    while(cin>>s>>n)
    {
        length=strlen(s);
        int i;
        for(i=0; i<length+5; i++)
        {
            taken[i]=0;
        }
        sort(s,s+length);

        per_call();
        getchar();
        per.clear();

    }
    return 0;
}
