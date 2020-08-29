#include <bits/stdc++.h>
using namespace std;

#define size 10000

int maxD, maxN;
std::vector<int> arr[size+1];
bool vis[size+1];

void dfs(int s, int d)
{
	vis[s]=1;
	if(d>maxD)
		maxD=d, maxN=s;
	for(int c:arr[s])
		if(vis[c]==0)
			dfs(c,d+1); 
}

int main(int argc, char const *argv[])
{
	int a,b,n;
	cin>>n;
	for (int i = 0; i < n-1; ++i)
	{
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	maxD=-1;
	dfs(1,0);
	for (int i = 0; i <= size; ++i)
		vis[i]=0;
	maxD=-1;
	dfs(maxN,0);
	cout<<maxD;
	return 0;
}