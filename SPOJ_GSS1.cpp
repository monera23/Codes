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
	int ts;
	int mv;
	int left;
	int right;
} tree[300002],ans,Emp;
int ar[50003];


void build(int id,int l,int r)
{
	if(r-l<2)
	{
		tree[id].ts=tree[id].mv=tree[id].left=tree[id].right=ar[l];
		
		//db(tree[id].ts)db(id) el
		return;
	}
	
	int mid=(l+r)/2;
	
	build(id*2,l,mid);
	build(id*2+1,mid,r);
	
	tree[id].ts=tree[id*2].ts + tree[id*2+1].ts;
	tree[id].left=max(tree[id*2].left,max(tree[id*2].ts+tree[id*2+1].left,tree[id*2].ts+tree[id*2+1].ts));
	tree[id].right=max(tree[id*2+1].right,max(tree[id*2+1].ts+tree[id*2].right,tree[id*2].ts+tree[id*2+1].ts));
	tree[id].mv=max(tree[id*2].mv,max(tree[id*2+1].mv,tree[id*2].right+tree[id*2+1].left));   // max value will be either left mv right mv or the range not checked yet which is = L.right + R.left;
	
}

T query(int x,int y,int id,int l,int r)
{
	if(x>=r or l>=y)              // if out of range return large negative value 
	return Emp;
	
	if(x<=l && r<=y)
	return tree[id];
	
	int mid=(l+r)/2;
	
	T L,R;
	
	L=query(x,y,id*2,l,mid);
	R=query(x,y,id*2+1,mid,r);
	
   ans.ts=L.ts + R.ts;                                // output a struct 
   ans.left=max(L.left,max(L.ts+R.left,L.ts+R.ts));
   ans.right=max(R.right,max(R.ts+L.ts,R.ts+L.right));
   ans.mv=max(L.mv,max(R.mv,L.right+R.left));
	
	return ans;
	
}




int main() 
{
    ios :: sync_with_stdio(0);
    
    int n;
    scanf("%d",&n);
    
    Emp.ts=-115007;
    Emp.mv=-115007;
    Emp.left=-115007;
    Emp.right=-115007;
    
    f(i,0,n-1)
    scanf("%d",&ar[i]);
    
    build(1,0,n);
    
    int q;
    scanf("%d",&q);
    
    while(q--)
    {
    	int x,y;
    	scanf("%d%d",&x,&y);
    	x--;
    	printf("%d\n",query(x,y,1,0,n).mv);
    
   // db(tree[1].ts)
    }
    
	
  return 0;
}
