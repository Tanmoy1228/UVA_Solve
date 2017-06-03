#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int t=1,T,R,N;
    while(scanf("%d %d",&R,&N)!=EOF)
    {

        if(R==0 || N==0)
            break;
        R=R-N;
        int a=R/N;
        if(a*N<R)
            a++;
        if(a>26)
            printf("Case %d: impossible\n",t);
        else
            printf("Case %d: %d\n",t,a);
        t++;
    }
    return 0;
}
