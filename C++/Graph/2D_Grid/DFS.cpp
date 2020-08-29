#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MAX 1000

int N,M;
bool vis[MAX][MAX];

int dx[] = {-1,  0, +1,  0};
int dy[] = { 0, +1,  0, -1};

bool isValid(int x, int y)
{
	if(x < 1 || x > N || y < 1 || y > M)
		return false;
	return true;
}

void dfs(int x, int y)
{
	vis[x][y] = 1;
	cout<<x<< " " << y << endl;
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
	dfs(1, 1);
	return 0;
}