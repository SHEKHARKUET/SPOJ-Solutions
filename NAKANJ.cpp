#include <bits/stdc++.h>
 
using namespace std;
 
bool visited[8][8];
int dist[8][8];
queue< pair<int,int> >q;
int r[8]={2,2,1,1,-2,-2,-1,-1};
int c[8]={1,-1,2,-2,1,-1,2,-2};
 
bool isin(int x,int y)
{
    if(x>=0&&x<8&&y>=0&&y<8)return true;
    return false;
}
 
int bfs(int dx,int dy)
{
    pair<int,int>p;
    int x,y,x1,y1,i;
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        x=p.first;
        y=p.second;
        visited[x][y]=true;
        for(i=0;i<8;i++)
        {
            x1=x+r[i];
            y1=y+c[i];
            if(isin(x1,y1))
            {
                if(!visited[x1][y1])
                {
                    q.push(make_pair(x1,y1));
                    dist[x1][y1]=1+dist[x][y];
                    if(x1==dx&&y1==dy)return dist[x1][y1];
                }
            }
        }
    }
}
 
int main()
{
    int test,sx,sy,dx,dy;
    scanf("%d",&test);
    string s1,s2;
    while(test--)
    {
        cin>>s1>>s2;
        if(s1==s2)
        {
            printf("0\n");
            continue;
        }
        sx=s1[0]-'a';
        sy=s1[1]-'1';
        dx=s2[0]-'a';
        dy=s2[1]-'1';
        q.push(make_pair(sx,sy));
        memset(visited,false,sizeof(visited));
        dist[sx][sy]=0;
        printf("%d\n",bfs(dx,dy));
        while(!q.empty())q.pop();
    }
    return 0;
}