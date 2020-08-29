#include<bits/stdc++.h>
using namespace std;

#define MAX 100001
vector<int> arr[MAX], primes;

int dis[MAX];
bool vis[MAX];
int n,e,t;

bool isPrime(int temp)
{
	for(int i=2; i*i<=temp; i++)
		if(temp%i==0)
			return false;
	return true;
}

bool isValid(int a,int b)
{
	int cnt=0;
	while(a)
	{
		if((a%10) != (b%10))
			++cnt;
		a/=10;
		b/=10;
	}
	if(cnt==1)
		return true;
	return false;
}

void buildGraph()
{
	for(int i=1000; i<=9999; i++)
		if(isPrime(i))
			primes.push_back(i);

	for(int i=0; i<primes.size(); i++)
		for(int j=i+1; j<primes.size(); j++)
		{
			int aa=primes[i];
			int bb=primes[j];
			if(isValid(aa,bb))
			{
				arr[aa].push_back(bb);
				arr[bb].push_back(aa);
			}
		}
}


void bfs(int src)
{
	queue<int>q;
	q.push(src);
	vis[src]=1;
	dis[src]=0;

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
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a,b;
	buildGraph();
	cin>>t;
	
	while(t--)
	{
		cin>>a>>b;
		for(int i=1000;i<=9999; i++)
			vis[i]=0, dis[i]=-1;

		bfs(a);

		if(dis[b] == -1)
			cout<<"Impossible";
		else
			cout<<dis[b];
		cout<<endl;
	}
}