
// Useful functions 

// find(x) for Union with path compression 
int find(int x)
{
	if(x!=parent[x])
	parent[x]=find(parent[x]);
	return parent[x];
	
}

// gcd 
int gcd(int a,int b)
{
    if(b==0)
    return a;
    else 
    return gcd(b,a%b);
}

// code to separate words

string str;
    
    while(getline(cin,str))
    {
        istringstream iss(str);
        string word;
        while(iss>>word)
        cout<<word<<" ";
    }
    
    //matrix exponentiation
    
    int A[3][3],ANS[3][3],temp[3][3];

void  fast_expo(int n)
{
    while(n)
    {
            
        if(n%2==1)
        {
            memset(temp,0,sizeof(temp));
        for(int i=1;i<=2;i++)
    for(int j=1;j<=2;j++)
    for(int k=1;k<=2;k++)
    temp[i][j]+=ANS[i][k]*A[k][j],temp[i][j]%=MOD;
        f(i,1,2)
        f(j,1,2)
        ANS[i][j]=temp[i][j];
        
        }
      memset(temp,0,sizeof(temp));
      for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
    for(int k=1;k<=2;k++)
    temp[i][j]+=A[i][k]*A[k][j],temp[i][j]%=MOD;
        f(i,1,2)
        f(j,1,2)
        A[i][j]=temp[i][j];
        
        n/=2;
        
    }
}

// to find lowest set 1 in number 
lb=x &(-x);

//to convert a number into all 1's
a=a|a+1;

// powerset(all subsets of array)
void printPowerSet(char *set, int set_size)
{
    /*set_size of power set of a set with set_size
      n is (2**n -1)*/
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;
 
    /*Run from counter 000..0 to 111..1*/
    for(counter = 0; counter < pow_set_size; counter++)
    {
      for(j = 0; j < set_size; j++)
       {
          /* Check if jth bit in the counter is set
             If set then pront jth element from set */
          if(counter & (1<<j))
            printf("%c", set[j]);
       }
       printf("\n");
    }
}

 //  anagram or next permutation 
 
 void anagram(string s){
    sort(s.begin(), s.end());
    do
        c++;
    while(next_permutation(s.begin(), s.end()));
}   
// check for palindromes in a string (number of palin)

int count(string s)
{
    int n = s.length();
    int res = 0;
    // pick the middle point m:
    for (int m = 0; m < n; m++) {
        // Try an odd-length substring (even == 0), and also an even-length one (even == 1):
        for (int even = 0; even < 2; even++) {
            int i, j;
            // initialize pointers depending on even or not:
            bool pal = true;
            if (even == 1) {
                i = m;
                j = m + 1;
                res++;
            } else {
                i = m - 1;
                j = m + 1;
            }
            // do the check:
            while ( (i >= 0) && (j < n) ) {
                pal = (pal && (s[i] == s[j]) );
                if (pal) {
                    res++;
                }
                i--;
                j++;
            }
        }
    }
    return res;
}

// topological sort

set<int > s;

	if(valid[i]==true && deg[i]==0)         // first insert all nodes having 0 incoming edges
			{
			s.insert(i);
			
			}

while(!s.empty())                     // we get lexicographically smallest sort (set)
		{
			it=s.begin();
			
			cout<<*it<<" ";
			
			int nod=*it;
			
			s.erase(it);
			
			for(int i=0;i<g[nod].size();i++)
			{
				deg[g[nod][i]]--;                    // decrease degree of neighbours
				if(deg[g[nod][i]]==0)                // if 0 incoming nodes insert in set
				s.insert(g[nod][i]);
			}
		}
		
		
// modular exponentiation a^b

ll modpow(ll a,ll b)
{
	ll ret=1;
	while(b>0)
	{
		if(b&1)
		{
			ret*=a;
			if(ret>=MOD)
			ret%=MOD;
		}
		a*=a;
		b/=2;
		if(a>=MOD)
		a%=MOD;
		
	}
	return ret;
}	


// all substrings of string 

for(int k=0;k<n;k++)
		{
			s2="";
			for(int i=0;i<n-k;i++)
			{
				int j=i+k;
				s2+=s[j];
				
				sort(all(s2));
				m[s2]++;
				
			}
		}
		
// check for if string is palindrome 

bool ispal(string a)
{
    string b=a;
    reverse(b.begin(),b.end());
    return a==b;
}		

// compare function for pair sorting 

bool cmp(pair<int,char> lhs,pair<int,char> rhs)
{
  if(lhs.ff==rhs.ff)
  return lhs.ss>rhs.ss;
  
  else
  return lhs.ff<rhs.ff;
}
