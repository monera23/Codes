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

struct T{
	ll total;
	ll lazy;
} tree[300002];

void upd(int id,int l,int r ,ll val)      // updates value of parent and puts the val in its lazy to propagate to its children
{
	tree[id].lazy+=val;
	tree[id].total+=(r-l)*val;
}

void shift(int id,int l,int r)      // updates the value of children with parent's lazy ;
{
	int mid=(l+r)/2;
	upd(id*2,l,mid,tree[id].lazy);
	upd(id*2+1,mid,r,tree[id].lazy);
	tree[id].lazy=0;
	
}

void update(int x,int y,int id,int l,int r,ll val)
{
	if(x>=r or l>=y)
	return ;
	
	if(x<=l && r<=y)
	{
		upd(id,l,r,val);
		return ;
		
	}
	
	shift(id,l,r);
	int mid=(l+r)/2;
	
	update(x,y,id*2,l,mid,val);
	update(x,y,id*2+1,mid,r,val);
	
	tree[id].total=tree[id*2].total + tree[id*2+1].total;
}

ll query(int x,int y,int id,int l,int r)
{
	if(x>=r or l>=y)
	return 0;
	
	if(x<=l && r<=y)
	return tree[id].total;
	
	shift(id,l,r);
	
	int mid=(l+r)/2;
	return query(x,y,id*2,l,mid) + query(x,y,id*2+1,mid,r) ;
	
}

int main() 
{
    ios :: sync_with_stdio(0);
    
    int t;
    cin>>t;
    
    while(t--)
    {
    	f(i,0,300001)
    	tree[i].total=0,tree[i].lazy=0;
    	
    	int n,c;
    	cin>>n>>c;
    	
    	while(c--)
    	{
    		int b,p,q,v;
    		cin>>b;
    		
    		if(b==0)
    		{
    			cin>>p>>q>>v;
    			p--;
    			update(p,q,1,0,n,v);
    		}
    		
    		else if(b==1)
    		{
    			cin>>p>>q;
    			p--;
    			ll ans= query(p,q,1,0,n);
    			
    			cout<<ans<<endl;
    		}
    	}
    	
    }
	
  return 0;
}
