#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
int n,k,T;
int a[MAXN],sum[MAXN];
int q_sum(int l,int r)
{
    if(l>r)return 0;
    return sum[r]-sum[l-1];
}
bool check_fir()
{
    for(int i=1;i+k-1<=n;++i)
    {
        int lala=q_sum(1,i-1)+q_sum(i+k,n);
        if(lala==0||lala+k==n)return true;
    }
    return false;
}
bool check_sec()
{
    if(k*2<n||k==1)return false;
    int len=n-k-1;
    for(int i=2;i<=len;++i)
    {
        if(a[i]!=a[i-1]||a[n-i+1]!=a[n-i+2])return false;
    }
    if(a[len]==a[len+1]||a[n-len]==a[n-len+1]||a[1]==a[n])return false;
    return true;
}
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;++i)
    {
        scanf("%1d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    if(check_fir())
    {
        printf("tokitsukaze\n");
    }
    else
    {
        if(check_sec())
        {
            printf("quailty\n");
        }
        else
        {
            printf("once again\n");
        }
    }
    return 0;
}
