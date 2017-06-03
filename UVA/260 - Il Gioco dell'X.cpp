#include <bits/stdc++.h>

using namespace std;

int n,vis[210][210],s,h;
char g[210][210];

int dfsblack(int i,int j)
{
    if(i==n-1)
        s=1;
    vis[i][j]=1;
    if(g[i][j+1]=='b' && j+1<n && vis[i][j+1]==0)
        dfsblack(i,j+1);
    if(g[i+1][j+1]=='b' && i+1<n && j+1<n && vis[i+1][j+1]==0)
        dfsblack(i+1,j+1);
    if(g[i+1][j]=='b' && i+1<n && vis[i+1][j]==0)
        dfsblack(i+1,j);
    if(g[i-1][j]=='b' && i-1>=0 && vis[i-1][j]==0)
        dfsblack(i-1,j);
    if(g[i-1][j-1]=='b' && j-1>=0 && i-1>=0 && vis[i-1][j-1]==0)
        dfsblack(i-1,j-1);
    if(g[i][j-1]=='b' && j-1>=0 && vis[i][j-1]==0)
        dfsblack(i,j-1);

}

int dfswhite(int u,int v)
{
    if(v==n-1)
        s=1;
    vis[u][v]=1;
    if(g[u][v+1]=='w'&&v+1<n&&vis[u][v+1]==0)
        dfswhite(u,v+1);
    if(g[u+1][v+1]=='w'&&u+1<n&&v+1<n&&vis[u+1][v+1]==0)
        dfswhite(u+1,v+1);
    if(g[u+1][v]=='w'&&u+1<n&&vis[u+1][v]==0)
        dfswhite(u+1,v);
    if(g[u-1][v]=='w'&&u-1>=0&&vis[u-1][v]==0)
        dfswhite(u-1,v);
    if(g[u-1][v-1]=='w'&&v-1>=0&&u-1>=0&&vis[u-1][v-1]==0)
        dfswhite(u-1,v-1);
    if(g[u][v-1]=='w'&&v-1>=0&&vis[u][v-1]==0)
        dfswhite(u,v-1);
}


int main()
{
    //read();
    int x=0;
    while(cin>>n&&n!=0)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cin>>g[i][j];
        }
        int d=0;
        for(int i=0; i<n; i++)
        {
            memset(vis,0,sizeof vis);
            h=0;
            s=0;
            if(g[0][i]=='b')
            {
                dfsblack(0,i);
                if(s==1)
                {
                    cout<<++x<<" "<<"B"<<endl;
                    d=1;
                    break;
                }
            }
        }
        if(d==0)
        {
            for(int i=0; i<n; i++)
            {

                memset(vis,0,sizeof vis);
                h=0;
                s=0;
                if(g[i][0]=='w')
                {
                    dfswhite(i,0);
                    if(s==1)
                    {
                        cout<<++x<<" "<<"W"<<endl;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
