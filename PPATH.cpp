#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;
 
bool prime[10002],visited[10002],flag;
queue<int>q;
int dist[10002];
 
void sieve()
{
    for(int i=2;i*i<=10000;i++)
    {
        if(prime[i])
        {
            for(int j=2*i;j<=10000;j+=i)prime[j]=false;
        }
    }
}
 
int bfs(int source,int dest)
{
    if(source==dest)return 0;
    int u,i,j,n,m;
    q.push(source);
    visited[source]=true;
    string str;
    while(!q.empty())
    {
        n=q.front();
        q.pop();
        for(i=0;i<10;i++)
        {
            for(j=0;j<4;j++)
            {
                str=to_string(n);
                if(i==0&&j==0)continue;
                str[j]=i+48;
                m=stoi(str);
                if(prime[m]&&!visited[m])
                {
                    q.push(m);
                    visited[m]=true;
                    dist[m]=1+dist[n];
                    if(m==dest)
                    {
                        flag=true;
                        break;
                    }
                }
            }
        }
    }
    if(flag)return dist[dest];
    else return -1;
}
 
 
int main()
{
    /*int x=42;
    string str;
    ostringstream temp;
    temp<<x;
    str=temp.str();
    cout<<str<<endl;*/
    memset(prime,true,sizeof(prime));
    sieve();
    int test,x,y;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d",&x,&y);
        flag=false;
        memset(visited,false,sizeof(visited));
        dist[x]=0;
        printf("%d\n",bfs(x,y));
    }
    return 0;
}