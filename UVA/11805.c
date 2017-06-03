#include<stdio.h>
int main()
{
    int t=1,T;
    scanf("%d",&T);
    while(t<=T)
    {
        int n,k,p,i,j;
        scanf("%d %d %d",&n,&k,&p);
        j=k;
        for(i=1;i<=p;i++)
        {
            if(j==n)
            {
                j=0;
            }
            j++;
        }
        printf("Case %d: %d\n",t,j);
        t++;
    }
    return 0;
}
