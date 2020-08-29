#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MAX 1000

int N,M;
bool vis[MAX][MAX];
int dis[MAX][MAX];
int dx[] = {-1,  0, +1,  0};
int dy[] = { 0, +1,  0, -1};

// corner is not consider
bool isValid(int x, int y)
{
	if(x < 1 || x > N || y < 1 || y > M)
		return false;
	return true;
}

void dfs(int x, int y)
{
	queue<pair<int,int>> q;
	q.push({x,y});
	vis[x][y] = 1;
	dis[x][y] = 0;
	
	while(!q.empty())
	{
		int currX = q.front().first;
		int currY = q.front().second;
		q.pop();
		for(int i=0; i<(sizeof dx/ sizeof dx[0]); i++)
		{
			int xi = currX+dx[i], yi = currY+dy[i];
			if(!vis[xi][yi] && isValid(xi, yi))
			{
				q.push({xi, yi});
				dis[xi][yi] = dis[currX][currY] + 1;
				vis[xi][yi] = 1;
			}
		}
	}
	cout<<"\ndistance arr:\n";
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=M; j++)
			cout<<dis[i][j]<<" ";
		cout<<endl;
	}
}

int main(int argc, char const *argv[])
{
	cin>>N>>M;
	int x,y;
	cin>>x>>y;
	dfs(x, y);
	return 0;
}