#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int,long long> pi;
 
int level[10005];
vector<pi>v[10005];
int parent[10005][17];
bool vis[10005];
long long dist[10005];
 
void dfs(int u)     /// NO mystery here. Simple DFS.
{
    int i;
    for(i=0;i<v[u].size();i++)
    {
        if(!vis[v[u][i].first])
        {
            level[v[u][i].first] = level[u]+1;
            dist[v[u][i].first] = dist[u] + v[u][i].second;
            parent[v[u][i].first][0] = u;
            vis[v[u][i].first] = true;
            dfs(v[u][i].first);
        }
    }
}
 
int query(int p,int q)
{
    if(level[p]<level[q])swap(p,q);
    int j;
 
    ///Bring p to the same depth as q.
    for(j=16;j>=0;j--)
    {
        if(parent[p][j]!=-1 && level[parent[p][j]]>=level[q])
        {
            p=parent[p][j];
        }
    }
 
    if(p==q)return p; /// p and q are the same node.
 
    ///Bring p and q to the lowest depth where p!=q(parent[p]=parent[q]).
    for(j=16;j>=0;j--)
    {
        if(parent[p][j]!=-1 && parent[q][j]!=-1 && parent[p][j]!=parent[q][j])
        {
            p=parent[p][j];
            q=parent[q][j];
        }
    }
 
    return parent[p][0]; ///LCA found as parent[p]=parent[q] but p!=q.
}
 
int kth(int p,int q)
{
    if(q==0)return p;
    int j,x=0;
    for(j=16;j>=0;j--)
    {
        if(parent[p][j]!=-1 && (1<<j)+x<=q)
        {
            p=parent[p][j];
            x+=(1<<j);
        }
        if(x==q)return p;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int test,n,m,k,root,i,j,x,y,lca;
    long long c;
    string str;
    cin>>test;
    while(test--)
    {
        cin>>n;
        for(i=0;i<n-1;i++)
        {
            cin>>x>>y>>c;
            v[x].push_back({y,c});
            v[y].push_back({x,c});
        }
        root=1;
        memset(vis,false,sizeof(vis));
        memset(parent,-1,sizeof(parent));
        vis[root]=true;parent[root][0]=-1;
        level[root]=0;dist[root]=0;dfs(root);
 
        ///Setting up all the ancestors.
        for(j=1;(1<<j)<n;j++)
        {
            for(i=1;i<=n;i++)
            {
                if(parent[i][j-1]!=-1&&parent[parent[i][j-1]][j-1]!=-1)
                    parent[i][j]=parent[parent[i][j-1]][j-1];
            }
        }
        while(true)
        {
            cin>>str;
            if(str=="DONE")break;
            else if(str=="DIST")
            {
                cin>>x>>y;
                lca=query(x,y);
                cout<<dist[x]+dist[y]-(2*dist[lca])<<endl;
            }
            else
            {
                cin>>x>>y>>k;
                lca=query(x,y);
                if(level[x]-level[lca]+1>=k)cout<<kth(x,k-1)<<endl;
                else cout<<kth(y,level[x]+level[y]-(2*level[lca])-k+1)<<endl;
            }
        }
        cout<<"\n";
        for(i=1;i<=n;i++)v[i].clear();
    }
    return 0;
}