#include<bits/stdc++.h> 
using namespace std;

#define MAX 2000

int t,n,e;
int inDegree[MAX+1];
vector<int> arr[MAX+1];
vector<int> res;

bool kahn(int n)
{
	priority_queue<int, vector<int>, greater<int>> q;
	for(int i=1; i<=n; i++)
		if(inDegree[i]==0)
			q.push(i);
		
	while(!q.empty())
	{
		int curr = q.top();
		res.push_back(curr);
		q.pop();
		for(int child: arr[curr])
			if((--inDegree[child])==0)
				q.push(child);
	}

	return res.size() == n;
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
	if(kahn(n))
		for(int r: res)
			cout<<r<<" ";
	else
		cout<<"Sandro fails.";
	return 0;
}