#include<stdio.h>
int main()
{
    int t=1,n,m,c;
    while(scanf("%d",&n)!=EOF)
    {
        c=0;
        m=1;
        if(n<0)
        {
            break;
        }
        while(m<n)
        {
            m=2*m;
            c++;
        }
        printf("Case %d: %d\n",t,c);
        t++;
    }
    return 0;
}
