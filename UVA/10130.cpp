#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int weight[1000],price[1000],s[1000][1000],k_w[1000],p,a,b,t,T,n,ans,i,j,w,z,k,*q;

int main()
{
    scanf("%d",&T);
    for(t=1; t<=T; t++)
    {

        scanf("%d",&n);
        for(a=1; a<=n; a++)
        {
            scanf("%d %d",&price[a],&weight[a]);
        }
        scanf("%d",&p);
        ans=0;
        for(a=0; a<p; a++)
        {
            scanf("%d",&k);
            k_w[a]=k;
        }
        q=max_element(k_w,k_w+p);
        k=*q;
        for(i=0; i<=n; i++)
        {
            for(j=0; j<=k; j++)
            {
                s[i][j]=0;
            }
        }

        for(i=1; i<=n; i++)
        {
            for(w=1; w<=k; w++)
            {
                if(weight[i]>w)
                {
                    s[i][w]=s[i-1][w];
                }
                else
                {
                    if(s[i-1][w]>s[i-1][w-weight[i]]+price[i])
                    {
                        s[i][w]=s[i-1][w];
                    }
                    else
                    {
                        s[i][w]=s[i-1][w-weight[i]]+price[i];
                    }
                }
            }
        }
        for(a=0; a<p; a++)
        {
            k=k_w[a];
            ans=ans+s[n][k];
        }

        printf("%d\n",ans);
    }
    return 0;
}
