#include<bits/stdc++.h>
using namespace std;

#define SIZE 10000
vector<int> adjList[SIZE+1];

int dis[SIZE+1];
bool isVisited[SIZE+1];
std::vector<int> primes;
int _distance[SIZE+1];

bool isPrime(int num)
{
	for(int i=2; i*i<=num; ++i)
		if(num%i == 0) return false;
	return true;
}

bool isValidPath(int from, int to)
{
	int differece = 0;
	while(from > 0)
	{
		if((from % 10) != (to % 10))
			differece++;
		from /= 10;
		to /= 10;
	}
	if(differece == 1)
		return true;
	return false;
}

void generateGraph()
{
	for(int i=1000; i<=9999; i++)
		if(isPrime(i))
			primes.push_back(i);

	for(int i=0; i<primes.size(); i++)
		for(int j=i+1; j<primes.size(); j++)
		{
			int from = primes[i], to = primes[j];
			if(isValidPath(from, to))
			{
				adjList[from].push_back(to);
				adjList[to].push_back(from);
			}
		}
}

void singleSourceShortestPath(int source)
{
	queue<int> q;
	q.push(source);
	isVisited[source] = 1;
	_distance[source] = 0;
	while(!q.empty())
	{
		int currNode = q.front();
		q.pop();
		for(int child: adjList[currNode])
			if(!isVisited[child])
			{
				q.push(child);
				isVisited[child] = 1;
				_distance[child] = _distance[currNode] + 1;
			}
	}
}


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	generateGraph();
	while(t--)
	{
		int source, destination;
		cin>>source>>destination;
		for(int i=0; i<=SIZE; i++)
			_distance[i] = -1, isVisited[i] = 0;

		singleSourceShortestPath(source);

		if(_distance[destination] == -1)
			cout<<"Impossible";
		else
			cout<<_distance[destination];
		cout<<'\n';
	}
	return 0;
}