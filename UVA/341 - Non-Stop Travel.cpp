#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
long long int mat[10000][10000],next[10000][10000];

int main()
{
    long long int n,t=1;
    while(scanf("%lld",&n)!=EOF)
    {
        long long int i,j,k,intersec,road,time_sec,first,last;
        if(n==0)
        {
            break;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                mat[i][j]=9999999999;
                next[i][j]=j;
            }
        }
        for(i=1; i<=n; i++)
        {
            scanf("%lld",&intersec);
            for(j=1; j<=intersec; j++)
            {
                scanf("%lld %lld",&road,&time_sec);
                mat[i][road]=time_sec;
            }
        }
        scanf("%lld %lld",&first,&last);
        for(k=1; k<=n; k++)
        {
            for(i=1; i<=n; i++)
            {
                for(j=1; j<=n; j++)
                {
                    if(mat[i][j]>mat[i][k]+mat[k][j])
                    {
                        mat[i][j]=mat[i][k]+mat[k][j];
                        next[i][j]=next[i][k];
                    }
                }
            }
        }
        i=first;
        j=last;
//        for(i=1;i<=n;i++)
//        {
//            for(j=1;j<=n;j++)
//            {
//                cout<<i<<"  "<<j<<"->"<<next[i][j]<<"\n";
//            }
//            cout<<endl;
//        }
        printf("Case %lld: Path =",t);
        printf(" %lld",first);
        while(i!=j)
        {

            printf(" %lld",next[i][j]);
            i=next[i][j];
        }
        printf("; %lld second delay\n",mat[first][last]);
        t++;
    }
    return 0;
}
