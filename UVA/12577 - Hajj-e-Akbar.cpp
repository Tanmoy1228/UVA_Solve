#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
    long long int t=1,i,j;
    string input;
    while(1)
    {
        cin>>input;
        if(input=="*")
            break;
        if(input=="Hajj")
            printf("Case %lld: Hajj-e-Akbar\n",t);
        else if(input=="Umrah")
            printf("Case %lld: Hajj-e-Asghar\n",t);
        t++;
    }
    return 0;
}
