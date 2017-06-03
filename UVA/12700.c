#include<stdio.h>
int main()
{
    int t=1,T;
    scanf("%d",&T);
    while(t<=T)
    {
        char s[1000];
        int i,j,B=0,W=0,T=0,A=0,n;
        scanf("%d",&n);
        scanf("%s",s);
        if(n==0)
        {
            break;
        }
        for(i=0;i<n;i++)
        {
            if(s[i]=='B')
            {
                B++;
            }
            else if(s[i]=='W')
            {
                W++;
            }
            else if(s[i]=='T')
            {
                T++;
            }
            else if(s[i]=='A')
            {
                A++;
            }
        }
        if(W==0 && T==0 && B!=0)
        {
            printf("Case %d: BANGLAWASH\n",t);
        }
        else if(B==0 && T==0 && W!=0)
        {
            printf("Case %d: WHITEWASH\n",t);
        }
        else if(B==0 && T==0 && W==0 && A!=0)
        {
            printf("Case %d: ABANDONED\n",t);
        }
        else
        {
            if(B>W)
            {
                printf("Case %d: BANGLADESH %d - %d\n",t,B,W);
            }
            else if(B<W)
            {
                printf("Case %d: WWW %d - %d\n",t,W,B);
            }
            else if(B==W)
            {
                printf("Case %d: DRAW %d %d\n",t,W,T);
            }
        }
        t++;
    }
    return 0;
}
