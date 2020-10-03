#include<bits/stdc++.h>
using namespace std;

#define size 1000001
#define endl "\n"

vector<int> adjList[size];
queue<int>q;
int lowestAncestor[size], intime[size];
bool isVisited[size];
int n,noOfEdges,t,source,destination, timer;

void findBridges(int node, int parent=-1)
{
	isVisited[node] = 1;
	intime[node] = lowestAncestor[node] = intime;

	for(int child: adjList[node])
	{
		if(child == parent) // parent of node
			continue;
		if(isVisited[child])
		{
			//backedge found , update the lowest ancestor
			lowestAncestor[node] = min(lowestAncestor[node], intime[child]);
		}
		else
		{
			//forward edge found
			//not visited so call findbridge again
			findbridge(child, node);

			//if lowest ancestor of child if greater than intime of node
			//then it is bridge means it has no other path
			if(lowestAncestor[child] > intime[node])
				cout<<node<<' - '<<child<<'\n';

			//now node will also update its lowest ancestore from child
			lowestAncestor[node] = min(lowestAncestor[node],
					lowestAncestor[child]);
		}
	}
}

int main(int argc, char const *argv[])
{
	cin>>n>>noOfEdges;
	while(noOfEdges--)
		cin >> source >> destination,
	adjList[source].push_back(destination),
	adjList[destination].push_back(source);

	findBridges(1);
	return 0;
}