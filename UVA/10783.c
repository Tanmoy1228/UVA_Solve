#include<stdio.h>
int main()
{
    int t, test=0, n, k, m, i;
    scanf("%d", &t);
    while(++test<=t)
    {
        scanf("%d", &n);
        scanf("%d", &m);
        int j=0, l;
        for(k=n; k<=m; k++)
        {
            l=k;
            if(k%2==1)
            {
                j=j+l;
            }
        }
        printf("Case %d: %d\n", test, j);
    }

    return 0;
}
