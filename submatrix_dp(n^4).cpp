// monera
// O(n^4) dp submatrix max xor 
// Precomputation using prefix sum 1,1 to x,y (top left to lower right) for each i,j 
#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f(i,a,b) for(int i =a; i <=b ; i++)
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define sqr(x) ((x)*(x))
#define EPS 1e-9
#define db(var) cout<<var<<" ";
#define el cout<<endl;
#define p(A,a,b)  f(i,a,b) cout<<A[i]<<" ";
#define sj  cout<<"OK"<<endl;
#define ll long long int 


//functions
#define count_1(n)   __builtin_popcountll(n)
#define gcd(a,b) __gcd(a,b)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )

#define MOD 1000000007
#define PI acos(-1.0)
#define e exp(1.0)
#define EPS 1e-9
#define INF    2047483647
#define INFLL  9023372036854775807LL

using namespace std;




int main() 
{
    ios :: sync_with_stdio(0);
    
    int t;
    cin>>t;
    
    while(t--)
    {
    	int n;
    	cin>>n;
    	
    	int ar[n+5][n+5];
    	ll dp[n+5][n+5]={0};
    	
    	f(i,1,n)
    	{
    		f(j,1,n)
    		cin>>ar[i][j];
    	}
    	
    	f(i,1,n)
    	{
    		f(j,1,n)
    		{
    			dp[i][j]=dp[i-1][j]^dp[i][j-1]^dp[i-1][j-1]^ar[i][j];			//pre-comp 
    		}
    	}
    	
    	ll ans=0;
    	
    	f(i,1,n)
    	{
    		f(j,1,n)
    		{
    			f(k,i,n)
    			{
    				f(l,j,n)
    				{
    					ll val=dp[k][l]^dp[k][j-1]^dp[i-1][l]^dp[i-1][j-1];   // k,l pointing to lower right, i,j pointing to upper left
    					
    					ans=MAX(val,ans);
    					
    				}
    			}
    		}
    	}
        
        cout<<ans<<endl;
    	
    }

  return 0;
}
