#include<stdio.h>
#include<string.h>
int main()
{
    while(1)
    {
        char s[10000];
        int i,j=0,l;
        gets(s);
        if(strcmp(s,"*")==0)
        {
            break;
        }
        l=strlen(s);
        for(i=1;i<l-1;i++)
        {
            if(s[i]==' ')
            {
                if(s[i+1]==s[0] || s[i+1]==s[0]+32 || s[i+1]==s[0]-32)
                {
                    continue;
                }
                else
                {
                    printf("N\n");
                    j=1;
                    break;
                }
            }
            if(j==1)
            {
                break;
            }
        }
        if(j==1)
        {
            continue;
        }
        printf("Y\n");
    }
    return 0;
}
