#include <bits/stdc++.h>
 
using namespace std;
 
bool ok(vector<int>&v, int k, int d)
{
    int i,pos=1,x=v[0]+d;
    for(i=0;i<k;i++)
    {
        pos=lower_bound(v.begin()+pos,v.end(),x)-v.begin();
        if(pos==v.size())return false;
        x=v[pos]+d;
        pos++;
    }
    return true;
}
 
int binsearch(vector<int>&v, int k)
{
    int lo=0,hi=(v[v.size()-1]-v[0])/k,mid,res=0;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        //cout<<mid<<endl;
        if(ok(v,k,mid)){lo=mid+1;res=mid;}
        else hi=mid-1;
    }
    return res;
}
 
int main()
{
    int test,n,k,i,x;
    vector<int>v;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++){scanf("%d",&x);v.push_back(x);}
        sort(v.begin(),v.end());
        printf("%d\n",binsearch(v,k-1));
        v.clear();
    }
    return 0;
}