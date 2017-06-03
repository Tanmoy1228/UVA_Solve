#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s[1000],q[1000];
        int l,i;
        getchar();
        gets(s);
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            if(s[i]=='0')
            {
                q[i]='O';
            }
            else if(s[i]=='1')
            {
                q[i]='I';
            }
            else if(s[i]=='2')
            {
                q[i]='Z';
            }
            else if(s[i]=='3')
            {
                q[i]='E';
            }
            else if(s[i]=='4')
            {
                q[i]='A';
            }
            else if(s[i]=='5')
            {
                q[i]='S';
            }
            else if(s[i]=='6')
            {
                q[i]='G';
            }
            else if(s[i]=='7')
            {
                q[i]='T';
            }
            else if(s[i]=='8')
            {
                q[i]='B';
            }
            else if(s[i]=='9')
            {
                q[i]='P';
            }
            else
            {
                q[i]=s[i];
            }
        }
        for(i=0;i<l;i++)
        {
            printf("%c",q[i]);
        }
        printf("\n");
    }
    return 0;
}
