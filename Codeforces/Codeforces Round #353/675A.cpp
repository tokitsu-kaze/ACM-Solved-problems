#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	ll a,b,c,d;
	while(~scanf("%lld%lld%lld",&a,&b,&c))
	{
		if(a==b)
		{
			puts("YES");
			continue;
		}
		if(c==0)
		{
			if(a!=b) puts("NO");
			else puts("YES");
		}
		else
		{
			if((b-a)%c) puts("NO");
			else
			{
				d=(b-a)/c;
				if(d<=0) puts("NO");
				else puts("YES");
			}
		}
	}
	return 0;
}