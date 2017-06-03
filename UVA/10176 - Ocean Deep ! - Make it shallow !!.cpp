#include<iostream>
#include<stack>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
    long long int i,j=0,l,k,q;
    char s;
    while(scanf("%c",&s)!=EOF)
    {
        if(s=='#')
        {
            if(j%131071==0)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
            j=0;
            continue;
        }
        if(s=='1' || s=='0')
        {
            k=s-'0';
            j=j*2+k;
            j=j%131071;
        }

    }
    return 0;
}
