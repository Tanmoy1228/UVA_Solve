#include<stdio.h>
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n, &m);
        if(n>m)
        {
            printf(">\n");
        }
        else if(n<m)
        {
            printf("<\n");
        }
        else if(n==m)
        {
            printf("=\n");
        }
    }
    return 0;
}
