#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
#include<utility>
#include<sstream>
#include<deque>
#include<cmath>
using namespace std;
vector<int > g[10005];
int dist[10005]={0};
int m=0;

void dfs(int node,int par,int d)
{
	bool visit[10005]={false};
	visit[node]=true;
	dist[node]=d;
	
	for(int i=0;i<g[node].size();++i)
	{
		if(visit[g[node][i]]==false)
		{
			visit[g[node][i]]=true;
			dist[g[node][i]]=max(dist[g[node][i]],dist[node]+1);
			m=max(m,dist[g[node][i]]);
			dfs(g[node][i],node,dist[g[node][i]]);
		}
		else if(visit[g[node][i]]==true && g[node][i]==par)
		continue;
	}
	
}

int main()
{
   int n;
   scanf("%d",&n);
   for(int i=1;i<n;++i)
   {
   	int a,b;
   	scanf("%d%d",&a,&b);
   	g[a].push_back(b);
   	g[b].push_back(a);
   	
   }
   for(int i=1;i<=n;++i)
   {
   	dfs(i,i,0);
   }
   printf("%d",m);
    return 0;
}
