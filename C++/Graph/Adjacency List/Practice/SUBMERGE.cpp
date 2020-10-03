#include<bits/stdc++.h> 
using namespace std;

#define SIZE 100000
vector<int> adjList[SIZE+1];
bool isVisited[SIZE+1];
int n,e;
set<int> articulatePoints;
int timer, intime[SIZE+1], lowestAncestor[SIZE+1];

void findArticulatePoints(int node, int parent = -1)
{
	isVisited[node] = 1;
	intime[node] = lowestAncestor[node] = timer++;
	int childrens = 0;
	for(int child: adjList[node])
	{
		if(child == parent) continue;
		if(isVisited[child])
			lowestAncestor[node] = min(lowestAncestor[node],
				intime[child]);
		else
		{
			findArticulatePoints(child, node);
			lowestAncestor[node] = min(lowestAncestor[node],
				lowestAncestor[child]);

			if(intime[node] <= lowestAncestor[child] && parent != -1)
				articulatePoints.insert(node);
			++childrens;
		}
	}
	if(parent == -1 && childrens > 1)
		articulatePoints.insert(node);
}

int main(int argc, char const *argv[])
{
	int a,b;
	while(1)
	{
		cin>>n>>e;
		if(n == 0 && e == 0)
			break;
		for (int i = 1; i <= n; ++i)
			adjList[i].clear(), isVisited[i] = 0;
		timer = 1;
		articulatePoints.clear();
		
		for (int i = 1; i <= e; ++i)
			cin>>a>>b,adjList[a].push_back(b), adjList[b].push_back(a);
		
		for(int i=1; i<=n; i++)
			if(!isVisited[i])
				findArticulatePoints(i);
		
		cout << articulatePoints.size() <<'\n';
	}
	return 0;
}