#include<stdio.h>
#include<string.h>
int main()
{
    char s[10000];
    while(scanf("%s",s))
    {
        int i,j,k,l,a=0,b=0,c=0;
        char x[10000],y[10000];
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            x[l-1-i]=s[i];
        }
        if(strcmp(x,s)==0)
        {
            a=1;
        }
        for(i=0;i<l;i++)
        {
            if(s[i]=='A')
            {
                y[l-1-i]='A';
            }
            else if(s[i]=='E')
            {
                y[l-1-i]='3';
            }
            else if(s[i]=='H')
            {
                y[l-1-i]='H';
            }
            else if(s[i]=='I')
            {
                y[l-1-i]='I';
            }
            else if(s[i]=='J')
            {
                y[l-1-i]='L';
            }
            else if(s[i]=='L')
            {
                y[l-1-i]='J';
            }
            else if(s[i]=='M')
            {
                y[l-1-i]='M';
            }
            else if(s[i]=='O')
            {
                y[l-1-i]='O';
            }
            else if(s[i]=='S')
            {
                y[l-1-i]='2';
            }
            else if(s[i]=='T')
            {
                y[l-1-i]='T';
            }
            else if(s[i]=='U')
            {
                y[l-1-i]='U';
            }
            else if(s[i]=='V')
            {
                y[l-1-i]='V';
            }
            else if(s[i]=='W')
            {
                y[l-1-i]='W';
            }
            else if(s[i]=='X')
            {
                y[l-1-i]='X';
            }
            else if(s[i]=='Y')
            {
                y[l-1-i]='Y';
            }
            else if(s[i]=='Z')
            {
                y[l-1-i]='5';
            }
            else if(s[i]=='1')
            {
                y[l-1-i]='1';
            }
            else if(s[i]=='2')
            {
                y[l-1-i]='S';
            }
            else if(s[i]=='3')
            {
                y[l-1-i]='E';
            }
            else if(s[i]=='5')
            {
                y[l-1-i]='Z';
            }
            else if(s[i]=='8')
            {
                y[l-1-i]='8';
            }
            else
            {
                b=1;
                break;
            }
        }
        if(strcmp(s,y)==0 && b==0)
        {
            c=1;
        }
        if(a==1 && c==1)
        {
            printf("%s -- is a mirrored palindrome.\n",s);
        }
        else if(a==0 && c==0)
        {
            printf("%s -- is not a palindrome.\n",s);
        }
        else if(a==1 && c==0)
        {
            printf("%s -- is a regular palindrome.\n",s);
        }
        else if(a==0 && c==1)
        {
            printf("%s -- is a mirrored string.\n",s);
        }
        printf("\n");
    }
    return 0;
}
