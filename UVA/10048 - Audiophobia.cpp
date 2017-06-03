#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int crossing,road,quarry,crossing1,crossing2,i,j,k,cost,t=1,ans;
    while(scanf("%lld %lld %lld",&crossing,&road,&quarry)!=EOF)
    {
        if(crossing==0 && road==0 && quarry==0)
            break;
        long long int mat[102][102];
        for(i=1; i<=crossing; i++)
        {
            for(j=1; j<=crossing; j++)
            {
                if(i==j)
                {
                    mat[i][j]=0;
                    continue;
                }
                mat[i][j]=9999999999;
            }
        }
        for(i=1; i<=road; i++)
        {
            scanf("%lld %lld %lld",&crossing1,&crossing2,&cost);
            mat[crossing1][crossing2]=min(mat[crossing1][crossing2],cost);
            mat[crossing2][crossing1]=mat[crossing1][crossing2];
        }
        for(k=1; k<=crossing; k++)
        {
            for(i=1; i<=crossing; i++)
            {
                for(j=1; j<=crossing; j++)
                {
                    if(i==j || i==k || j==k)
                        continue;
                    mat[i][j]=min(mat[i][j],max(mat[i][k],mat[k][j]));
                    mat[j][i]=mat[i][j];
                }
            }
        }
        if(t>1)
            printf("\n");
        printf("Case #%lld\n",t);
        t++;
        for(i=1; i<=quarry; i++)
        {
            scanf("%lld %lld",&crossing1,&crossing2);
            ans=mat[crossing1][crossing2];
            if(ans==9999999999)
                printf("no path\n");
            else
                printf("%lld\n",ans);
        }
    }
    return 0;
}


