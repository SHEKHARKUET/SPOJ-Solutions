#include <bits/stdc++.h>
 
using namespace std;
 
int level[100005];
vector<int>v[100005];
int parent[100005][17];
bool vis[100005];
long long w[100005];
 
long long dfs(int u)     /// NO mystery here. Simple DFS.
{
    int i;
    for(i=0;i<v[u].size();i++)
    {
        if(!vis[v[u][i]])
        {
            level[v[u][i]] = level[u]+1;
            parent[v[u][i]][0] = u;
            vis[v[u][i]] = true;
            w[u]+=dfs(v[u][i]);
        }
    }
    return w[u];
}
 
long long query(int p,int q)
{
    if(p==q)return w[1];
    if(level[p]<level[q])return w[q];
    int j;
 
    ///Bring p to the same depth as q.
    for(j=16;j>=0;j--)
    {
        if(parent[p][j]!=-1 && level[parent[p][j]]>level[q])
        {
            p=parent[p][j];
        }
    }
 
    if(parent[p][0]==q)return w[1]-w[p];
    return w[q];
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n,m,root,i,j,x,y,queries,p,q;
    char c;
    while(cin>>n)
    {
        for(i=1;i<=n;i++)cin>>w[i];
        for(i=2;i<=n;i++)
        {
            cin>>x;
            v[i].push_back(x);
            v[x].push_back(i);
        }
        root=1;
        memset(vis,false,sizeof(vis));
        memset(parent,-1,sizeof(parent));
        vis[root]=true;parent[root][0]=-1;
        level[root]=0;m=dfs(root);
 
        ///Setting up all the ancestors.
        for(j=1;(1<<j)<n;j++)
        {
            for(i=1;i<=n;i++)
            {
                if(parent[i][j-1]!=-1&&parent[parent[i][j-1]][j-1]!=-1)
                    parent[i][j]=parent[parent[i][j-1]][j-1];
            }
        }
 
        cin>>queries;
        while(queries--)
        {
            cin>>c;
            if(c=='R')cin>>root;
            else
            {
                cin>>p;
                cout<<query(root,p)<<endl;
            }
        }
        for(i=1;i<=n;i++)v[i].clear();
    }
    return 0;
}