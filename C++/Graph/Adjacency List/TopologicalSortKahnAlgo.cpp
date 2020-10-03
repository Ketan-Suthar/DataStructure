#define SIZE 1000000
bool isVisisted[SIZE];
std::vector<int> adjList[SIZE], ;
int inDegree[SIZE+1];

vector<int> topologicalSort(int n)
{
	std::vector<int> topoSortResult;
	queue<int> q;
	// priority_queue<int, vector<int> v, greater<int>> q; // for sorted order
	for(int i=0; i<n; i++)
		if(!inDegree[i])
			q.push(i);

	while(!q.empty())
	{
		int currNode = q.front();
		topoSortResult.push_back(currNode);
		q.pop();
		for(int child: adjList[currNode])
		{
			inDegree[child]--;
			if(!inDegree[child])
				q.push(child);
		}
	}
	return topoSortResult;
}

