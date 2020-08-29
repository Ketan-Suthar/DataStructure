#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MAX 1000

int arr[MAX][MAX];
int N,M;
bool vis[MAX][MAX];

int dx[] = {-1, 0, 1,  0};
int dy[] = { 0, 1, 0, -1};

bool isValid(int x, int y)
{
	if(x < 1 || x > N || y < 1 || y > M || (arr[x][y]==0))
		return false;
	return true;
}

void dfs(int x, int y)
{
	vis[x][y] = 1;
	for(int i=0; i<(sizeof dx/ sizeof dx[0]); i++)
	{
		int xi = x+dx[i], yi = y+dy[i];
		if(!vis[xi][yi] && isValid(xi, yi))
			dfs(xi ,yi);
	}
}

int main(int argc, char const *argv[])
{
	cin>>N>>M;
	int cc=0;

	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			cin>>arr[i][j];

	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			if(vis[i][j]==0 && arr[i][j]==1)
				dfs(i, j), ++cc;
	cout<<endl<<cc;
	return 0;
}