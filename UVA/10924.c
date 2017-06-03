#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char s[100];
    while(scanf("%s",s)!=EOF)
    {
        int i,j,l,x,y=0,z=0;
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            if(s[i]>=65 && s[i]<=90)
            {
                x=s[i]-38;
            }
            else if(s[i]>=97 && s[i]<=122)
            {
                x=s[i]-96;
            }
            y=y+x;
        }
        for(j=2;j<=sqrt(y);j++)
        {
            if(y%j==0)
            {
                printf("It is not a prime word.\n");
                z=1;
                break;
            }
        }
        if(z==1)
        {
            continue;
        }
        printf("It is a prime word.\n");
    }
    return 0;
}
