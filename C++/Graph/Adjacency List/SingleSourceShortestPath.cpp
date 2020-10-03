#include<bits/stdc++.h>
using namespace std;

#define SIZE 10000
vector<int> adjList[SIZE+1];

int dis[SIZE+1];
bool isVisited[SIZE+1];
int n,e,t,a,b;

void singleSourceShortestPath(int source)
{
	queue<int>q;
	isVisited[source] = 1;
	dis[source] = 0;
	q.push(source);
	while(!q.empty())
	{
		int currNode = q.front();
		q.pop();

		for(int child: adjList[currNode])
			if(!isVisited[child])
			{
				q.push(child);
				isVisited[child] = 1;
				dis[child] = dis[currNode] + 1;
			}
	}
}