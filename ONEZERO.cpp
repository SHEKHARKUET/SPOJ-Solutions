#include <bits/stdc++.h>
 
using namespace std;
 
queue<string>q;
 
bool isdivisible(string s,int d)
{
    int digit,x,i,j,k,rem=0;
    x=k=i=0;
    while(i<s.length())
    {
        while(true)
        {
            digit=s[i]-'0';
            x=10*x+digit;
            i++;
            k++;
            if(x>=d||i==s.length())break;
        }
        rem=x%d;
        x=rem;
        k=1;
    }
    if(rem)return false;
    else return true;
}
 
string bfs(int n)
{
    q.push("1");
    string u,s1,s2;
    while(!q.empty())
    {
        u=q.front();
        //if(isdivisible(u,n))return u;
        q.pop();
        s1=s2=u;
        s1.push_back('0');
        s2.push_back('1');
        if(isdivisible(s1,n))return s1;
        q.push(s1);
        if(isdivisible(s2,n))return s2;
        q.push(s2);
    }
}
 
int main()
{
    int test;
    int n;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        //printf("%s\n",bfs(n));
        cout<<bfs(n)<<endl;
        while(!q.empty())q.pop();
    }
    return 0;
}