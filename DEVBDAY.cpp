// QL -http://www.codechef.com/problems/DEVBDAY
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

int f[100005];
int r[100005];
vector<int> g[100005];
bool visit[100005]={false};

int find_cycle(int nod)      //cycle finding method
{
	if(visit[nod]==1)
	return nod;
	
	visit[nod]=1;
	
	return find_cycle(f[nod]);
}

ll dfs(int nod,int par)
{
	visit[nod]=true;
	ll val=r[nod];              //cost added here
	
	for(int i=0;i<g[nod].size();i++)
	{
		if(g[nod][i]==par)
		continue;
		
		ll fet=dfs(g[nod][i],nod);
		if(fet>0)         // negative cost ignored
		val+=fet;         // cost from nodes neighbours to cycle node
	}
	return val;
}

int main() 
{
	int t;
	cin>>t;
	
	while(t--)
	{
		ll n,ans=0;
		cin>>n;
		
		f(i,1,n)
		{
			visit[i]=0;
			f[i]=0;
			r[i]=0;
			g[i].clear();
		}
		
		f(i,1,n)
		{
		cin>>f[i];
		g[f[i]].pb(i);
		}
		
		f(i,1,n)
		cin>>r[i];
		
		f(i,1,n)
		{
			if(visit[i]==0)
			{
				int F=find_cycle(i);
				int a=F;   // node in cycle 
				int b=f[F]; // frnd of node in cycle 
				ll v=0;
				do
				{
					 v+=dfs(b,a);  // for each node in cycle find neighbours and add positive cost if any
					a=b;
					b=f[b];
					
				}while(a!=F);
				
				if(v>0)
				ans+=v;          // adding cost of each component
				
			}
		}
		
		cout<<ans<<endl;
		
	}
	
  return 0;
}
