////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-15 20:16:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1141
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:1564KB
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
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=1000000+10;
const int EDGE=100000+10;//�ߵ�����
typedef long long ll;
//log(1)+log(2)+...+log(n)< m*log(2)
int main()
{
	int y,n,i;
	double sum;
	while(~scanf("%d",&y)&&y)
	{
		n=(y-1960)/10+2;
		n=1<<n;
		sum=0;
		i=1;
		while(sum<n)
		{
			sum+=log(i*1.0)/log(2.0);
			i++;
		}
		printf("%d\n",i-2);
	}
	return 0;
}