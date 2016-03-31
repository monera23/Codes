// monera
// Spoj - LITE same as flipcoin on codechef only indexing is different. This question has 1 indexing.
#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define f(i,a,b) for(int i =a; i <=b ; i++)
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define sqr(x) ((x)*(x))
#define EPS 1e-9
#define db(var) cout<<var<<" ";
#define gcd(a,b) __gcd(a,b)
#define p(A,a,b)  f(i,a,b) cout<<A[i]<<" ";
#define sj  cout<<"OK"<<endl;
#define ll long long int 
#define el cout<<endl;

#define MOD 1000000007
#define PI acos(-1.0)
#define e exp(1.0)
#define EPS 1e-9

using namespace std;

struct T{
	int tail;
	int head;
	int flips;
} tree[400005];

void build(int id,int l,int r)
{
	if(r-l<2)
	{
		tree[id].tail=1;
		tree[id].head=0;
		return ;
		
	}
	
	int mid=(l+r)>>1;
	
	build(id<<1,l,mid);
	build(id << 1 | 1,mid,r);
	
	tree[id].tail=tree[id<<1].tail + tree[id<<1 | 1].tail;
	tree[id].head=tree[id<<1].head + tree[id<<1 | 1].head;
}

void upd(int id,int l,int r,int val)
{
	tree[id].flips+=val;
	
	if(val%2==1)
	{
		int t=tree[id].tail;
		tree[id].tail=tree[id].head;
		tree[id].head=t;
	}
}

void shift(int id,int l,int r)
{
	int mid=(l+r)>>1;
	
	upd(id<<1,l,mid,tree[id].flips);
	upd(id<<1 | 1,mid,r,tree[id].flips);
	
	tree[id].flips=0;
}

void update(int x,int y,int id,int l,int r,int val)
{
	if(x>=r or l>=y)
	return ;
	
	if(x<=l && r<=y)
	{
		upd(id,l,r,1);
		return ;
	}
	shift(id,l,r);
	
	int mid=(l+r)>>1;
	
	update(x,y,id<<1,l,mid,val);
	update(x,y,id<<1 | 1,mid,r,val);
	
	tree[id].tail=tree[id<<1].tail + tree[id<<1 | 1].tail;
	tree[id].head=tree[id<<1].head + tree[id<<1 | 1].head;
	
}

int query(int x,int y,int id,int l,int r)
{
	if(x>=r or l>=y)
	return 0;
	
	if(x<=l && r<=y)
	{
	
	return tree[id].head;
	}
	shift(id,l,r);
	int mid=(l+r)>>1;
	
	if(y<mid)
	{
		return query(x,y,id<< 1,l,mid);
	}
	else if(x>=mid)
	{
		return query(x,y,id<< 1 | 1,mid,r);
	}
	
	else
	{
	return query(x,y,id<< 1,l,mid) + query(x,y,id << 1 | 1,mid,r);
	}
	
	
	
}

int main() 
{
    ios :: sync_with_stdio(0);
	
	int n,q;
	scanf("%d%d",&n,&q);
	
	build(1,0,n);
	
	while(q--)
	{
		int t,a,b;
		scanf("%d%d%d",&t,&a,&b);
		
		if(t==0)
		{
		    a--;
			update(a,b,1,0,n,1);
		}
		
		else if(t==1)
		{
			a--;
			int ans=query(a,b,1,0,n);
			printf("%d\n",ans);
			
		}
		
	}
//	db(tree[7].tail) db(tree[7].head);
	
  return 0;
}
