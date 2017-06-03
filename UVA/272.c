#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000],q[1000];
    int a=0;
    while(gets(s))
    {
        int l,i,j=0,k;
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            if(s[i]=='"')
            {
                if(a%2==0)
                {
                    printf("``");
                    a++;
                }
                else if(a%2==1)
                {
                    printf("''");
                    a++;
                }
            }
            else
            {
                printf("%c",s[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
