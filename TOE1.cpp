#include<bits/stdc++.h>
 
using namespace std;
 
string str[3];
 
bool hmatch(char c)
{
    int i;
    for(i=0;i<3;i++)
    {
        if(str[i][0]==str[i][1]&&str[i][1]==str[i][2]&&str[i][0]==c)
            break;
    }
    if(i==3)return false;
    return true;
}
 
bool vmatch(char c)
{
    int i;
    for(i=0;i<3;i++)
    {
        if(str[0][i]==str[1][i]&&str[1][i]==str[2][i]&&str[0][i]==c)
            break;
    }
    if(i==3)return false;
    return true;
}
 
bool dmatch(char c)
{
    if(str[0][0]==str[1][1]&&str[1][1]==str[2][2]&&str[0][0]==c)
        return true;
    if(str[2][0]==str[1][1]&&str[1][1]==str[0][2]&&str[2][0]==c)
        return true;
    return false;
}
 
bool match(char c)
{
    if(hmatch(c)||vmatch(c)||dmatch(c))return true;
    return false;
}
 
int main()
{
    int test,i,j,numx,numo;
    scanf("%d",&test);
    while(test--)
    {
        for(i=0;i<3;i++)cin>>str[i];
        numx=numo=0;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(str[i][j]=='X')numx++;
                else if(str[i][j]=='O')numo++;
            }
        }
        if(numx==numo)
        {
            if(match('X'))printf("no\n");
            else printf("yes\n");
        }
        else if(numx==numo+1)
        {
            if(match('O'))printf("no\n");
            else printf("yes\n");
        }
        else printf("no\n");
    }
}