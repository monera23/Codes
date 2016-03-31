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
     
    inline int next_int() {
    	int n = 0;
    	char c = getchar_unlocked();
    	while (!('0' <= c && c <= '9')) {
    		c = getchar_unlocked();
    	}
    	while ('0' <= c && c <= '9') {
    		n = n * 10 + c - '0';
    		c = getchar_unlocked();
    	}
    	return n;
    }
     
    struct T{
    	int s0;
    	int s1;
    	int s2;
    	int lazy;
    } tree[300005];
     
    int ar[100005];
     
    void upd(int id,int l,int r,int iter)
    {
    	tree[id].lazy+=iter;
    	
    	if(iter%3==1)
    	{
    	int temp=tree[id].s0;
    	tree[id].s0=tree[id].s2;
    	tree[id].s2=tree[id].s1;
    	tree[id].s1=temp;
     
    	}
    	else if(iter%3==2)
    	{
    	int temp=tree[id].s0;
    	tree[id].s0=tree[id].s1;
    	tree[id].s1=tree[id].s2;
    	tree[id].s2=temp;
    	}
    	else
    	{
    		tree[id].s0=tree[id].s0;
    		tree[id].s1=tree[id].s1;
    		tree[id].s2=tree[id].s2;
    	}
    	
    	
    	
    }
     
    void shift(int id,int l,int r)
    {
    	int mid=(l+r)/2;
    	
    	upd(id << 1 ,l,mid,tree[id].lazy);
    	upd(id << 1 | 1,mid,r,tree[id].lazy);
    	tree[id].lazy=0;
    }
     
    void build(int id,int l ,int r)
    {
    	if(r-l<2)
    	{
    		if(ar[l]%3==0)
    		{
    			tree[id].s0=1;
    		}
    		else if(ar[l]%3==1)
    		{
    			tree[id].s1=1;
    		}
    		else if(ar[l]%3==2)
    		{
    			tree[id].s2=1;
    		}
    		
    		tree[id].lazy=0;
    		return ;
    	}
    	
    	int mid=(l+r)/2;
    	
    	build(id << 1 ,l,mid);
    	build(id<< 1 | 1,mid,r);
    	
    	tree[id].s0=tree[id*2].s0 + tree[id*2+1].s0;
    	tree[id].s1=tree[id*2].s1 + tree[id*2+1].s1;
    	tree[id].s2= tree[id*2].s2 + tree[id*2+1].s2;
    	
    }
     
    void update(int x,int y,int id,int l,int r,int val)
    {
    	if(x>=r or l>=y)
    	return ;
    	
    	if(x<=l && r<=y)
    	{
    		upd(id,l,r,val);
    		return ;
    	}
    	
    	shift(id,l,r);
    	int mid=(l+r)>>1;
    	
    	update(x,y,id << 1,l,mid,val);
    	update(x,y,id << 1 | 1,mid,r,val);
    	
    	tree[id].s0=tree[id*2].s0 + tree[id*2+1].s0;
    	tree[id].s1=tree[id*2].s1 + tree[id*2+1].s1;
    	tree[id].s2= tree[id*2].s2 + tree[id*2+1].s2;
    	
    }
     
    int query(int x,int y,int id,int l,int r)
    {
    	if(x>=r or l>=y)
    	return 0;
    	
    	if(x<=l && r<=y)
    	return tree[id].s0;
    	
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
     
    inline void readint(int &a)
    {
        register int c;
        a = 0;
        do c = getchar_unlocked(); while(c < '0');
        do{
        a = (a << 1) + (a << 3) + c - '0';
        c = getchar_unlocked();
        }while(c >= '0');
    }
         
    inline void printint(int a)
    {
        char s[11];
        int t = -1;
        do{
        s[++t] = a % 10 + '0';
        a /= 10;
        }while(a > 0);
        while(t >= 0)putchar_unlocked(s[t--]);
        putchar_unlocked('\n');
    }
     
    int main() 
    {
        ios :: sync_with_stdio(0);
        
        int n,q;
        readint(n);
        readint(q);
        
        
        
        build(1,0,n);
       // db(tree[1].s1)
        
        while(q--)
        {
        	int t,a,b;
        	readint(t);
        	readint(a);
        	readint(b);
        	
        	if(t==0)
        	{
        		
        		b++;
        		update(a,b,1,0,n,1);
        	}
        	else if(t==1)
        	{
        		
        		b++;
        		
        		int ans= query(a,b,1,0,n);
        		printint(ans);
        	} 
        }
        //db(tree[1].s0)
    	
      return 0;
    } 
