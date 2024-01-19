#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct RMQ
{
	#define type int
	type v[MAX];
	int lg[MAX],bin[22];
	type mx[MAX][22],mn[MAX][22];
	void work(int n,type *a)
	{
		int i,j;
		for(i=bin[0]=1;1<<(i-1)<=n;i++) bin[i]=(bin[i-1]<<1);
		for(i=2,lg[1]=0;i<=n;i++) lg[i]=lg[i>>1]+1;
		for(i=1;i<=n;i++)
		{
			v[i]=a[i];
			mx[i][0]=mn[i][0]=v[i];
		}
		for(j=1;1<<(j-1)<=n;j++)
		{
			for(i=1;i+bin[j]-1<=n;i++)
			{
				mx[i][j]=max(mx[i][j-1],mx[i+bin[j-1]][j-1]);
				mn[i][j]=min(mn[i][j-1],mn[i+bin[j-1]][j-1]);
			}
		}
	}
	type ask_max(int l,int r)
	{
		int t=lg[r-l+1];
		return max(mx[l][t],mx[r-bin[t]+1][t]);
	}
	type ask_min(int l,int r)
	{
		int t=lg[r-l+1];
		return min(mn[l][t],mn[r-bin[t]+1][t]);
	}
	#undef type
}rmq;
int a[MAX];
int ck(int n,int len,int target,int k)
{
	int i,cnt;
	cnt=0;
	for(i=1;i<=n-len+1;i++)
	{
		if(rmq.ask_max(i,i+len-1)
		  -rmq.ask_min(i,i+len-1)>=target) cnt++;
	}
	return cnt>=k;
}
int main()
{
	int t,n,k,i,res,l,r,mid,len;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		rmq.work(n,a);
		res=2e9;
		len=n-k+1;
		for(i=1;i<=n-len+1;i++)
		{
			res=min(res,rmq.ask_max(i,i+len-1)
					   -rmq.ask_min(i,i+len-1));
		}
		l=1;
		r=len;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(n,mid,res,k)) r=mid;
			else l=mid+1;
		}
		printf("%d %d\n",res,l);
	}
	return 0;
}
