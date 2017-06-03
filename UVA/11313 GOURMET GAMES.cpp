#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int T,t;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,k,l,a,b;
        scanf("%d %d",&n,&m);

        k=n;
        l=0;
        while(k>m)
        {
            a=k%m;
            b=k/m;
            l=l+b;
            k=a+b;
        }
        if(k==m)
        {
            printf("%d\n",l+1);
        }
        else
        {
            printf("cannot do this\n");
        }
    }
    return 0;
}
