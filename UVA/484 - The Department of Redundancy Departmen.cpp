#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    vector<long long int>m;
    vector<long long int>::iterator s,w;
    long long int a,i=10,l=0,n;
    while(scanf("%lld",&a)!=EOF)
    {
        m.push_back(a);
    }
    for(s=m.begin();s!=m.end();s++)
    {
        l=1;
        for(w=s+1;w!=m.end();w++)
        {
            if(*s==*w)
            {
                l++;
                m.erase(w);
                w--;
            }
        }
        printf("%lld %lld",*s,l);
        if(!m.empty())
        {
            printf("\n");
        }
    }
    return 0;
}
