#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
long long int Y[104][104];
long long int M[104][104];
int main()
{
    //freopen("in.txt","r",stdin);
    long long int n,i,j,k,cost,place,t=0;
    char age,dir,place1,place2;
    map<char,long long int>m1;
    map<long long int,char>m2;
    vector<int >ans;
    while(scanf("%lld",&n))
    {

        if(n==0)
        {
            break;
        }
        getchar();
        int counter=1;
        for(i=0; i<=100; i++)
        {
            for(j=0; j<=100; j++)
            {
                if(i==j)
                {
                    Y[i][j]=0;
                    M[i][j]=0;
                    continue;
                }
                Y[i][j]=9999999999;
                M[i][j]=9999999999;
            }
        }
        int check=0;
        for(i=0; i<n; i++)
        {
            //getchar();
            scanf("%c %c %c %c %lld\n",&age,&dir,&place1,&place2,&cost);
            if(m1.find(place1)==m1.end())
            {
                m1[place1]=counter;
                m2[counter]=place1;
                counter++;
                check=1;
            }
            if(m1.find(place2)==m1.end())
            {
                m1[place2]=counter;
                m2[counter]=place2;
                counter++;
                check=1;
            }
            if(age=='Y')
            {
                if(check==1)
                {
                    Y[m1[place1]][m1[place2]]=cost;
                }

                else
                    Y[m1[place1]][m1[place2]]=min(Y[m1[place1]][m1[place2]],cost);
                check=0;
                if(dir=='B')
                {
                    Y[m1[place2]][m1[place1]]=Y[m1[place1]][m1[place2]];
                }
            }
            else if(age=='M')
            {
                if(check==1)
                {
                    M[m1[place1]][m1[place2]]=cost;
                }
                else
                    M[m1[place1]][m1[place2]]=min(M[m1[place1]][m1[place2]],cost);
                check=0;
                if(dir=='B')
                {
                    M[m1[place2]][m1[place1]]=M[m1[place1]][m1[place2]];
                }
            }
        }
//        for(i=1; i<counter; i++)
//        {
//            for(j=1; j<counter; j++)
//            {
//                cout<<Y[i][j]<<"  ";
//            }
//            cout<<endl;
//        }
//        for(i=1; i<counter; i++)
//        {
//            for(j=1; j<counter; j++)
//            {
//                cout<<M[i][j]<<"  ";
//            }
//            cout<<endl;
//        }
        scanf("%c %c",&place1,&place2);
        for(k=1; k<counter; k++)
        {
            for(i=1; i<counter; i++)
            {
                for(j=1; j<counter; j++)
                {
                    Y[i][j]=min(Y[i][j],Y[i][k]+Y[k][j]);
                    M[i][j]=min(M[i][j],M[i][k]+M[k][j]);
                }
            }
        }
//        if(t!=0)
//            cout<<endl;
//        t++;
//        cout<<"\n\n";
//        for(i=1; i<counter; i++)
//        {
//            for(j=1; j<counter; j++)
//            {
//                cout<<Y[i][j]<<"  ";
//            }
//            cout<<endl;
//        }
//        for(i=1; i<counter; i++)
//        {
//            for(j=1; j<counter; j++)
//            {
//                cout<<M[i][j]<<"  ";
//            }
//            cout<<endl;
//        }
//        cout<<"\n\n";
        cost=9999999999;
        if(m1[place1]>0 && m1[place1]<counter && m1[place2]>0 && m1[place2]<counter)
        {
            for(i=1; i<counter; i++)
            {
                if(cost>Y[m1[place1]][i]+M[m1[place2]][i])
                {
                    cost=Y[m1[place1]][i]+M[m1[place2]][i];
                    ans.clear();
                    place=i;
                    ans.push_back(i);
                    continue;
                }
                if(cost==Y[m1[place1]][i]+M[m1[place2]][i])
                {
                    ans.push_back(i);
                }

            }
        }
        else
        {
            if(place1==place2)
                cout<<0<<" "<<place1<<endl;
            else
                cout<<"You will never meet."<<endl;
            m1.clear();
            m2.clear();
            ans.clear();
            continue;
        }
        if(cost>=9999999999)
        {

            cout<<"You will never meet."<<endl;
            m1.clear();
            m2.clear();
            ans.clear();
            continue;
        }
        i=0;
        if(ans.size()>1)
        {
            cout<<cost<<" ";
            for(i=0; i<ans.size()-1; i++)
            {
                cout<<m2[ans[i]]<<" ";
            }
            cout<<m2[ans[i]]<<endl;
        }
        else
            cout<<cost<<" "<<m2[ans[i]]<<endl;
        m1.clear();
        m2.clear();
        ans.clear();
    }
    return 0;
}
