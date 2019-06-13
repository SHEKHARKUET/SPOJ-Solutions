#include <bits/stdc++.h>
 
using namespace std;
 
int tree[90007];
 
void update(int b,int e,int node,int i)
{
    if(i<b||i>e)return;
    if(b==e&&b==i)
    {
        tree[node]++;
        return;
    }
    int left,right,mid;
    mid=(b+e)/2;
    left=node*2;
    right=left+1;
    update(b,mid,left,i);
    update(mid+1,e,right,i);
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str,strArr[30002];
    map<string,int>mp;
    int arr[30002],i,n,test,cnt;
    cin>>test;
    while(test--)
    {
        cin>>n;
        for(i=0;i<n;i++)cin>>strArr[i];
        for(i=0;i<n;i++)
        {
            cin>>str;
            mp.insert(make_pair(str,i));
        }
        for(i=0;i<n;i++)arr[mp[strArr[i]]]=i;
        memset(tree,0,sizeof(tree));
        cnt=0;
        for(i=n-1;i>=0;i--)
        {
            cnt+=query(0,n-1,1,0,arr[i]);
            update(0,n-1,1,arr[i]);
        }
        cout<<cnt<<endl;
        mp.clear();
    }
    return 0;
}