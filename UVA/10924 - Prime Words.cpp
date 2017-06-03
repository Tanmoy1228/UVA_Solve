#include<bits/stdc++.h>
#define ll long long int
#define MAX 1100
using namespace std;

bool isPrime[MAX+5];
void seive_N_logN(ll N)
{
    ///calculate prime upto N in NlogN time
    memset(isPrime,true,sizeof isPrime);
    //prime.clear();

    //isPrime[1]=false;
    for (ll i = 4; i<= N; i=i+2)
        isPrime[i]=false;

    for (ll i = 3; i * i<= N; i=i+2)
    {
        if (isPrime[i])
        {
            for (ll j = i * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }
//    for(ll i=1; i<MAX; i++)
//        if(isPrime[i])
//            prime.push_back(i);
}

int main()
{
    ll n,m,i,j,ans;
    string s;
    seive_N_logN(MAX);
    while(cin>>s)
    {
        ans=0;
        n=s.size();
        for(i=0;i<n;i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                ans += s[i]-'a'+1;
            }
            else if(s[i]>='A' && s[i]<='Z')
            {
                ans += s[i]-'A'+26+1;
            }
        }

        if(isPrime[ans])
            printf("It is a prime word.\n");
        else
            printf("It is not a prime word.\n");
    }

    return 0;
}

