#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

char arr[100];
vector<char>result;
bool taken[100];
int n,m;

void reset()
{
//    Clear(arr);
//    Clear(taken);
    result.clear();
}

void print()
{
    for(int i=0; i<m; i++)
        cout<<result[i];
    cout<<endl;
}

void call()
{
    if(result.size()==m)
        print();
    else
        for(int i=0; i<n; i++)
        {
            if(!result.empty() && result[result.size()-1]>arr[i])
                continue;
            if(taken[i]==0)
            {
                taken[i]=1;
                result.push_back(arr[i]);
                cout<<arr[i]<<endl;
                call();
                taken[i]=0;
                result.pop_back();
//                while(arr[i]==arr[i+1])
//                    i++;
            }
        }
}

int main()
{
    while(cin>>arr>>m)
    {
        n=strlen(arr);
        sort(arr,arr+n);

        call();

        reset();
    }
}
