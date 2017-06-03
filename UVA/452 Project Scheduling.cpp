#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    int t,T;
    cin>>T;

    getchar();
    getchar();
    while(T--)
    {
        char s[100];
        long long int cost[30]={0};
        long long int maxi[30]={0},total_max=0;
        int take[30]={0};
//        int arr[30];
//        int mat[30][30];
        int indegree[30]={0};
        map<int,int>m;
        vector<int>v[30];
        long long int i,j,k,length,counter=1,a=0;

        while(gets(s) && s[0])
        {
//            gets(s);
            length=strlen(s);
//            if(!length)
//            {
//                break;
//            }
            //arr[counter]=s[0]-64;
            //cost[s[0]-64]=s[2]-'0';
            indegree[s[0]-64]=0;
            counter++;
            a=0;
            for(i=2;i<length;i++)
            {
                if(s[i]==' ')
                {
                    break;
                }
                k=s[i]-'0';
                a=a*10;
                a=a+k;
            }
            cost[s[0]-64]=a;
            for(i++; i<length; i++)
            {
                v[s[i]-64].push_back(s[0]-64);
                indegree[s[0]-64]++;
            }
        }
//        for(i=1; i<=12; i++)
//        {
//            length=v[i].size();
//            cout<<i<<"->";
//            for(j=0; j<length; j++)
//            {
//                cout<<v[i][j]<<" ";
//            }
//            cout<<"co"<<cost[i]<<endl;
//        }
        total_max=0;
        for(k=1; k<counter; k++)
        {
            for(i=1; i<counter; i++)
            {
                //cout<<i<<endl;
                if(!take[i] && !indegree[i])
                {
                    cost[i]=max(cost[i],maxi[i]);
                    length=v[i].size();
                    for(j=0; j<length; j++)
                    {
                        indegree[v[i][j]]--;
                        take[i]=1;
                        maxi[v[i][j]]=max(maxi[v[i][j]],cost[i]+cost[v[i][j]]);
                        //cout<<i<<" "<<v[i][j]<<" "<<maxi[v[i][j]]<<endl;
                        if(total_max<maxi[v[i][j]])
                        {
                            total_max=maxi[v[i][j]];
                            //printf("%lld\n\n",total_max);
                        }
                    }
                    break;
                }
            }

        }
        printf("%lld\n",total_max);
        if(T)
            cout<<endl;
//        for(k=1; k<counter; k++)
//        {
//            v[k].clear();
//            maxi[k]=0;
//        }
        //getchar();
        //getchar();


    }
    return 0;
}
//3
//
//A 5
//B 3 A
//D 2 A
//C 2 B
//F 2 CE
//E 4 DC
//
//A 5
//B 3 A
//D 2 A
//C 2 B
//F 2 CE
//E 4 DC
//
//A 2
//C 3
//B 5 AC
//D 10 B
//H 13 GF
//E 11 B
//G 12
//F 2 DE
//I 10
//J 20 I
