#include <bits/stdc++.h>
using namespace std;

#define SIZE 100000

struct edge
{
	int from, to, weight;
};

edge edgeList[SIZE+1];
int parent[SIZE+1];

int findParent(int a)
{
	if(parent[a] == -1) return a;
	return parent[a] = findParent(parent[a]);
}

void mergeSets(int a, int b)
{
	parent[a] = b;
}

int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;

	memset(parent, -1, sizeof(parent));

	for (int i = 0; i < m; ++i)
		cin>>edgeList[i].from >> edgeList[i].to >> edgeList[i].weight;

	sort(edgeList, edgeList+m, [](edge a, edge b)
		{ return a.weight < b.weight; });

	int mstSum = 0;
	for(int currEdge=0; currEdge<m; currEdge++)
	{
		int fromSet = findParent(edgeList[currEdge].from);
		int toSet = findParent(edgeList[currEdge].to);

		if(fromSet != toSet)
		{
			mstSum += edgeList[currEdge].weight;
			mergeSets(fromSet, toSet);
		}
	}
	cout << mstSum;
	return 0;
}