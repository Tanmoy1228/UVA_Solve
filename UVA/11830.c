#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    while(scanf("%d",&n))
    {
        int i,j=0,k,l;
        char s[10000],q[10000];
        scanf("%s",s);
        if(n==0 && strcmp(s,"0")==0)
        {
            break;
        }
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            k=s[i]-'0';
            if(k==n || (j==0 && k==0))
            {
                continue;
            }
            q[j]=s[i];
            j++;
        }
        if(j==0)
        {
            printf("0\n");
            continue;
        }
        for(i=0;i<j;i++)
        {
            printf("%c",q[i]);
        }
        printf("\n");
    }
    return 0;
}
