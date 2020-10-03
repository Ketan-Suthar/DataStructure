#include <bits/stdc++.h>
using namespace std;
#define SIZE 10000
std::vector<int> adjList[SIZE+1];
bool isVisited[SIZE+1];
int maximumDistance, farthestNode;

void findFathestNode(int node, int distance)
{
	isVisited[node] = 1;
	if(distance > maximumDistance)
	{
		maximumDistance = distance;
		farthestNode = node;
	}
	for(int child: adjList[node])
		if(!isVisited[child])
			findFathestNode(child, distance+1);
}


int main(int argc, char const *argv[])
{
	int n;
	int a,b;
	cin>>n;
	for(int i=1; i<n; i++)
	{
		cin>>a>>b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}
	maximumDistance = -1;
	findFathestNode(1, 0);
	for(int i=0; i<=SIZE; i++) isVisited[i] = 0;

	maximumDistance = -1;
	findFathestNode(farthestNode, 0);
	cout<<maximumDistance;
	return 0;
}