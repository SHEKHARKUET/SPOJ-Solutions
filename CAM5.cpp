#include <bits/stdc++.h>
 
using namespace std;
 
bool visited[100002];
vector<int>v[100002];
queue<int>q;
 
void bfs(int source)
{
    q.push(source);
    visited[source]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<v[u].size();i++)
        {
            if(!visited[v[u][i]])
            {
                visited[v[u][i]]=true;
                q.push(v[u][i]);
            }
        }
    }
}
 
int main()
{
    int i,test,nodes,edges,x,y,cnt;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d",&nodes,&edges);
        for(i=0;i<edges;i++)
        {
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        memset(visited,false,sizeof(visited));
        cnt=0;
        for(i=0;i<nodes;i++)
        {
            if(!visited[i])
            {
                bfs(i);
                cnt++;
            }
        }
        printf("%d\n",cnt);
        for(i=0;i<nodes;i++)v[i].clear();
    }
    return 0;
}