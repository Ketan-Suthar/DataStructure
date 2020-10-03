#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MAX 30

bool isVisited[MAX+1][MAX+1];
int dis[MAX+1][MAX+1];
char grid[MAX+1][MAX+1];
int N;
int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};


bool isValid(int x, int y)
{
	if(x < 0 || x >= N || y < 0 || y >= N)
		return false;
	if(isVisited[x][y] || grid[x][y] == 'T')
		return false;
	return true;
}


int findMinimSteps(int startX=0, int startY=0)
{
	queue<pair<int, int>> q;
	q.push({startX, startY});
	isVisited[startX][startY] = 1;
	dis[startX][startY] = 0;

	while(!q.empty())
	{
		int currX = q.front().first;
		int currY = q.front().second;
		q.pop();
		for(int i=0; i < (sizeof(dx)/ sizeof(int)); i++)
		{
			int newX = currX + dx[i];
			int newY = currY + dy[i];
			if(isValid(newX, newY))
			{
				isVisited[newX][newY] = 1;
				dis[newX][newY] = dis[currX][currY] + 1;
				q.push({newX, newY});
				if(grid[newX][newY] == 'E')
					return dis[newX][newY];
			}
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int sourceX, sourceY;
	cin>>N;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
		{
			cin>>grid[i][j];
			if(grid[i][j] == 'S')
				sourceX = i, sourceY = j;
		}
	cout<<findMinimSteps(sourceX, sourceY)<<'\n';
	return 0;
}


