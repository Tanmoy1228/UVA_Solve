#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll num[105];
ll gcd(ll a,ll b)
{
    if(b)
        return gcd(b,a%b);
    return a;
}

int main()
{
    ll c=0,i=0,j=0,k,m;
    char str[100];
    scanf("%lld",&c);
    getchar();
    while(c--)
    {
        gets(str);
        i = 0;
        j = 0;
        while(str[i])
        {
            num[j]=0;
            while(str[i] && str[i]!=' ')
                num[j]=num[j]*10 + str[i++]-'0';
            while(str[i]==' ')
                i++;
            //cout<<num[j]<<endl;
            j++;
        }
        m = 1;
        for(i=0; i<j; i++)
            for(k=i+1; k<j; k++)
                m = max(m,gcd(num[i],num[k]));
        printf("%lld\n",m);
    }
    return 0;
}
