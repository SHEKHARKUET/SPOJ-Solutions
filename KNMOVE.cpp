#include <bits/stdc++.h>
 
using namespace std;
 
int r[8]={-2,-1,-2,-1,2,1,2,1};
int c[8]={1,2,-1,-2,1,2,-1,-2};
bool vis[1002][1002];
int res[1002][1002];
queue<pair<pair<int,int>,int> >Q;
 
bool isin(int i,int j)
{
    if(i>=1&&i<=1000&&j>=1&&j<=1000)return true;
    return false;
}
 
void bfs()
{
    Q.push({{1,1},0});
    memset(vis,false,sizeof(vis));
    vis[1][1]=true;
    int i,sx,sy,cost;
    while(!Q.empty())
    {
        sx=Q.front().first.first;
        sy=Q.front().first.second;
        cost=Q.front().second;
        res[sx][sy]=cost;
        Q.pop();
        for(i=0;i<8;i++)
        {
            if(isin(sx+r[i],sy+c[i])&&!vis[sx+r[i]][sy+c[i]])
            {
                Q.push({{sx+r[i],sy+c[i]},cost+1});
                vis[sx+r[i]][sy+c[i]]=true;
            }
        }
    }
}
 
int main()
{
    int test,x,y,i;
    bfs();
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",res[x][y]);
    }
    return 0;
}