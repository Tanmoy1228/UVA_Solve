#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

int arr[1100][1100];
int taken[1100][1100];
int dis[1100][1100];

int main()
{
    int R,C;
    while(cin>>R>>C)
    {
        int a,b,c,d,i,j,n,w,x,y,z;
        queue<int>q1;
        queue<int>q2;
        if(R==0 && C==0)
        {
            break;
        }
        for(i=0; i<R+10; i++)
        {
            for(j=0; j<C+10; j++)
            {
                arr[i][j]=0;
                taken[i][j]=0;
                dis[i][j]=0;
            }
        }
        cin>>n;
        for(i=0; i<n; i++)
        {
            cin>>a>>b;
            for(j=0; j<b; j++)
            {
                cin>>c;
                arr[a][c]=1;
            }
        }
        cin>>w>>x;
        cin>>y>>z;
        dis[w][x]=0;

        q1.push(w);
        q2.push(x);
        while(!q1.empty())
        {
            c=q1.front();
            d=q2.front();
            if(c==y && d==z)
            {
                printf("%d\n",dis[c][d]);
                break;
            }
            if(taken[c][d]==1)
            {
                q1.pop();
                q2.pop();
                continue;
            }
            if(arr[c][d]==1)
            {
                q1.pop();
                q2.pop();
                taken[c][d]=1;
                continue;
            }
            if(c>=0 && c<=R && d>=0 && d<=C)
            {
                taken[c][d]=1;
                if(taken[c][d-1]!=1 && c>=0 && c<=R && d-1>=0 && d-1<=C)
                {
                    q1.push(c);
                    q2.push(d-1);
                    dis[c][d-1]=dis[c][d]+1;
                }
                if(taken[c][d+1]!=1 && c>=0 && c<=R && d+1>=0 && d+1<=C)
                {
                    q1.push(c);
                    q2.push(d+1);
                    dis[c][d+1]=dis[c][d]+1;
                }
                if(taken[c-1][d]!=1 && c-1>=0 && c-1<=R && d>=0 && d<=C)
                {
                    q1.push(c-1);
                    q2.push(d);
                    dis[c-1][d]=dis[c][d]+1;
                }
                if(taken[c+1][d]!=1 && c+1>=0 && c+1<=R && d>=0 && d<=C)
                {
                    q1.push(c+1);
                    q2.push(d);
                    dis[c+1][d]=dis[c][d]+1;
                }
            }

            q1.pop();
            q2.pop();
        }
    }

    return 0;
}
