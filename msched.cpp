#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
#include<utility>
#include<sstream>
#include<cmath>
using namespace std;

// Fast IO begins
 
inline int inp()
{
int noRead=0;
char p=getchar_unlocked();
for(;p<33;)
{
p=getchar_unlocked();
};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getchar_unlocked();
}
return noRead;
};
char ob[2048], *at = ob, *end = ob + 2048 - 1;
void flush_buffer()
{
fwrite(ob, 1, at - ob, stdout);
at = ob;
}
void buffer(int k)
{
if(at + 10 > end) flush_buffer();
long long int  d[10], dc = 0;
if(k < 0) *at++ = '-', k = -k;
if(k==0) d[dc++]=0;
while(k) d[dc++] = k % 10, k /= 10;
for(long long int  k = dc; k--; *at++ = d[k] + '0')
*at++=10;
}
 
// Fast IO ends
 

int main()
{
    int n;
    n=inp();
    int m=100005;
    int s=0;
    int sum[100003]={0};
    vector<pair<int ,int > > v;
    vector<pair<int ,int > >::iterator it;
    
    for(int i=0;i<n;++i)
    {
    	int a,b;
    	a=inp();
    	b=inp();
    	v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end());
    
    for(int i=v.size()-1;i>=0;i--)
    {
    	int temp=v[i].second;
    	
    	while(temp)
    	{
    	if(!sum[temp])
       {
    	sum[temp]=1;
    //	cout<<sum[v[i].first]<<" ";
    	s=s+v[i].first;
    	break;
       }
       else
       temp--;
       
    	}
    }
    
    printf("%d\n",s);
    
    return 0;
}

