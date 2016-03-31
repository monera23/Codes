// monera
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
int tree[10000];
int ar[1000];
int lazy[1000];

void build(int id,int l,int r)
{
	if(r-l<2)
	{
		tree[id]=ar[l];
		return;
	}
	
	int mid=(l+r)/2;
	
	build(id*2,l,mid);
	build(id*2+1,mid,r);
	
	tree[id]=max(tree[id*2],tree[id*2+1]);
	
}

void update(int x,int y,int id,int l,int r,int value)
{
	if(lazy[id]!=0)				// if lazy of id has some value update the tree[id] and lazy the values to children
	{
		tree[id]+=lazy[id];
		
		if(r-l>=2)
		{
			lazy[2*id]+=lazy[id];
			lazy[2*id+1]+=lazy[id];
		}
		lazy[id]=0;
	}
	
	if(x>=r or l>=y)
	return ;
	
	if(x<=l && r<=y)				// if within range increase tree[id] by value 
	{								// also increase value of lazy of children
		tree[id]+=value;
		
		if(r-l>=2)
		{
			lazy[id*2]+=value;
			lazy[2*id+1]+=value;
		}
		return ;
	}
	int mid=(l+r)/2;
	
	update(x,y,2*id,l,mid,value);
	update(x,y,2*id+1,mid,r,value);
	
	tree[id]=max(tree[id*2],tree[id*2+1]);
}


int query(int x,int y,int id,int l,int r)
{
	if(x>=r or l>=y)
	return 0; 
	
	if(lazy[id]!=0)					// update the value of node if it is used and lazy the values to children 
	{
		tree[id]+=lazy[id];
		
		if(r-l>=2)
		{
			lazy[id*2]+=lazy[id];
			lazy[id*2+1]+=lazy[id];
		}
		lazy[id]=0;
	}
	

	
	if(x<=l && r<=y)
	return tree[id];
	
	int mid=(l+r)/2;
	
	return max(query(x,y,id*2,l,mid),query(x,y,id*2+1,mid,r));
	
}


int main() 
{
    ios :: sync_with_stdio(0);
	
	int n;
	cin>>n;
	
	f(i,0,n-1)
	cin>>ar[i];
	
	build(1,0,n);
	
	int q;
	cin>>q;
	
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		int val=query(a,b+1,1,0,n);
		cout<<val<<endl;
	}
	
	
  return 0;
}
