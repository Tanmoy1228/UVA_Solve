#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
int mat[100][100];
int main()
{
    int n,m,t=1;

    vector<int>v;
    map<int,string>ma;
    map<int,string>::iterator it;
    while(scanf("%d %d",&n,&m)==2 && n!=0)
    {
        int loop,i,j,k,a,b,c;
        char name[15];


        if(n==0)
        {
            break;
        }

        for(b=1; b<=n; b++)
        {
            for(c=1; c<=n; c++)
            {
                if(b==c)
                {
                    mat[b][c]=0;
                    continue;
                }
                mat[b][c]=500000;
            }
        }
        for(loop=1; loop<=n; loop++)
        {
            scanf("%s",&name);
            ma[loop]=name;
        }
//        for(it=ma.begin();it!=ma.end();it++)
//        {
//            cout<<it->first<<"  "<<it->second<<endl;
//        }
        for(loop=1; loop<=m; loop++)
        {
            scanf("%d %d %d",&i,&j,&k);
            mat[i][j]=k;
            mat[j][i]=k;
        }
        if(m==0)
        {
            cout<<"Case #"<<t<<" : "<<ma[1]<<endl;
            t++;
            continue;
        }
        for(a=1; a<=n; a++)
        {
            for(b=1; b<=n; b++)
            {
                for(c=1; c<=n; c++)
                {
                    mat[b][c]=min(mat[b][c],mat[b][a]+mat[a][c]);
                    mat[c][b]=mat[b][c];
                }
            }
        }
        int total=0,maxi=500000,position;
        for(b=1; b<=n; b++)
        {
            total=0;

            for(c=1; c<=n; c++)
            {
                if(b==c || mat[b][c]==500000)
                {
                    continue;
                }
                total=total+mat[b][c];
            }
            if(maxi>total)
            {
                maxi=total;
                position=b;
            }
        }
        it=ma.find(position);
        //printf("Case #%d : %s\n",t,ma[position]);
        cout<<"Case #"<<t<<" : "<<ma[position]<<endl;
        t++;
        ma.clear();
    }
    return 0;
}
