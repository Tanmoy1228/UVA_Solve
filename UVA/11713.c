#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char x[100],y[100];
        int l1,l2,i,j,z=1;
        scanf("%s",x);
        scanf("%s",y);
        l1=strlen(x);
        l2=strlen(y);
        if(l1==l2)
        {
            for(i=0;i<l1;i++)
            {
                if(x[i]==y[i])
                {
                    continue;
                }
                else if((x[i]=='a' || x[i]=='e' || x[i]=='i' || x[i]=='o' || x[i]=='u') && (y[i]=='a' || y[i]=='e' || y[i]=='i' || y[i]=='o' || y[i]=='u'))
                {
                    continue;
                }
                else
                {
                    z=0;
                    printf("No\n");
                    break;
                }
            }
            if(z==1)
            {
                printf("Yes\n");
            }
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
