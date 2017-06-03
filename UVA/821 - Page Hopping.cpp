#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
    int a,b,i,j,k,t=1;
    int mat[102][102];
    while(scanf("%d %d",&a,&b))
    {
        if(a==0 && b==0)
        {
            break;
        }

        for(i=1; i<=101; i++)
        {
            for(j=1; j<=101; j++)
            {
                if(i==j)
                    mat[i][j]=0;
                mat[i][j]=100000;
            }
        }
        mat[a][b]=1;
        while(scanf("%d %d",&a,&b))
        {
            if(a==0 && b==0)
            {
                break;
            }
            mat[a][b]=1;
        }
        for(k=1; k<=100; k++)
        {
            for(i=1; i<=100; i++)
            {
                for(j=1; j<=100; j++)
                {
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }
        int c=0;
        double total=0.0;
        for(i=1; i<=100; i++)
        {
            for(j=1; j<=100; j++)
            {
                if(mat[i][j]==100000 || i==j)
                {
                    continue;
                }
                else
                {
                    total=total+mat[i][j];
                    c++;
                }
            }
        }
        double to;
        to=total/c;
        printf("Case %d: average length between pages = %0.3lf clicks\n",t,to);
        t++;

    }
    return 0;
}
