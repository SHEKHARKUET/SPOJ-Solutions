#include <bits/stdc++.h>
 
using namespace std;
 
bool visited[1002][1002];
string str[1002];
queue< pair<int,int> >q;
int row,col;
int r[4]={0,-1,0,1};
int c[4]={1,0,-1,0};
char s[4]={'W','S','E','N'};
map<char,int>mp;
 
bool isin(int x,int y)
{
    if(x>=0&&x<row&&y>=0&&y<col)return true;
    return false;
}
 
void bfs(pair<int,int>source)
{
    int x,y,x1,y1,x2,y2;
    q.push(source);
    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;
        visited[x][y]=true;
        //cout<<x<<" "<<y<<endl;
        q.pop();
        for(int i=0;i<4;i++)
        {
            x1=x+r[i];
            y1=y+c[i];
            if(isin(x1,y1))
            {
                if(str[x1][y1]==s[i]&&!visited[x1][y1])
                {
                    visited[x1][y1]=true;
                    q.push(make_pair(x1,y1));
                }
            }
        }
        x2=x+r[mp[str[x][y]]];
        y2=y+c[mp[str[x][y]]];
        //cout<<x2<<" "<<y2<<endl;
        if(isin(x2,y2)&&!visited[x2][y2])
        {
            q.push(make_pair(x2,y2));
            visited[x2][y2]=true;
        }
    }
    //printf("\n\n");
}
 
int main()
{
    int i,j,cnt;
    mp.insert(make_pair('E',0));
    mp.insert(make_pair('N',1));
    mp.insert(make_pair('W',2));
    mp.insert(make_pair('S',3));
    while(scanf("%d%d",&row,&col)==2)
    {
        for(i=0;i<row;i++)cin>>str[i];
        memset(visited,false,sizeof(visited));
        cnt=0;
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                if(!visited[i][j])
                {
                    bfs(make_pair(i,j));
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
        //bfs(make_pair(0,0));
    }
    return 0;
}