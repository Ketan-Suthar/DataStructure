#include <bits/stdc++.h>
using namespace std;

#define iip pair<int, int>
#define SIZE 1000000
std::vector<iip> adjList[SIZE];
int totalEdges, totalNoes;

int main(int argc, char const *argv[])
{
	int from, to, weight;
	cin >> totalNoes >> totalEdges;
	for (int i = 0; i < totalEdges; ++i)
	{
		cin >> from >> to >> weight;
		adjList[from].push_back({to, weight});
		adjList[to].push_back({from, weight});
	}

	priority_queue<iip, vector<iip>, greate<iip>> pq;
	std::vector<int> distance(totalNoes+1, INT_MAX);

	pq.push_back({0, 1});
	distance[1] = 0;

	while(!pq.empty())
	{
		int currNode = pq.front().second;
		int currDistance = pq.front().first;
		pq.pop();
		
		for(auto edge: adjList[currNode])
		{
			if(currDistance + edge.second < distance[edge.first])
			{
				distance[edge.first] = currDistance + edge.second;
				pq.push_back({distance[edge.first], edge.second});
			}
		}
	}
	return 0;
}