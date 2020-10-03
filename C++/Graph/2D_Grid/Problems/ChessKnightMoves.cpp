#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MAX 8

bool isVisited[MAX+1][MAX+1];
int dis[MAX+1][MAX+1];
int targetX, targetY, X, Y;
int dx[] = {-2, -1, +1,  2, 2,   1, -1, -2};
int dy[] = { 1,  2,  2,  1, -1, -2, -2, -1};

// corner is not consider
bool isValid(int x, int y)
{
	if(x < 1 || x > MAX || y < 1 || y > MAX)
		return false;
	return true;
}

int dfs()
{
	int x = X, y = Y;
	queue<pair<int,int>> q;
	q.push({x,y});
	isVisited[x][y] = 1;
	dis[x][y] = 0;
	if(x == targetX && y == targetY)
		return dis[x][y];
	while(!q.empty())
	{
		int currX = q.front().first;
		int currY = q.front().second;
		q.pop();
		for(int i=0; i<(sizeof dx/ sizeof dx[0]); i++)
		{
			int xi = currX+dx[i], yi = currY+dy[i];
			if(!isVisited[xi][yi] && isValid(xi, yi))
			{
				q.push({xi, yi});
				dis[xi][yi] = dis[currX][currY] + 1;
				isVisited[xi][yi] = 1;
				if(xi == targetX && yi == targetY)
					return dis[xi][yi];
			}
		}
	}
	return -1;
}

int getX(char x)
{
	return x - 'a' + 1;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		char x,y;
		cin>> x >> y;
		X = getX(x);
		Y = y - '0';

		cin>>x>>y;
		targetX = getX(x);
		targetY = y - '0';

		for(int i=1; i<=8; i++)
			for(int j=1; j<=8; j++)
				isVisited[i][j] = 0;

		cout<< dfs() << '\n';
	}
	
	return 0;
}