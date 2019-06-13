#include <bits/stdc++.h>

using namespace std;

queue<int>q;
int u,nodes,dist[10002];
vector<int>v[10002];
bool visited[10002];

int bfs(int source,bool dn)
{
    memset(visited,false,sizeof(visited));
    dist[source]=0;
    q.push(source);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        visited[u]=true;
        for(int i=0;i<v[u].size();i++)
        {
            if(!visited[v[u][i]])
            {
                q.push(v[u][i]);
                if(dn)dist[v[u][i]]=dist[u]+1;
            }
        }
    }
    if(!dn)return u;
    else
    {
        sort(dist,dist+nodes);
        return dist[nodes-1];
    }
}

int main()
{
    int i,j,x,y;
    while(cin>>nodes)
    {
        for(i=0;i<nodes-1;i++)
        {
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        cout<<bfs(bfs(1,false),true)<<endl;
        for(i=1;i<=nodes;i++)v[i].clear();
    }
    return 0;
}
