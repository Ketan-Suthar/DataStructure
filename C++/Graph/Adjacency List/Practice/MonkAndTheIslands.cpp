#include<bits/stdc++.h>
using namespace std;

#define size 10001
vector<int> arr[size];
queue<int>q;
int dis[size];
bool vis[size];
int n,e,t,a,b;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		for(int i=0;i<size; i++)
			arr[i].clear(), vis[i]=0, dis[i]=0;
		cin>>n>>e;
		while(e--)
		{
			cin>>a>>b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		q.push(1);
		vis[1]=1;
		dis[1]=0;
		while(!q.empty())
		{
			int node=q.front();
			q.pop();
			for(int child: arr[node])
				if(vis[child]==0)
				{
					q.push(child);
					dis[child]=dis[node]+1;
					vis[child]=1;
				}
		}
		cout<<dis[n]<<endl;
	}
}