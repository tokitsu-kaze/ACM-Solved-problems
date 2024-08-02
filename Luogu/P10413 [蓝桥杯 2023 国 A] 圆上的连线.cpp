#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=2023;
int comb[4105][2105];
void init_comb(int n,int m)
{
	int i,j;
	comb[0][0]=1;
	for(i=1;i<=n;i++)
	{
		comb[i][0]=1;
		for(j=1;j<=i;j++)
		{
			comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
			if(comb[i][j]>=mod) comb[i][j]-=mod;
		}
	}
}
ll C(int n,int m)
{
	if(m>n||m<0||n<0) return 0;
	return comb[n][m];
}
int main()
{
	int n,i,ans;
	n=2023;
	init_comb(2*n,n);
	ans=1;
	for(i=1;i<=n/2;i++) ans=(ans+C(n,i*2)*(C(2*i,i)-C(2*i,i-1)+mod))%mod;
	printf("%d\n",ans);
	return 0;
}
