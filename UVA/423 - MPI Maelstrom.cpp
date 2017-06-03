#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
    long long int n;
    while(scanf("%lld",&n)!=EOF)
    {
        long long int i,j,k,counter,cost,mincost=9999999999;
        char c[5];
        counter=0;
        long long int mat[102][102];
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=i; j++)
            {
                if(i==j)
                {
                    mat[i][j]=0;
                    continue;
                }

                scanf("%s",c);
                if(c[0]=='x')
                {
                    mat[i][j]=9999999999;
                }
                else
                {
                    sscanf(c,"%lld",&mat[i][j]);

                }
                mat[j][i]=mat[i][j];
            }
        }


        for(k=1; k<=n; k++)
        {
            for(i=1; i<=n; i++)
            {
                for(j=1; j<=n; j++)
                {
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                    mat[j][i]=mat[i][j];
                }
            }
        }
        cost=0;
        for(i=1; i<=n; i++)
        {
            cost=max(cost,mat[1][i]);
        }
        cout<<cost<<endl;
//
//        for(i=1;i<=n;i++)
//        {
//            for(j=1;j<=n;j++)
//            {
//                printf("%5lld",mat[i][j]);
//            }
//            cout<<endl;
//        }
    }
    return 0;
}
