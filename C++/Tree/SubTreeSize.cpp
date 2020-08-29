#include <bits/stdc++.h>
using namespace std;

#define size 10000

int maxD, maxN;
std::vector<int> arr[size+1];
int subSize[size+1];
bool vis[size+1];

int dfs(int s)
{
	vis[s]=1;
	int currS=1;
	for(int c:arr[s])
		if(vis[c]==0)
			currS += dfs(c);

	return subSize[s]=currS;
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
	dfs(1);
	for (int i = 1; i <= n; ++i)
		cout<<subSize[i]<<" ";
	return 0;
}