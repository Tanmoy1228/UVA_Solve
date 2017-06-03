#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(a>=b+c || b>=c+a || c>=a+b)
        {
            printf("Wrong!!\n");
        }
        else
        {
            printf("OK\n");
        }
    }
    return 0;
}
