
#include<bits/stdc++.h> 
using namespace std; 

#define MAX 100000
#define iip pair<int,int> 

// vector to store edges 
vector <vector<iip>> edges(MAX+1); 

// Prints shortest distance from given source to 
// every other vertex 

int n,m;

void zeroOneBFS(int src) 
{ 
	// Initialize distances from given source 
	int dist[MAX]; 
	for (int i=0; i<MAX; i++) 
		dist[i] = INT_MAX; 

	// double ende queue to do BFS. 
	deque <iip> Q; 
	dist[src] = 0; 
	Q.push_back({src, 0}); 

	while (!Q.empty()) 
	{ 
		int v = Q.front().first; 
		Q.pop_front(); 

		for (int i=0; i<edges[v].size(); i++) 
		{ 
			// checking for the optimal distance 
			if (dist[edges[v][i].first] > dist[v] + edges[v][i].second) 
			{ 
				dist[edges[v][i].first] = dist[v] + edges[v][i].second; 

				// Put 0 weight edges to front and 1 weight 
				// edges to back so that vertices are processed 
				// in increasing order of weights. 
				if (edges[v][i].second == 0) 
					Q.push_front({edges[v][i].first, 0}); 
				else
					Q.push_back({edges[v][i].first, 1}); 
			} 
		} 
	} 

	cout << dist[n-1]; 
} 

void addEdge(int u, int v, int wt) 
{ 
	edges[u].push_back({v, wt}); 
	edges[v].push_back({u, wt}); 
} 

// Driver function 
int main() 
{ 
    int a,b,w;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>a>>b>>w;
        addEdge(a, b, w);
    }
	int src = 0;//source node 
	zeroOneBFS(src); 
	return 0; 
} 

/* sample input
	// n = 9, m = 13;
    // addEdge(0, 1, 0); 
    // addEdge(0, 7, 1); 
    // addEdge(1, 7, 1); 
    // addEdge(1, 2, 1); 
    // addEdge(2, 3, 0); 
    // addEdge(2, 5, 0); 
    // addEdge(2, 8, 1); 
    // addEdge(3, 4, 1); 
    // addEdge(3, 5, 1); 
    // addEdge(4, 5, 1); 
    // addEdge(5, 6, 1); 
    // addEdge(6, 7, 1); 
    // addEdge(7, 8, 1);
*/