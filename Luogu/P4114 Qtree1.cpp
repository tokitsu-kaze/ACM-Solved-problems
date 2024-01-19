#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct Segment_Tree
{
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	struct node
	{
		type v;
		void init()
		{
			
		}
	}t[MAX<<2];
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	node merge(node x,node y)
	{
		node res;
		res.v=max(x.v,y.v);
		return res;
	}
	void pushup(int id){t[id]=merge(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id].v=a[l];
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
			t[id].v=qv;
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
		return merge(query(l,mid,ls),query(mid+1,r,rs));
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r,type v)
	{
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	node ask(int l,int r)
	{
		ql=l;
		qr=r;
		return query(1,n,1);
	}
	#undef type
	#undef ls
	#undef rs
}tr;
struct Heavy_Light_Decomposition
{
	#define type int
	struct edge{int a,b;type v;};
	struct node{int to;type w;};
	vector<int> mp[MAX];
	vector<edge> e;
	int dep[MAX],fa[MAX],sz[MAX],son[MAX];
	int id[MAX],top[MAX],dfn[MAX],tot;
	int n,rt;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
		e.clear();
		e.push_back({0,0,0});
	}
	void add_edge(int a,int b,type v=0)
	{
		e.push_back({a,b,v});
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	void dfs1(int x,int pre,int h)
	{
		int i,to;
		dep[x]=h;
		fa[x]=pre;
		sz[x]=1;
		for(i=0;i<mp[x].size();i++)
		{
			to=mp[x][i];
			if(to==pre) continue;
			dfs1(to,x,h+1);
			sz[x]+=sz[to];
			if(son[x]==-1||sz[to]>sz[son[x]]) son[x]=to;
		}
	}
	void dfs2(int x,int tp)
	{
		int i,to;
		dfn[x]=++tot;
		id[dfn[x]]=x;
		top[x]=tp;
		if(son[x]==-1) return;
		dfs2(son[x],tp);
		for(i=0;i<mp[x].size();i++)
		{
			to=mp[x][i];
			if(to!=son[x]&&to!=fa[x]) dfs2(to,to);
		}
	}
	void work(int _rt)
	{
		rt=_rt;
		for(int i=0;i<=n;i++) son[i]=-1;
		tot=0;
		dfs1(rt,0,0);
		dfs2(rt,rt);
	}
	int LCA(int x,int y)
	{
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			x=fa[top[x]];
	    }
	    if(dep[x]>dep[y]) swap(x,y);
	    return x;
	}
	//path
	void init_path()
	{
		tr.a[dfn[rt]]=0;
		for(int i=1;i<n;i++)
		{
			if(dep[e[i].a]<dep[e[i].b]) swap(e[i].a,e[i].b);
			tr.a[dfn[e[i].a]]=e[i].v;
		}
		tr.build(n);
	}
	void upd_edge(int id,type v)
	{
		if(dep[e[id].a]>dep[e[id].b]) tr.upd(dfn[e[id].a],dfn[e[id].a],v);
		else tr.upd(dfn[e[id].b],dfn[e[id].b],v);
	}
	void upd_path(int x,int y,type v)
	{  
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			tr.upd(dfn[top[x]],dfn[x],v);
			x=fa[top[x]];
	    }
	    if(dep[x]>dep[y]) swap(x,y);
	    if(x!=y) tr.upd(dfn[x]+1,dfn[y],v);
	}
	type ask_path(int x,int y)
	{  
		Segment_Tree::node res;
		res.v=0;
		while(top[x]!=top[y])
		{  
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			res=tr.merge(res,tr.ask(dfn[top[x]],dfn[x]));
			x=fa[top[x]];
	    }  
	    if(dep[x]>dep[y]) swap(x,y);
	    if(x!=y) res=tr.merge(res,tr.ask(dfn[x]+1,dfn[y]));
	    return res.v;
	}
	#undef type
}hld;
/*
hld.init(n)
hld.add_edge(a,b,v=0);  a <-> b
hld.work(root);
*/
int main()
{
	int n,i,a,b,c,x,y;
	char op[11];
	scanf("%d",&n);
	hld.init(n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		hld.add_edge(a,b,c);
	}
	hld.work(1);
	hld.init_path();
	while(~scanf("%s",op))
	{
		if(op[0]=='D') break;
		scanf("%d%d",&x,&y);
		if(op[0]=='C') hld.upd_edge(x,y);
		else printf("%d\n",hld.ask_path(x,y));
	}
	return 0;
}
