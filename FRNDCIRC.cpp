#include <bits/stdc++.h>
 
using namespace std;
 
// This program implements a simple disjoint set union data structure.
 
int Par[100002],Rank[100002],sz[100002];
 
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
 
int mergeSet(int x,int y)
{
    int px=findSet(x);
    int py=findSet(y);
    if(Rank[px]==Rank[py])Rank[py]++;
    if(Rank[py]<Rank[px])
    {
        Par[py]=px;
        sz[px]+=sz[py];
        return sz[px];
    }
    else
    {
        Par[px]=py;
        sz[py]+=sz[px];
        return sz[py];
    }
}
 
int main()
{
    int test,n,m,i,x,y,cnt;
    string str1,str2;
    map<string,int>mp;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>test;
    while(test--)
    {
        cin>>m;
        cnt=1;
        for(i=0;i<m;i++)
        {
            cin>>str1>>str2;
            if(mp.find(str1)==mp.end()){createSet(cnt);mp.insert({str1,cnt});cnt++;}
            if(mp.find(str2)==mp.end()){createSet(cnt);mp.insert({str2,cnt});cnt++;}
            x=mp[str1];
            y=mp[str2];
            if(findSet(x)!=findSet(y))
                cout<<mergeSet(x,y)<<endl;
            else cout<<sz[findSet(x)]<<endl;
        }
        mp.clear();
    }
    return 0;
}