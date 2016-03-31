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
	int left;
	int right;
} tree[4*30009];

char s[30009];
int n;


void build(int id,int l,int r)
{
	if(r-l<2)
	{
		if(s[l]=='(')
		tree[id].left=1,tree[id].right=0;
		
		else if(s[l]==')')
		tree[id].right=1,tree[id].left=0;
		
		return ;
	}
	
	int mid=(l+r)>>1;
	
	build(id+id,l,mid);
	build(id+id+1,mid,r);
	
	int mini=min(tree[id+id].left,tree[id+id+1].right);                  // number of closed brackets
	
	tree[id].left= tree[id+id].left + tree[id+id+1].left-mini;			// remove the number of closed brackets from left and right 
	tree[id].right= tree[id+id].right + tree[id+id+1].right-mini;
	
	
}

void modify(int p,int id,int l,int r)
{
	if(r-l<2)
	{
		if(s[p]=='(')
		{
			s[p]=')';
			tree[id].left=0;
			tree[id].right=1;
		}
		else if(s[p]==')')
		{
			s[p]='(';
			tree[id].left=1;
			tree[id].right=0;
		}
		
		return ;
	}
	
	int mid=(l+r)>>1;
	
	if(p<mid)
	{
		modify(p,id+id,l,mid);
	}
	else
	{
		modify(p,id+id+1,mid,r);
	}
	
	int mini=min(tree[id+id].left,tree[id+id+1].right);
	tree[id].left= tree[id+id].left + tree[id+id+1].left-mini;
	tree[id].right= tree[id+id].right + tree[id+id+1].right-mini;
	
}



int main() 
{
    ios :: sync_with_stdio(0);
    
   
    int t=0;
    
    while(cin>>n)
    {
    	t++;
    	
    	cin>>s;
    	
    	build(1,0,n);
    	
    	int m;
         cin>>m;
    	
    	printf("Test %d:\n",t);
    	
    	while(m--)
    	{
    		int k;
    	    cin>>k;
    		
    		
    		
    		// db(tree[1].left) db(tree[1].right) el
    		if(k==0)
    		{
    			if(tree[1].left==0 && tree[1].right==0)       // if root has no unclosed brackets then yes 
    			printf("YES\n");
    			else
    			printf("NO\n");
    		}
    		
    		else
    		{
    			k--;
    			modify(k,1,0,n);
    		}
    	}
    	
    }
    
	
  return 0;
}
