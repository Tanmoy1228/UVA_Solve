#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
vector<int>ring;
int taken[20];
bool check[20];
void call()
{
    int i,k,z;
    if(ring.size()==n)
    {
        for(i=0;i<n-1;i++)
            cout<<ring[i]<<" ";
        cout<<ring[i]<<endl;
        return;
    }
    for(i=2;i<=n;i++)
    {
        k=ring.back();
        if(ring.size()==0)
        {
            break;
        }
        if(taken[i]==0 && check[i+k]!=true && !(ring.size()==n-1 && check[1+i]==true))
        {

            taken[i]=1;
            ring.push_back(i);

            call();
            taken[i]=0;
            ring.pop_back();
        }
    }
    return;
}

int main()
{
    int t=0,i,j;

    for(i=4;i<=2*18;i++)
    {
        check[i]=false;
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                check[i]=true;
                break;
            }
        }
    }

    while(cin>>n)
    {
        if(t)
            cout<<endl;
        printf("Case %d:\n",t+1);
        t++;
        for(j=0;j<=n+2;j++)
        {
            taken[j]=0;
        }
        ring.push_back(1);
        call();
        ring.clear();
    }
    return 0;
}
