#include<bits/stdc++.h> 
using namespace std;

#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define SIZE 200000

bool isVisisted[SIZE];
std::vector<int> adjList[SIZE];
int intime[SIZE+1], lowestAncestor[SIZE+1];
int timer;
std::vector<pair<int, int>> bidirectionalRoads;
bool hasBridge;

void findBidirectionalRoads(int node, int parent=-1)
{
	isVisisted[node] = 1;
	lowestAncestor[node] = intime[node] = timer++;

	for(int child: adjList[node])
	{
		if(child == parent) continue;
		if(isVisisted[child])
		{
			lowestAncestor[node] = min(lowestAncestor[node],
				intime[child]);
			if(intime[node] > intime[child])
				bidirectionalRoads.push_back({node, child});
		}
		else
		{
			findBidirectionalRoads(child, node);
			lowestAncestor[node] = min(lowestAncestor[node],
				lowestAncestor[child]);
			if(lowestAncestor[child] > intime[node])
			{
				hasBridge = true;
				return;
			}
			bidirectionalRoads.push_back({node, child});
		}
	}
}

int main(int argc, char const *argv[])
{
	FAST;
	int nodes, edges;
	cin>>nodes>>edges;
	while(edges--)
	{
		int a,b;
		cin>>a>>b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}
    timer = 1;
	findBidirectionalRoads(1, -1);

	if(hasBridge)
	{cout<<0;}
	else
	{
	    //cout<<"in else: "<<bidirectionalRoads.size();
		for(auto x: bidirectionalRoads)
		{
			cout<<x.first<<' '<<x.second<<'\n';
		}
	}
	return 0;
}

