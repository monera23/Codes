// monera
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
#define count_1(n)    __builtin_popcountll(n)
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

#define B1 33
#define M1 10000009

string s;
ll p[100005];
ll has[100005];

void pre()
{
	p[0]=1;
	f(i,1,s.length())
	{
		p[i]=(B1*p[i-1])%M1;                  // hash function= (s[i]*p^i)%MOD;
	}
	
	f(i,1,s.length())
	{
		has[i]=(B1*has[i-1]  +s[i-1]-'a'+1)%M1;
	}
	
}

ll ghash(int l,int r)
{
	int len=r-l+1;
	
	ll res= (has[r]-(has[l-1]*p[len])%M1+M1)%M1;
	return res;
}


int main() 
{
    ios :: sync_with_stdio(0);
     
     cin>>s;
     
     pre();
     
     int q;
     cin>>q;
     
     while(q--)
     {
     	ll l1,r1,l2,r2;
     	cin>>l1>>r1>>l2>>r2;
     	
     	
     	ll v1=ghash(l1,r1);
     	ll v2=ghash(l2,r2);
     	
     	
     	
     	if(v1==v2)
     	cout<<"Yes\n";
     	
     	else
     	cout<<"No\n";
     	
     }
     
     
	
  return 0;
}
