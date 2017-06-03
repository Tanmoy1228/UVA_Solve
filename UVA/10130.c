#include<stdio.h>
int price[1010],carry[110],weight[1010],c,s[1010][110],n,t,T,i,j,k,l,z,m,ans;
int max_m(int x, int y)
{
    if(x>y)
    {

        return x;
    }
    else
    {
        return y;
    }
}
int super(int a,int b,int c)
{
    int t1,t2;
    t1=0;
    t2=0;
    if(a==n+1)
    {
        return 0;
    }
    if(s[a][b]!=-1)
    {
        return s[a][b];
    }

    if(b+weight[a]<=c)
    {
        t1=price[a]+super(a+1,b+weight[a],c);
    }
    else
    {
        t1=0;
    }
    t2=super(a+1,b,c);
    if(t1>t2)
    {
        printf("%d\n",a);
        s[a][b]=t1;
    }
    else
    {
        s[a][b]=t2;
    }
    return s[a][b];
}
int main()
{
    scanf("%d",&t);
    for(T=1; T<=t; T++)
    {
        ans=0;
        scanf("%d",&n);
        k=0;
        for(j=1; j<=n; j++)
        {
            scanf("%d %d",&price[j],&weight[j]);
        }

        scanf("%d",&m);
        for(j=0; j<m; j++)
        {
            scanf("%d",&carry[j]);
            z=carry[j];
            for(i=0; i<=n+2; i++)
            {
                for(l=0; l<=z+2; l++)
                {
                    s[i][l]=-1;
                }
            }
            k=super(1,0,z);
            ans=ans+k;
        }
        printf("%d\n",ans);
    }
    return 0;
}
