#include<bits/stdc++.h> 
using namespace std; 

#define MAX 100000
#define iip pair<int,int> 

vector <vector<iip>> edges(MAX+1); 

int n,m;

void zeroOneBFS(int src) 
{
	vector<int> d(n, INT_MAX);
	d[src] = 0;
	deque<iip> q;
	q.push_front({src, 0});
	while (!q.empty()) {
	    int v = q.front().first;
	    q.pop_front();
	    for (auto edge : edges[v]) {
	        int u = edge.first;
	        int w = edge.second;
	        if (d[v] + w < d[u]) {
	            d[u] = d[v] + w;
	            if (w == 1)
	                q.push_back({u, 1});
	            else
	                q.push_front({u, 0});
	        }
	    }
	}
//	for (int i = 1; i <= n; ++i)
	cout<<d[n];
}

void addEdge(int u, int v, int wt) 
{ 
	edges[u].push_back({v, wt}); 
	edges[v].push_back({u, wt}); 
} 
// Driver function 
int main() 
{ 
    int a,b;
    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        cin>>a>>b;
        if(b > a)
        	addEdge(a, b, 0);
        else
        	addEdge(b, a, 1);
    }
	int src = 1;
	zeroOneBFS(src); 
	return 0; 
} 