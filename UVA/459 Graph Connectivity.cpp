#include<bits/stdc++.h>
using namespace std;
bool mark[100000];
long long int par[100000];
int findpar(long long int p)
{
    if(par[p]==p)
        return p;
    else
        return par[p]=findpar(par[p]);
}
int main()
{
    long long int T;
    scanf("%lld",&T);
    getchar();
    getchar();

    while(T--)
    {
        char ch1[10],ch[10];
        long long int i,j,k,length,a,b,c=0;
        //getchar();

        gets(ch1);
        memset(mark,false,sizeof mark);
        for(i=1; i<=ch1[0]-'A'+1; i++)
            par[i]=i;
        while(gets(ch) && ch[0]!='\0')
        {
            a=findpar(ch[0]-'A'+1);
            b=findpar(ch[1]-'A'+1);
            if(a==b)
                continue;
            par[a]=b;
            //cout<<a<<" "<<b<<endl;
        }
        c=0;
        for(i=1; i<=ch1[0]-'A'+1; i++)
        {
            findpar(i);
            //cout<<par[i]<<endl;
            if(!mark[par[i]])
            {
                mark[par[i]]=true;
                c++;
            }
        }
        printf("%lld\n",c);
        if(T)
            cout<<endl;

    }
    return 0;
}

//3
//
//E
//AB
//CE
//DB
//EC
//
//
//E
//AB
//CE
//DB
//EC
//
//
//E
//AB
//CE
//DB
//EC
//

