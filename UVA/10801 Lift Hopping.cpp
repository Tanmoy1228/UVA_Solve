#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

int main()
{
    long long int n,k;
    while(scanf("%lld %lld",&n,&k)!=EOF)
    {
        int cost1[10],arr[10][110],cost2[100][100];
        int i,j,l,a,b,c,m;
        char path[500],cos[10];
        vector<int>v[100];
        for(i=1;i<n;i++)
        {
            scanf("%d",&cost1[i]);
        }

        gets(cos);
        a=atoi(cos);
        cost1[i]=a;

        for(i=1;i<=n;i++)
        {
            gets(path);
            l=strlen(path);
            c=0;
            a=0;
            for(j=0;j<l;j++)
            {
                m=path[j+1];
                if(m==' ' || m=='\0')
                {
                    b=path[j]-'0'+a;
                    arr[i][c]=b;
                    a=0;
                    j++;
                    c++;
                    continue;
                }

                a=path[j]-'0';
                a=a*10;
            }
        }
    }
    return 0;
}
