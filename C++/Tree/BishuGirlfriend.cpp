#include <bits/stdc++.h>
using namespace std;

#define size 1000
vector<int> arr[size+1];
int dis[size+1], n, q;
bool isVis[size+1];

void dfs(int s, int d)
{
	isVis[s] = 1;
	dis[s] = d;
	for(int child: arr[s])
		if(isVis[child] == 0)
			dfs(child, dis[s] + 1);
}

int main()
{
	cin>>n;
	int a,b;

	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	dfs(1, 0);
	int ans = -1, min_dis = INT_MAX;

	cin>>q;
	while(q--)
	{
		cin>>a;
		if(dis[a] < min_dis)
			min_dis = dis[a], ans = a;
		else
			if((dis[a] == min_dis) && (a < ans))
				ans = a;
	}

	cout<<ans;
}