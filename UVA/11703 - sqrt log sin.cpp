#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll arr[1000009],i,j;
int main()
{

    arr[0]=1;
    for(j=1;j<=1000002;j++)
    {
        ll a=floor(j-sqrt(j));
        ll b=floor(log(j));
        ll c=floor(j*sin(j)*sin(j));

        arr[j]=(arr[a] + arr[b] + arr[c])%1000000;
    }
        //arr[j]=(arr[ (int)floor(j-sqrt(j)) ] + arr[ (int)floor(log(j)) ] + arr[ (int)floor(j*pow(sin(i),2)) ])%1000000;
    while(cin>>i && i!=-1)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
