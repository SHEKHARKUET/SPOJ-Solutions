#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int tc,i,x,n,caseno=0;
    bool vis[102],start[202];
    int par[102],arr[202],child[102];
    cin>>tc;
    while(tc--)
    {
        memset(vis,false,sizeof(vis));
        memset(start,false,sizeof(start));
        memset(child,0,sizeof(child));
        cin>>n;
        for(i=0;i<n*2;i++)
        {
            cin>>x;
            arr[i]=x;
            if(!vis[x])
            {
                vis[x]=true;
                start[i]=true;
            }
        }
        for(i=1;i<n*2;i++)
        {
            if(start[i])
            {
                if(start[i-1]){par[arr[i]]=arr[i-1];child[arr[i-1]]++;}
                else {par[arr[i]]=par[arr[i-1]];child[par[arr[i-1]]]++;}
            }
        }
        cout<<"Case "<<++caseno<<":\n";
        for(i=1;i<=n;i++)
            cout<<i<<" -> "<<child[i]<<endl;
        cout<<endl;
    }
    return 0;
}