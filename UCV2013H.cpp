#include <bits/stdc++.h>
 
using namespace std;
 
bool visited[252][252];
queue< pair<int,int> >q;
int arr[252][252];
int r[4]={1,0,-1,0};
int c[4]={0,1,0,-1};
map<int,int>mp;
int row,col;
 
bool isin(int x,int y)
{
    if(x>=0&&x<row&&y>=0&&y<col)return true;
    return false;
}
 
void bfs(pair<int,int>source)
{
    int x,y,x1,y1,cnt=1;
    q.push(source);
    visited[source.first][source.second]=true;
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
                if(!visited[x1][y1]&&arr[x1][y1]==1)
                {
                    visited[x1][y1]=true;
                    q.push(make_pair(x1,y1));
                    cnt++;
                }
            }
        }
    }
    mp[cnt]++;
}
 
int main()
{
    int i,j,c;
    while(scanf("%d%d",&row,&col)==2)
    {
        if(row==0&&col==0)break;
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)scanf("%d",&arr[i][j]);
        }
        memset(visited,false,sizeof(visited));
        c=0;
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                if(!visited[i][j]&&arr[i][j]==1)
                {
                    c++;
                    bfs(make_pair(i,j));
                }
            }
        }
        map<int,int>::iterator it;
        printf("%d\n",c);
        for(it=mp.begin();it!=mp.end();it++)
        {
            printf("%d %d\n",it->first,it->second);
        }
        mp.clear();
    }
    return 0;
}