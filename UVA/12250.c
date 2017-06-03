#include<stdio.h>
#include<string.h>
int main()
{
    int t=1;
    while(1)
    {
        char s[1000];
        int l;
        scanf("%s",s);
        if(strcmp(s,"HELLO")==0)
        {
            printf("Case %d: ENGLISH\n",t);
        }
        else if(strcmp(s,"HOLA")==0)
        {
            printf("Case %d: SPANISH\n",t);
        }
        else if(strcmp(s,"HALLO")==0)
        {
            printf("Case %d: GERMAN\n",t);
        }
        else if(strcmp(s,"BONJOUR")==0)
        {
            printf("Case %d: FRENCH\n",t);
        }
        else if(strcmp(s,"CIAO")==0)
        {
            printf("Case %d: ITALIAN\n",t);
        }
        else if(strcmp(s,"ZDRAVSTVUJTE")==0)
        {
            printf("Case %d: RUSSIAN\n",t);
        }
        else if(strcmp(s,"#")==0)
        {
            break;
        }
        else
        {
            printf("Case %d: UNKNOWN\n",t);
        }
        t++;
    }
    return 0;
}
