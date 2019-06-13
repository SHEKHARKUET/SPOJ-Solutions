#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int,int>pi;
typedef pair<int,pi>pii;
priority_queue<pii,vector<pii>,greater<pii>>q;
int arr[102][102];
int dist[102][102];
bool visited[102][102];
int row,col;
int r[4]={0,-1,0,1};
int c[4]={1,0,-1,0};
 
bool isin(int x,int y)
{
    if(x>=0&&x<row&&y>=0&&y<col)return true;
    return false;
}
 
int bfs(pii source,int dx,int dy)
{
    int x,y,x1,y1,cst;
    q.push(source);
    visited[0][0]=true;
    dist[0][0]=arr[0][0];
    if(dx==0&&dy==0)return dist[0][0];
    while(!q.empty())
    {
        x=q.top().second.first;
        y=q.top().second.second;
        cst=q.top().first;
        q.pop();
        for(int i=0;i<4;i++)
        {
            x1=x+r[i];
            y1=y+c[i];
            if(isin(x1,y1))
            {
                if(!visited[x1][y1])
                {
                    visited[x1][y1]=true;
                    dist[x1][y1]=cst+arr[x1][y1];
                    q.push(make_pair(dist[x1][y1],make_pair(x1,y1)));
                    if(x1==dx&&y1==dy)return dist[x1][y1];
                    //cout<<dist[x1][y1]<<" "<<x1<<" "<<y1<<endl;
                }
            }
        }
    }
}
 
int main()
{
    int test,i,j,dx,dy,ti,req;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d",&row,&col);
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
                scanf("%d",&arr[i][j]);
        }
        scanf("%d%d%d",&dx,&dy,&ti);
        memset(visited,false,sizeof(visited));
        req=bfs(make_pair(arr[0][0],make_pair(0,0)),dx-1,dy-1);
        if(req<=ti)printf("YES\n%d\n",ti-req);
        else printf("NO\n");
        while(!q.empty())q.pop();
    }
    return 0;
}