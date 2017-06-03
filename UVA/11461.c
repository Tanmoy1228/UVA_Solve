#include<stdio.h>
#include<math.h>
int main()
{
    int a, b;
    while(scanf("%d %d", &a, &b)==2)
    {
        int i, j, k, c=0;
        if(a==0 && b==0)
        {
            break;
        }
        for(i=a; i<=b; i++)
        {
            j = sqrt(i);
            k = j*j;
            if(k==i)
            {
                c++;
            }
        }
        printf("%d\n", c);
    }
    return 0;
}
