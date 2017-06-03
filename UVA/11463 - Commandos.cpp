#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
    int t,T;
    scanf("%d",&T);
    for(t=1; t<=T; t++)
    {
        int building,road,road1,road2,i,j,k;
        int mat[102][102];
        scanf("%d",&building);
        scanf("%d",&road);
        for(i=1; i<=building; i++)
        {
            for(j=1; j<=building; j++)
            {
                if(i==j)
                {
                    mat[i][j]=0;
                    continue;
                }
                mat[i][j]=9999;
            }
        }
        for(i=1; i<=road; i++)
        {
            scanf("%d %d",&road1,&road2);
            mat[road1+1][road2+1]=1;
            mat[road2+1][road1+1]=1;
        }
        scanf("%d %d",&road1,&road2);
        for(k=1; k<=building; k++)
        {
            for(i=1; i<=building; i++)
            {
                for(j=1; j<=building; j++)
                {
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                    mat[j][i]=mat[i][j];
                }
            }
        }
//        for(i=1; i<=building; i++)
//        {
//            for(j=1; j<=building; j++)
//            {
//                cout<<mat[i][j]<<"  ";
//            }
//            cout<<endl;
//        }
        int cost=0;
        for(i=1; i<=building; i++)
        {
            cost=max(cost,mat[road1+1][i]+mat[road2+1][i]);
        }
        printf("Case %d: %d\n",t,cost);
    }
    return 0;
}
