#include <bits/stdc++.h>
 
using namespace std;
 
int arr[300002],arr2[1000002],res[200002];
int tree[900007];
 
void update(int b,int e,int node,int i,bool v)
{
    if(i<b||i>e)return;
    if(b==e)
    {
        if(v)tree[node]++;
        else tree[node]--;
        return;
    }
    int left,right,mid;
    mid=(b+e)/2;
    left=node*2;
    right=left+1;
    update(b,mid,left,i,v);
    update(mid+1,e,right,i,v);
    tree[node]=tree[left]+tree[right];
}
 
int query(int b,int e,int node,int i,int j)
{
    if(i>e||j<b)return 0;
    if(b>=i&&e<=j)return tree[node];
    int left,right,mid;
    mid=(b+e)/2;
    left=node*2;
    right=left+1;
    int q1=query(b,mid,left,i,j);
    int q2=query(mid+1,e,right,i,j);
    return q1+q2;
}
 
int main()
{
    int j,x,y,q,n,i;
    typedef pair<int,int>pi;
    vector< pair<pi,int> >v;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)scanf("%d",&arr[i]);
        scanf("%d",&q);
        for(i=0;i<q;i++)
        {
            scanf("%d%d",&x,&y);
            v.push_back(make_pair(make_pair(y-1,x-1),i));
        }
        sort(v.begin(),v.end());
        memset(tree,0,sizeof(tree));
        memset(arr2,-1,sizeof(arr2));
        j=0;
        for(i=0;i<n;i++)
        {
            if(arr2[arr[i]]==-1)
            {
                update(0,n-1,1,i,true);
                arr2[arr[i]]=i;
            }
            else
            {
                update(0,n-1,1,i,true);
                update(0,n-1,1,arr2[arr[i]],false);
                arr2[arr[i]]=i;
            }
            while(v[j].first.first==i&&j<q)
            {
                res[v[j].second]=query(0,n-1,1,v[j].first.second,v[j].first.first);
                j++;
            }
        }
        for(i=0;i<q;i++)printf("%d\n",res[i]);
        v.clear();
    }
    return 0;
}