#define SIZE 1000000
bool isVisisted[SIZE];
std::vector<int> adjList[SIZE];

bool containCycle(int node, int parent)
{
	isVisisted[node] = 1;
	for(int child: adjList[node])
	{
		if(isVisisted[child] && child != parent)
			return true;
		if(containCycle(child, node))
			return true;
	}
	return false;
}