#include<stdio.h>
#include<string.h>
int main()
{
    int t=1,T;
    scanf("%d",&T);
    while(t<=T)
    {
        char s[1000];
        int i,l;
        scanf("%s",s);
        l=strlen(s);
        if(l==3)
        {
            if((s[0]=='o' && s[1]=='n') || (s[0]=='o' && s[2]=='e') || (s[1]=='n' && s[2]=='e') || (s[1]=='n' && s[2]=='e' && s[0]=='o'))
            {
                printf("1\n");
            }
            if((s[0]=='t' && s[1]=='w') || (s[0]=='t' && s[2]=='o') || (s[1]=='w' && s[2]=='o'))
            {
                printf("2\n");
            }
        }
        else if(l==5)
        {
            printf("3\n");
        }
        t++;
    }
    return 0;
}
