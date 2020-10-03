#define SIZE 1000000
bool isVisisted[SIZE];
std::vector<int> adjList[SIZE];
int subTreeSize[SIZE];

int findSubTreeSize(int node)
{
	isVisisted[node] = 1;
	int currSize = 1;
	for(int child: adjList[node])
	{
		if(!isVisisted[child])
		{
			currSize += findSubTreeSize(child);
		}
	}
	subTreeSize[node] = currSize;
	return currSize;
}
