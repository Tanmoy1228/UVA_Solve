#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        long long int sum=0;
        for(int i=0;i<s.size();i++)
        {
           if((s[i]=='B'||s[i]=='F'||s[i]=='P'||s[i]=='V')&&(s[i-1]!='B'&&s[i-1]!='F'&&s[i-1]!='P'&&s[i-1]!='V'))
           {
               sum=sum*10+1;
           }

           else if((s[i]=='C'||s[i]=='G'||s[i]=='J'||s[i]=='K'||s[i]=='Q'||s[i]=='S'||s[i]=='X'||s[i]=='Z')&&(s[i-1]!='C'&&s[i-1]!='G'&&s[i-1]!='J'&&s[i-1]!='K'&&s[i-1]!='Q'&&s[i-1]!='S'&&s[i-1]!='X'&&s[i-1]!='Z'))
           {
               sum=sum*10+2;
           }
           else if((s[i]=='D'||s[i]=='T')&&(s[i-1]!='D'&&s[i-1]!='T'))
           {
               sum=sum*10+3;
           }
           else if(s[i]=='L'&&s[i-1]!='L')
           {
               sum=sum*10+4;

           }
           else if((s[i]=='M'||s[i]=='N')&&(s[i-1]!='M'&&s[i-1]!='N'))
           {
               sum=sum*10+5;
           }
           else if(s[i]=='R'&&s[i-1]!='R')
           {
               sum=sum*10+6;
           }
        }
        if(sum==0)
            cout<<endl;
        else
        cout<<sum<<endl;
    }
}
