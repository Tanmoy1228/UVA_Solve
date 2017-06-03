#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        if(a==-1 && b==-1)
        {
            break;
        }
        c=fabs(a-b);
        if(c>50)
        {
            c=100-c;
        }
        printf("%d\n",c);
    }
    return 0;
}
