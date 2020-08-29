#include <bits/stdc++.h>
using namespace std;

#define size_ 1000000
#define endl "\n"

vector<int> arr[size_+1];
int cc[size_+1];
int ccS;
int n,e,t;
bool vis[size_+1];

void dfs(int s)
{
	vis[s]=1;
	cc[s]=ccS;
	for(int c: arr[s])
		if(vis[c]==0)
			dfs(c);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	int a,b;
	string op;
	
	while(t--)
	{
		vector<pair<int, int>> p;
		for(int i=0; i<=size_; i++)
	        arr[i].clear(), vis[i]=0, cc[i]=0;
		cin>>n>>e;
		for (int i = 0; i < e; ++i)
		{
			cin>>a>>op>>b;
			if(op == "=")
			{
				arr[a].push_back(b);
				arr[b].push_back(a);
			}
			else
				p.push_back({a,b});
			
		}
		ccS=0;
		for(int i=1; i<=n; i++)
			if(vis[i]==0)
			{
				++ccS;
				dfs(i);
			}
		bool flag=0;
		for(int it=0; it < p.size(); ++it)
		{
			a = p[it].first;
			b = p[it].second;
			if(cc[a] == cc[b])
			{
				flag=1;
				break;
			}
		}
		if(flag)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}

	return 0;
}