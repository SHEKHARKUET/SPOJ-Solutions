#include <bits/stdc++.h>
#define MAX 300005
 
using namespace std;
 
struct Node
{
    int type;
    int x;
    int y;
    int w;
}N[MAX*2];
 
int Par[MAX],Rank[MAX],sz[MAX],res[MAX];
 
bool compareN(Node A,Node B)
{
    if(A.w!=B.w)return A.w>B.w;
    if(A.type!=B.type)return A.type<B.type;
}
 
void createSet(int x)
{
    Par[x]=x;
    sz[x]=1;
    Rank[x]=0;
}
 
int findSet(int x)
{
    if(x!=Par[x])Par[x]=findSet(Par[x]);
    return Par[x];
}
 
void mergeSet(int x,int y)
{
    int px=findSet(x);
    int py=findSet(y);
    if(Rank[py]<Rank[px])
    {
        Par[py]=px;
        sz[px]+=sz[py];
        sz[py]=0;
    }
    else
    {
        Par[px]=py;
        sz[py]+=sz[px];
        sz[px]=0;
    }
    if(Rank[px]==Rank[py])Rank[py]++;
}
 
int main()
{
    int n,m,q,i,j,x,y,w;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n>>m>>q){
    for(i=0;i<n;i++)createSet(i);
    for(i=0;i<m;i++){cin>>N[i].x>>N[i].y>>N[i].w;N[i].type=0;}
    for(i=m;i<m+q;i++){cin>>N[i].x>>N[i].w;N[i].y=i-m;N[i].type=1;}
    sort(N,N+m+q,compareN);
    for(i=0;i<m+q;i++)
    {
        if(N[i].type==0&&findSet(N[i].x)!=findSet(N[i].y))mergeSet(N[i].x,N[i].y);
        else if(N[i].type==1)res[N[i].y]=sz[findSet(N[i].x)];
    }
    for(i=0;i<q;i++)cout<<res[i]<<endl;}
    return 0;
}