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
const int MAX=100+10;
const int EDGE=100000+10;//�ߵ�����
typedef long long ll;
int main()
{
	int t,a,b,base;
	char c[111],d[111],*end;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%s %s %d",c,d,&base);
			a=strtol(c,&end,base);
			b=strtol(d,&end,base);
			printf("(%d,%d)\n",a/b,a%b);
		}
	}
	return 0;
}