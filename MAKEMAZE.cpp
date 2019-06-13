#include <bits/stdc++.h>
 
using namespace std;
 
int r[4]={1,0,-1,0};
int c[4]={0,1,0,-1};
bool visited[21][21],flag;
char str[21][21];
int row,col;
 
bool isin(int x,int y)
{
    if(x>=0&&x<row&&y>=0&&y<col)return true;
    return false;
}
 
void dfs(int x,int y)
{
    if(visited[x][y])return;
    visited[x][y]=true;
    for(int i=0;i<4;i++)
    {
        if(flag)break;
        int x1=x+r[i];
        int y1=y+c[i];
        if(isin(x1,y1))
        {
            if(str[x1][y1]=='.')
            {
                if((x1==0||x1==row-1||y1==0||y1==col-1)&&!visited[x1][y1])
                {
                    flag=true;
                    break;
                }
                dfs(x1,y1);
            }
        }
    }
    if(!flag)visited[x][y]=false;
    return;
}
 
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int test,i,j,cnt;
    vector<int>xcoord,ycoord;
    cin>>test;
    while(test--)
    {
        cin>>row>>col;
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                cin>>str[i][j];
                if((i==0||j==0||i==row-1||j==col-1)&&str[i][j]=='.')
                {
                    xcoord.push_back(i);
                    ycoord.push_back(j);
                }
            }
        }
        cnt=0;
        for(i=0;i<xcoord.size();i++)
        {
            if(xcoord.size()>2)break;
            flag=false;
            memset(visited,false,sizeof(visited));
            dfs(xcoord[i],ycoord[i]);
            if(flag)cnt++;
            if(cnt==3)break;
        }
        if(cnt==0||cnt==3)cout<<"invalid\n";
        else cout<<"valid\n";
        xcoord.clear();
        ycoord.clear();
    }
    return 0;
}