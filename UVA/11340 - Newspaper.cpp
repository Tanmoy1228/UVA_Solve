#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
int main()
{
    //freopen("tanmoy.txt","r",stdin);
    map<char,int>m;
    unsigned char a;
    char y[20000],z[10000];
    long long int t,b,i,x,l,j,n;
    double c;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld\n",&n);
        for(i=0;i<n;i++)
        {
            gets(z);
            sscanf(z,"%c %lld",&a,&b);
            m[a]=b;
        }
        scanf("%lld\n",&x);
        c=0;
        for(i=0;i<x;i++)
        {
            gets(y);
            l=strlen(y);
            for(j=0;j<l;j++)
            {
                a=y[j];
                if(m[a])
                {
                    c=c+m[a];
                }
            }
        }
        c=c/100.0;
        printf("%0.2lf$\n",c);
    }
    return 0;
}
