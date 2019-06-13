#include <bits/stdc++.h>
 
using namespace std;
 
int r[8]={1,0,-1,0,1,-1,1,-1};
int c[8]={0,1,0,-1,1,1,-1,-1};
bool visited[101][101],flag;
char s[101][101];
int row, col;
string desired="ALLIZZWELL";
 
bool isin(int x,int y)
{
    if(x>=0&&x<row&&y>=0&&y<col)return true;
    return false;
}
 
void dfs(int x,int y,string str)
{
    if(visited[x][y])return;
    visited[x][y]=true;
    str.push_back(s[x][y]);
    //if(str==desired)return;
    for(int i=0;i<8;i++)
    {
        if(str==desired)
        {
            flag=true;
            break;
        }
        if(isin(x+r[i],y+c[i]))
        {
            //if(str.length()==6)cout<<s[x+r[i]][y+c[i]]<<endl;
            if(s[x+r[i]][y+c[i]]==desired[str.length()])
                dfs(x+r[i],y+c[i],str);
        }
    }
    //cout<<str<<endl;
    if(!flag)visited[x][y]=false;
    return;
}
 
int main()
{
    //ios_base::sync_with_stdio(false);
   // cin.tie(NULL);
 
    int test,i,j;
    cin>>test;
    while(test--)
    {
        cin>>row>>col;
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
                cin>>s[i][j];
        }
        //cout<<s[0][0]<<endl;
        flag=false;
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                if(s[i][j]=='A')
                {
                    memset(visited,false,sizeof(visited));
                    dfs(i,j,"");
                    if(flag)break;
                }
            }
            if(flag)break;
        }
        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}