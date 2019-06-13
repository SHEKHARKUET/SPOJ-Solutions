#include <bits/stdc++.h>
 
using namespace std;
 
int parent[10002];
vector<int>v[10002];
bool flag;
 
void dfs(int u)
{
    for(int i=0;i<v[u].size();i++)
    {
        if(!flag)break;
        if(parent[u]==-1&&parent[v[u][i]]==-1)
        {
            parent[u]=v[u][i];
            dfs(v[u][i]);
        }
        else if(parent[u]==-1)
        {
            parent[u]=v[u][i];
            continue;
        }
        else if(parent[v[u][i]]==-1)
        {
            parent[v[u][i]]=u;
            dfs(v[u][i]);
        }
        else if(parent[u]!=v[u][i]&&parent[v[u][i]]!=u)
            flag=false;
    }
    return;
}
 
int main()
{
    int nodes,edges,i,j,x,y;
    while(scanf("%d%d",&nodes,&edges)==2)
    {
        for(i=0;i<edges;i++)
        {
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        flag=true;
        memset(parent,-1,sizeof (parent));
        dfs(x);
        if(flag)
        {
            for(i=1;i<=nodes;i++)
            {
                if(parent[i]==-1)break;
            }
            if(i>nodes)printf("YES\n");
            else printf("NO\n");
        }
        else printf("NO\n");
        for(i=1;i<=nodes;i++)v[i].clear();
    }
    return 0;
}