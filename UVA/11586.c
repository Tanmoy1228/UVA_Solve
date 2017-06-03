#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        char s[10000];
        int i,l,m=0,a,f=0;
        gets (s);
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            if(s[i]=='M')
            {
                m++;
            }
            else if(s[i]=='F')
            {
                f++;
            }
        }
        if(m==f && m>1 && f>1)
        {
            printf("LOOP\n");
        }
        else
        {
            printf("NO LOOP\n");
        }
    }
    return 0;
}
