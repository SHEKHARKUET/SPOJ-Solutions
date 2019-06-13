#include <bits/stdc++.h>
#define N 1000002
 
using namespace std;
 
int node[N][26],pre[N];
int root,nnode;
 
void init()
{
    nnode=0;
    for(int i=0;i<26;i++)
    {
        node[0][i]=-1;
        pre[0]=0;
    }
}
 
void insertStr(string str)
{
    root=0;
    int i,j;
    for(i=0;i<str.length();i++)
    {
        if(node[root][str[i]-'a']==-1)
        {
            nnode++;
            node[root][str[i]-'a']=nnode;
            for(j=0;j<26;j++)node[nnode][j]=-1;
        }
        root=node[root][str[i]-'a'];
        pre[root]++;
    }
}
 
int calPrefix(string str)
{
    root=0;
    int i;
    for(i=0;i<str.length();i++)
    {
        if(node[root][str[i]-'a']==-1)return 0;
        root=node[root][str[i]-'a'];
    }
    return pre[root];
}
 
int main()
{
    int n,q,i;
    string str;
    while(cin>>n>>q){
    init();
    for(i=0;i<n;i++)
    {
        cin>>str;
        insertStr(str);
    }
    for(i=0;i<q;i++)
    {
        cin>>str;
        cout<<calPrefix(str)<<endl;
    }
    }
    return 0;
}