#include<bits/stdc++.h> 
using namespace std;

#define size 2000
int t,n,e;
int inDegree[size+1];
vector<int> arr[size+1];
vector<int> res;

void kahn(int n)
{
	queue<int> q;
	for(int i=1; i<=n; i++)
		if(inDegree[i]==0)
			q.push(i);
		
	while(!q.empty())
	{
		int curr = q.front();
		res.push_back(curr);
		q.pop();
		for(int child: arr[curr])
			if((--inDegree[child])==0)
				q.push(child);
	}
	cout<<"\nTopological order: ";
	for (int i = 1; i <= n; ++i)
		cout<<res[i-1]<<" ";
}

int main(int argc, char const *argv[])
{
	int n,e,a,b;
	cin>>n>>e;
	while(e--)
	{
		cin>>a>>b;
		arr[a].push_back(b);
		inDegree[b]++;
	}
	kahn(n);
	return 0;
}