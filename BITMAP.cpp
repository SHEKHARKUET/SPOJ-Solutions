#include <bits/stdc++.h>
 
using namespace std;
 
bool visited[184][184];
int row,col;
queue< pair<int,int> >q;
int dist[184][184];
int r[4]={0,-1,0,1};
int c[4]={1,0,-1,0};
string str[184];
 
bool isin(int x,int y)
{
    if(x>=0&&x<row&&y>=0&&y<col)return true;
    return false;
}
 
void bfs()
{
    int u,x1,y1,x,y;
    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;
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
                    dist[x1][y1]=1+dist[x][y];
                    q.push(make_pair(x1,y1));
                }
            }
        }
    }
}
 
int main()
{
    int test,i,j;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d",&row,&col);
        for(i=0;i<row;i++)cin>>str[i];
        memset(visited,false,sizeof(visited));
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                if(str[i][j]=='1')
                {
                    q.push(make_pair(i,j));
                    visited[i][j]=true;
                    dist[i][j]=0;
                }
            }
        }
        bfs();
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                printf("%d",dist[i][j]);
                if(j!=col)printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}