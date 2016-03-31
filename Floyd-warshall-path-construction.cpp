// monera
#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f(i,a,b) for(int i =a; i <=b ; i++)
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define sqr(x) ((x)*(x))
#define sz(x) (int)(x.size())
#define EPS 1e-9
#define db(var) cout<<var<<" ";
#define el cout<<endl;
#define p(A,a,b)  f(i,a,b) cout<<A[i]<<" ";
#define sj  cout<<"OK"<<endl;
#define ll long long int 


//functions
#define count_1(n)    __builtin_popcountll(n)
#define gcd(a,b) __gcd(a,b)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define lcm(_1,_2)           ((_1/gcd(_1,_2))*(_2))

#define MOD 1000000007
#define PI acos(-1.0)
#define e exp(1.0)
#define EPS 1e-9
#define INF    2047483647
#define INFLL  9023372036854775807LL
const int MX=100005;

using namespace std;


int dist[105][105];
int par[105][105];
int visit[104];

int m;
void findp(int x,int y)
{
     if(x!=y)
     findp(x,par[x][y]);
     
     visit[y]=1;
      
}


int main() 
{
	
	for(int i=0;i<=103;i++)
	{
		for(int j=0;j<=103;j++)
		dist[i][j]=100000,par[i][j]=i;
	}
	int k;
	cin>>m>>k;
	
	for(int i=0;i<k;i++)
	{
		int x,y;
		cin>>x>>y;
		dist[x][y]=1;
	
	
	}
	
	for(int i=1;i<=m;i++)
	dist[i][i]=0;
	
	
	
	
for(int kk=1;kk<=m;kk++)                
	   	{                                   
			for(int i=1;i<=m;i++)
			{
				for(int j=1;j<=m;j++)
				{
					
					if(dist[i][j]>dist[i][kk]+dist[kk][j])
					{
						dist[i][j]=min(dist[i][j],dist[i][kk]+dist[kk][j]);
						par[i][j]=par[kk][j];
					}
					
				}
				
			}
		}
		
	

		
	int ans=0;
	
    
    
    findp(1,2);
    findp(2,1);
    
    visit[1]=visit[2]=1;
    
    for(int i=1;i<=m;i++)
    {
    	if(visit[i]==1)
    	ans++;
    	
    }
    
    
    cout<<ans<<endl;
      
	
  return 0;
}
