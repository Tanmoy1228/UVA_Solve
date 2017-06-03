#include<stdio.h>
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int L, G, i, j, a=-1, b;
        scanf("%d %d", &G, &L);
        if(L%G==0)
        {
            printf("%d %d\n", G, L);
        }
        else
        {
            printf("-1\n");
        }
    }

    return 0;
}
