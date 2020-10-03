#define SIZE 1000000
bool isVisisted[SIZE];
bool colorsOfNode[SIZE];
std::vector<int> adjList[SIZE];
bool isBipartiteGraph(int node, bool color)
{
	isVisisted[node] = true;
	colorsOfNode[node] = color;
	for(int child: adjList[node])
	{
		if(isVisisted[child])
			if(colorsOfNode[node] == colorsOfNode[child])
				return false;
		else
			if(!(isBipartiteGraph(child, color^1)))
				return false;
	}
	return true;
}