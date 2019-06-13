#include <bits/stdc++.h>
 
using namespace std;
 
set<int>s[100005];
int par[100005],n;
bool vis[100005];
 
bool bfs()
{
    int i,u;
    queue<int>Q;
    memset(vis,false,sizeof(vis));
    vis[1]=true;Q.push(1);
    while(!Q.empty())
    {
        u=Q.front();Q.pop();
        for(auto it=s[u].begin();it!=s[u].end();it++)
        {
            if(!vis[*it])
            {
                vis[*it]=true;
                par[*it]=u;
                if(*it==n)return true;
                Q.push(*it);
            }
        }
    }
    return false;
}
 
int main()
{
    int t,caseno=0,i,m,x,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<n;i++)
        {
            cin>>m;
            for(j=0;j<m;j++)
            {
                cin>>x;
                s[i].insert(x);
            }
        }
        //cout<<"Case "<<++caseno<<": ";
        if(!bfs())cout<<-1<<endl;
        else
        {
            stack<int>st;
            x=n;
            while(x!=1)
            {
                st.push(par[x]);
                x=par[x];
            }
            cout<<st.size()<<endl;
            while(!st.empty())
            {
                cout<<st.top()<<" ";
                st.pop();
            }
            cout<<endl;
        }
        cout<<"\n";
        for(i=1;i<n;i++)s[i].clear();
    }
    return 0;
}