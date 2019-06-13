#include <bits/stdc++.h>
 
using namespace std;
 
vector<int>allowed;
queue<pair<int,int> >Q;
int num;
bool vis[10][100005];
pair<int,int> par[10][100005];
 
pair<int,int> bfs()
{
    if(allowed.size()==0)return {-1,-1};
    if(allowed.size()==1 && allowed[0]==0)return {-1,-1};
    int i,r,d;
    pair<int,int> u;
    memset(vis,false,sizeof(vis));
    for(i=0;i<allowed.size();i++)
    {
        if(allowed[i]==0)continue;
        d = allowed[i]/num;
        r = allowed[i]%num;
        par[d][r]={-1,-1};
        if(r==0)return {d,r};
        Q.push({d,r});
    }
    while(!Q.empty())
    {
        u=Q.front();Q.pop();
        for(i=0;i<allowed.size();i++)
        {
            d = (u.second*10+allowed[i])/num;
            r = (u.second*10+allowed[i])%num;
            if(vis[d][r])continue;
            vis[d][r]=true;
            par[d][r]=u;
            if(r==0)return {d,r};
            Q.push({d,r});
        }
    }
    return {-1,-1};
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int test,m,x,y,i,j,caseno=0;
    pair<int,int> res;
    stack<int>st;
    bool bad[10];
    while(cin>>num)
    {
        cin>>m;
        memset(bad,false,sizeof(bad));
        for(i=0;i<m;i++)
        {
            cin>>x;
            bad[x]=true;
        }
        for(i=0;i<10;i++)if(!bad[i])allowed.push_back(i);
        cout<<"Case "<<++caseno<<": ";
        res=bfs();
        if(res.first==-1)cout<<-1<<"\n";
        else
        {
            x=res.first;y=res.second;
            while(x!=-1)
            {
                st.push((x*num+y)%10);
                i=par[x][y].first;
                j=par[x][y].second;
                x=i;y=j;
            }
            while(!st.empty()){cout<<st.top();st.pop();}
            cout<<"\n";
        }
        allowed.clear();
        while(!Q.empty())Q.pop();
    }
    return 0;
}