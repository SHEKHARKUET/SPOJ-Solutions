#include <bits/stdc++.h>
 
using namespace std;
 
vector<int>v[85],res,temp;
int level[85];
stack<int>st;
 
void dfs(int u,int par)
{
    int i,j,x,cnt;
    for(i=0;i<v[u].size();i++)
    {
        if(v[u][i]==par)continue;
        if(level[v[u][i]]==0)
        {
            level[v[u][i]] = 1;
            st.push(v[u][i]);
            dfs(v[u][i],u);
        }
        else if(level[v[u][i]]==1)
        {
            cnt=0;
            while(true)
            {
                x=st.top();
                temp.push_back(x);
                st.pop();
                cnt++;
                if(x==v[u][i])break;
            }
            for(j=temp.size()-1;j>=0;j--)st.push(temp[j]);
            temp.clear();
            res.push_back(cnt);
        }
    }
    level[u]=2;
    st.pop();
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n,m,x,y,i,t,caseno=0;
    cin>>t;
    while(t--)
    {
        unsigned long long tot=1;
        cin>>n>>m;
        for(i=0;i<m;i++)
        {
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        for(i=1;i<=n;i++)level[i]=0;
 
        level[1]=1;st.push(1);dfs(1,0);
 
        for(i=0;i<res.size();i++)tot*=res[i];
        cout<<"Case "<<++caseno<<": ";
        cout<<tot<<endl;
        for(i=1;i<=n;i++)v[i].clear();
        res.clear();
        while(!st.empty())st.pop();
    }
    return 0;
}