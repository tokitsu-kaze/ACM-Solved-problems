#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII > VPII;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int cnta[33],cntb[33];
        mem(cnta,0);
        mem(cntb,0);
        for(auto it:s) cnta[it-'a']++;
        for(auto it:target) cntb[it-'a']++;
        int ans=INF;
        for(int i=0;i<26;i++)
        {
            if(!cntb[i]) continue;
            ans=min(ans,cnta[i]/cntb[i]);
        }
        return ans;
        
    }
};
