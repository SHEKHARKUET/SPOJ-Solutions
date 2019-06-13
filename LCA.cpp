#include <bits/stdc++.h>
 
using namespace std;
 
int level[100005];
vector<int>v[100005];
int parent[100005][17];
bool vis[100005];
 
void dfs(int u)
{
    int i;
    for(i=0;i<v[u].size();i++)
    {
        if(!vis[v[u][i]])
        {
            level[v[u][i]]=level[u]+1;
            parent[v[u][i]][0]=u;
            vis[v[u][i]]=true;
            dfs(v[u][i]);
        }
    }
}
 
int query(int p,int q)
{
    if(level[p]<level[q])swap(p,q);
    int j;
    for(j=16;j>=0;j--)
    {
        if(parent[p][j]!=-1 && level[parent[p][j]]>=level[q])
        {
            p=parent[p][j];
        }
    }
    if(p==q)return p;
    for(j=16;j>=0;j--)
    {
        if(parent[p][j]!=-1 && parent[q][j]!=-1 && parent[p][j]!=parent[q][j])
        {
            p=parent[p][j];
            q=parent[q][j];
        }
    }
    return parent[p][0];
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int test,caseno=0,n,m,root,i,j,x,y,queries,p,q;
    cin>>test;
    while(test--)
    {
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>m;
            for(j=0;j<m;j++)
            {
                cin>>x;
                v[i].push_back(x);
                v[x].push_back(i);
            }
        }
        root=1;
        memset(vis,false,sizeof(vis));
        memset(parent,-1,sizeof(parent));
        vis[root]=true;parent[root][0]=-1;
        level[root]=0;dfs(root);
 
        for(j=1;(1<<j)<n;j++)
        {
            for(i=1;i<=n;i++)
            {
                if(parent[i][j-1]!=-1&&parent[parent[i][j-1]][j-1]!=-1)
                    parent[i][j]=parent[parent[i][j-1]][j-1];
            }
        }
        cout<<"Case "<<++caseno<<":"<<endl;
        cin>>queries;
        while(queries--)
        {
            cin>>p>>q;
            cout<<query(p,q)<<endl;
        }
        for(i=1;i<=n;i++)v[i].clear();
    }
    return 0;
}