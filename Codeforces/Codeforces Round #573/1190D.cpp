#include <bits/stdc++.h>
using namespace std;
/************* debug begin *************/
string to_string(string s){return '"'+s+'"';}
string to_string(const char* s){return to_string((string)s);}
string to_string(const bool& b){return(b?"true":"false");}
template<class T>string to_string(T x){ostringstream sout;sout<<x;return sout.str();}
template<class A,class B>string to_string(pair<A,B> p){return "("+to_string(p.first)+", "+to_string(p.second)+")";}
template<class A>string to_string(const vector<A> v){
	int f=1;string res="{";for(const auto x:v){if(!f)res+= ", ";f=0;res+=to_string(x);}res+="}";
	return res;
}
void debug_out(){puts("");}
template<class T,class... U>void debug_out(const T& h,const U&... t){cout<<" "<<to_string(h);debug_out(t...);}
#ifdef tokitsukaze 
#define debug(...) cout<<"["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__);
#else
#define debug(...) 233;
#endif
/*************  debug end  *************/
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
void go();
int main(){
	#ifdef tokitsukaze
//		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=998244353;
/*********************************  head  *********************************/
struct Fenwick_Tree
{
	int bit[MAX];
	int n;
	void init(int _n){n=_n;mem(bit,0);}
	int lowbit(int x){return x&(-x);}
	void insert(int x,int v)
	{
		while(x<=n)
		{
			bit[x]+=v;
			x+=lowbit(x);
		}
	}
	int get(int x)
	{
		int res=0;
		while(x)
		{
			res+=bit[x];
			x-=lowbit(x);
		}
		return res;
	}
	int query(int l,int r)
	{
		return get(r)-get(l-1);
	}
}tr;
VI x[MAX],y;
void go()
{
	int n,i,tot,pre;
	ll ans;
	while(~scanf("%d",&n))
	{
		tr.init(n);
		y.clear();
		map<int,int> idx,idy,cntx;
		tot=0;
		for(i=0;i<n;i++)
		{
			int X,Y;
			scanf("%d%d",&X,&Y);
			if(!idy.count(Y))
			{
				x[tot].clear();
				idy[Y]=tot++;
				y.pb(Y);
			}
			x[idy[Y]].pb(X);
			cntx[X]++;
		}
		tot=0;
		for(auto it:cntx)
		{
			idx[it.fi]=++tot;
			tr.insert(tot,1);
		}
		sort(all(y));
		ans=0;
		for(auto Y:y)
		{
			sort(all(x[idy[Y]]));
			pre=1;
			for(auto X:x[idy[Y]])
			{
				ans+=1LL*tr.query(pre,idx[X])*tr.query(idx[X],tot);
				pre=idx[X]+1;
				cntx[X]--;
				if(cntx[X]==0)
				{
					cntx.erase(X);
					tr.insert(idx[X],-1);
				}
	//			debug(Y,ans);
			}
		}
		printf("%lld\n",ans);
	}
}

