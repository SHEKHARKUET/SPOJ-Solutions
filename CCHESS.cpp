#include <bits/stdc++.h>
#define BIG 999999999
 
using namespace std;
 
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
 
bool vis[8][8];
priority_queue<pii,vector<pii>,greater<pii> >pq;
int r[8]={2,1,2,1,-2,-1,-2,-1};
int c[8]={1,2,-1,-2,1,2,-1,-2};
int dist[8][8];
 
bool isin(int i,int j)
{
    if(i>=0&&i<8&&j>=0&&j<8)return true;
    return false;
}
 
void dijkstra(pi s)
{
    pii cell;
    int i,x,y,cst;
    pq.push({0,s});
    dist[s.first][s.second]=0;
    while(!pq.empty())
    {
        cell=pq.top();
        pq.pop();
        x=cell.second.first;
        y=cell.second.second;
        cst=cell.first;
        if(vis[x][y])continue;
        vis[x][y]=true;
        for(i=0;i<8;i++)
        {
            if(isin(x+r[i],y+c[i])&&dist[x+r[i]][y+c[i]]>dist[x][y]+(x*(x+r[i])+y*(y+c[i])))
            {
                dist[x+r[i]][y+c[i]]=dist[x][y]+(x*(x+r[i])+y*(y+c[i]));
                pq.push({dist[x+r[i]][y+c[i]],{x+r[i],y+c[i]}});
            }
        }
    }
}
 
int main()
{
    int x1,y1,x2,y2,i,j;
    while(cin>>x1>>y1>>x2>>y2)
    {
        memset(vis,false,sizeof(vis));
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
                dist[i][j]=BIG;
        }
        dijkstra({x1,y1});
        if(dist[x2][y2]!=BIG)cout<<dist[x2][y2];
        else cout<<-1;
        cout<<endl;
    }
    return 0;
}