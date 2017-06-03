#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int n,i,j,k;
    char s[100];
    vector<string>name,song;

    song.push_back("Happy");
    song.push_back("birthday");
    song.push_back("to");
    song.push_back("you");
    song.push_back("Happy");
    song.push_back("birthday");
    song.push_back("to");
    song.push_back("you");
    song.push_back("Happy");
    song.push_back("birthday");
    song.push_back("to");
    song.push_back("Rujia");
    song.push_back("Happy");
    song.push_back("birthday");
    song.push_back("to");
    song.push_back("you");

    while(scanf("%d",&n)==1)
    {
        getchar();
        int loop=n/16;

        if(n%16==0);
        else
        {
            loop++;
            //cout<<loop<<endl;
            //continue;
        }

        for(i=0; i<n; i++)
        {
            scanf("%s",s);
            name.push_back(s);
        }

        for(i=0,j=0,k=0; i<loop*16; i++)
        {
            cout<<name[j]<<": "<<song[k]<<endl;
            j++;
            k++;
            if(j==n)
                j=0;
            if(k==16)
                k=0;
        }
        name.clear();
    }
    return 0;
}

