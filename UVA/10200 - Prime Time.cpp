#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
bool status(long long int n,long long int p)
{
    return bool(n & (1<<p));
}
int setprime(long long int n,long long int p)
{
    return n=(n | (1<<p));
}
long long int check[100011105/30];
int main()
{
    long long int n=100011000,i,j,c=0,x,y,k,l;

    l=sqrt(n);
//    for(i=2;i<=n;i=i+2)
//    {
//        check[i]=true;
//    }
    for(i=3;i<=l;i=i+2)
    {
        if(status(check[i>>5],i&31)==0)
        {
            for(j=i*i;j<n;j=j+2*i)
            {
                check[j>>5]=setprime(check[j>>5],j&31);
            }
        }
    }
//    check[1]=false;
//    check[2]=false;
//    for(i=1;i<=200;i++)
//    {
//        if(status(check[i/32],i%32)==0)
//        {
//            cout<<i<<"  ";
//        }
//    }
    while(scanf("%lld %lld",&x,&y)!=EOF)
    {
        double v;
        long long int z=0;
        for(k=x;k<=y;k++)
        {
            if(status(check[(k*k+k+41)>>5],(k*k+k+41)&31)==0)
            {
                //cout<<k*k+k+41<<"  ";
                z++;
            }
        }
        v=(double)(1.0*(z*100)/(y-x+1));
        printf("%0.2lf\n",v+1e-8);
    }
    return 0;
}

