#include <bits/stdc++.h>
 
using namespace std;
 
int Parent[1005],Rnk[1005];
 
void createset(int i)
{
    Parent[i]=i;
    Rnk[i]=0;
}
 
int findset(int x)
{
    if(x!=Parent[x])Parent[x]=findset(Parent[x]);
    return Parent[x];
}
 
void mergeset(int x,int y)
{
    int px=findset(x);
    int py=findset(y);
    if(Rnk[px]<=Rnk[py])Parent[px]=py;
    else Parent[py]=px;
    if(Rnk[px]==Rnk[py])Rnk[py]++;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int test,n,m,x,y,arr[1005],i,j;
    vector<int>v[1005],idx,numbers;
    cin>>test;
    while(test--)
    {
        cin>>n>>m;
        for(i=1;i<=n;i++)createset(i);
        for(i=1;i<=n;i++)cin>>arr[i];
        for(i=0;i<m;i++)
        {
            cin>>x>>y;
            if(findset(x)!=findset(y))mergeset(x,y);
        }
        for(i=1;i<=n;i++)v[findset(i)].push_back(i);
        for(i=1;i<=n;i++)
        {
            for(j=0;j<v[i].size();j++)
            {
                idx.push_back(v[i][j]);
                numbers.push_back(arr[idx[j]]);
            }
            if(v[i].size()>0)
            {
                sort(idx.begin(),idx.end());
                sort(numbers.begin(),numbers.end());
                for(j=0;j<v[i].size();j++)arr[idx[j]]=numbers[j];
                idx.clear();numbers.clear();
            }
        }
        for(i=1;i<=n;i++)cout<<arr[i]<<" ";
        cout<<endl;
        for(i=1;i<=n;i++)v[i].clear();
    }
    return 0;
}