#include <bits/stdc++.h>
#define BIG 999999999
 
using namespace std;
 
typedef pair<int,int> pi;
 
vector<pi>v[10002];
bool vis[10002];
int dist[10002];
priority_queue<pi,vector<pi>,greater<pi> >pq;
 
void dijkstra(int s)
{
    pq.push({0,s});
    dist[s]=0;
    pi node;
    int i,u;
    while(!pq.empty())
    {
        node=pq.top();
        pq.pop();
        u=node.second;
        if(vis[u])continue;
        vis[u]=true;
        for(i=0;i<v[u].size();i++)
        {
            if(dist[v[u][i].first]>v[u][i].second+dist[u])
            {
                dist[v[u][i].first]=v[u][i].second+dist[u];
                pq.push({dist[v[u][i].first],v[u][i].first});
            }
        }
    }
}
 
int main()
{
    int n,m,i,x,y,c,cas;
    cin>>cas;
    while(cas--)
    {
        cin>>n>>m;
        for(i=0;i<m;i++)
        {
            cin>>x>>y>>c;
            v[x].push_back({y,c});
        }
        memset(vis,false,sizeof(vis));
        for(i=0;i<10002;i++)dist[i]=BIG;
        cin>>x>>y;
        dijkstra(x);
        if(dist[y]!=BIG)cout<<dist[y]<<endl;
        else cout<<"NO\n";
 
        for(i=0;i<10002;i++)
        {
            if(!v[i].empty())v[i].clear();
        }
    }
    return 0;
}