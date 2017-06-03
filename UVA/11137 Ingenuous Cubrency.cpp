#include<bits/stdc++.h>
using namespace std;
long long int coin[22][10000];
long long int call(long long int i, long long int n)
{
    long long int t1=0,t2=0;
    if(n==0)
        return 1;
    if(i>21)
        return 0;
    if(coin[i][n]!=-1)
        return coin[i][n];
    if(n-(i*i*i)>=0)
    {
        t1=call(i,n-(i*i*i));
    }
    t2=call(i+1,n);
    return coin[i][n]=t1+t2;
}

int main()
{
    long long int n,l,i,j;
    memset(coin,-1,sizeof coin);
    call(1,10000);
    while(scanf("%lld",&n)!=EOF)
    {
        l=call(1,n);
        printf("%lld\n",l);
    }
    return 0;
}
