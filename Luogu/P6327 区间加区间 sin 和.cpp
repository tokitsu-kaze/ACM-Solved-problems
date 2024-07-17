#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
struct Segment_Tree
{
	#define type double
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	ll a[MAX],tag[MAX<<2],qv;
	struct node
	{
		double s,c;
		void init(){s=c=0;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.s=x.s+y.s;
		res.c=x.c+y.c;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void maintain(int id,ll x)
	{
		double sina,cosa,sinx,cosx;
		sina=t[id].s;
		cosa=t[id].c;
		sinx=sin(x);
		cosx=cos(x);
		t[id].s=sina*cosx+cosa*sinx;
		t[id].c=cosa*cosx-sina*sinx;
	}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		maintain(ls,tag[id]);
		maintain(rs,tag[id]);
		tag[ls]+=tag[id];
		tag[rs]+=tag[id];
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id].s=sin(a[l]);
			t[id].c=cos(a[l]);
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			maintain(id,qv);
			tag[id]+=qv;
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	node query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr) return t[id];
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(qr<=mid) return query(l,mid,ls);
		if(ql>mid) return query(mid+1,r,rs);
		return merge_node(query(l,mid,ls),query(mid+1,r,rs));
	}
	void build(int _n)
	{
		n=_n;
		build(1,n,1);
		null_node.init();
	}
	void upd(int l,int r,type v)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	double ask(int l,int r)
	{
		if(l>r) return null_node.s;
		ql=l;
		qr=r;
		return query(1,n,1).s;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
/*
tr.build(n);
tr.upd(l,r,v);
tr.ask(l,r);
Segment_Tree::node res=tr.merge_node(nodex,nodey);
*/
int main()
{
	int n,m,i,op,l,r,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&tr.a[i]);
	tr.build(n);
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		{
			scanf("%d",&x);
			tr.upd(l,r,x);
		}
		else printf("%.1f\n",tr.ask(l,r));
	}
	return 0;
}
