////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-24 13:13:04
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1114
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1800KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#define INF 0x3f3f3f
#define mem(a,b) memset(a,(b),sizeof(a))
#define PI acos(-1.0)
#define MAX 200000+10
using namespace std;
typedef long long ll;
int main()
{ 
	int t,e,f,n,dp[50010],val[501],w[501],i,j;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>e>>f;
			cin>>n;
			mem(dp,0x3f);
			dp[0]=0;
			for(i=0;i<n;i++)
			{
				scanf("%d%d",&val[i],&w[i]);
			}
			for(i=0;i<n;i++)
			{
				for(j=w[i];j<=f-e;j++)
				{
					dp[j]=min(dp[j],dp[j-w[i]]+val[i]);
				}
			}
			if(dp[f-e]!=dp[50005]) printf("The minimum amount of money in the piggy-bank is %d.\n",dp[f-e]);
			else puts("This is impossible.");
		}
	}
    return 0;
}