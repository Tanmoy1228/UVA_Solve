#include<stdio.h>
int main ()
{
    int t=1, T;
    scanf("%d", &T);
    while(t<=T)
    {
        int n, i, a[20];
        scanf("%d", &n);
        for(i=0; i<n; i++)
        {
            scanf("%d", &a[i]);
        }
        printf("Case %d: %d\n", t, a[n/2]);
        t++;
    }
    return 0;
}
