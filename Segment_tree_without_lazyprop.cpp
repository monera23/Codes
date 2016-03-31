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

void build(int id,int l,int r)              // building the tree
{
	if(r-l<2)
	{
		tree[id]=ar[l];			// array elements
		return;
	}
	
	int mid=(l+r)/2;
	
	build(id*2,l,mid);			// go to children
	build(id*2+1,mid,r);
	
	tree[id]=max(tree[id*2],tree[id*2+1]);			// value to be stored in parents
	
}

int query(int x,int y,int id,int l,int r)
{
	if(x>=r or l>=y)		//outside range
	return 0;
	
	if(x<=l && r<=y)		// within range
	return tree[id];
	
	int mid=(l+r)/2;
	
	return max(query(x,y,id*2,l,mid),query(x,y,id*2+1,mid,r));  //  return query ans
	
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
