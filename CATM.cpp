#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n,m,k,c1x,c1y,c2x,c2y,mx,my;
    while(scanf("%d%d",&n,&m)==2)
    {
        scanf("%d",&k);
        while(k--)
        {
            scanf("%d%d%d%d%d%d",&mx,&my,&c1x,&c1y,&c2x,&c2y);
            if(mx<=c1x&&mx<=c2x)printf("YES\n");
            else if(mx>=c1x&&mx>=c2x)printf("YES\n");
            else if(my<=c1y&&my<=c2y)printf("YES\n");
            else if(my>=c1y&&my>=c2y)printf("YES\n");
            else
            {
                if(abs(mx-c1x)==abs(my-c1y)&&abs(mx-c2x)==abs(my-c2y))printf("NO\n");
                else printf("YES\n");
            }
        }
    }
    return 0;
}