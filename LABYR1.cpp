#include <bits/stdc++.h>
 
using namespace std;
 
bool visited[1002][1002],temp[1002][1002];
int dist[1002][1002];
queue< pair<int,int> >q;
int r[4]={1,0,-1,0};
int c[4]={0,1,0,-1};
int row,col;
string str[1002];
 
bool isin(int x,int y)
{
    if(x>=0&&x<row&&y>=0&&y<col)return true;
    return false;
}
 
pair<int,int> bfs(pair<int,int>source,bool dn)
{
    int x,y,x1,y1;
    q.push(source);
    visited[source.first][source.second]=true;
    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;
        if(!dn)temp[x][y]=false;
        q.pop();
        for(int i=0;i<4;i++)
        {
            x1=x+r[i];
            y1=y+c[i];
            if(isin(x1,y1))
            {
                if(!visited[x1][y1]&&str[x1][y1]=='.')
                {
                    visited[x1][y1]=true;
                    q.push(make_pair(x1,y1));
                    if(dn)dist[x1][y1]=1+dist[x][y];
                }
            }
        }
    }
    if(dn)return make_pair(dist[x][y],0);
    else return make_pair(x,y);
}
 
pair<int,int> bfs2(pair<int,int>source,bool dn)
{
    int x,y,x1,y1;
    q.push(source);
    temp[source.first][source.second]=true;
    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;
        if(!dn)temp[x][y]=false;
        q.pop();
        for(int i=0;i<4;i++)
        {
            x1=x+r[i];
            y1=y+c[i];
            if(isin(x1,y1))
            {
                if(!temp[x1][y1]&&str[x1][y1]=='.')
                {
                    temp[x1][y1]=true;
                    q.push(make_pair(x1,y1));
                    if(dn)dist[x1][y1]=1+dist[x][y];
                }
            }
        }
    }
    if(dn)return make_pair(dist[x][y],0);
    else return make_pair(x,y);
}
 
int main()
{
    int test,i,j,maxm;
    cin>>test;
    while(test--)
    {
        cin>>col>>row;
        for(i=0;i<row;i++)
            cin>>str[i];
        memset(visited,false,sizeof(visited));
        memset(temp,false,sizeof(temp));
        memset(dist,0,sizeof(dist));
        maxm=0;
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                if(str[i][j]=='.'&&!temp[i][j])
                {
                    pair<int,int>pp;
                    pp=bfs(make_pair(i,j),false);
                    /*cout<<pp.first<<pp.second<<endl;
                    cout<<str[pp.first][pp.second]<<endl;*/
                    maxm=max(maxm,bfs2(pp,true).first);
                }
            }
        }
        cout<<"Maximum rope length is "<<maxm<<"."<<endl;
    }
    return 0;
}