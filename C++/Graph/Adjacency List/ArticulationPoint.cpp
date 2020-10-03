#define SIZE 1000000
bool isVisisted[SIZE];
std::vector<int> adjList[SIZE];
int intime[SIZE+1], lowestAncestor[SIZE+1];
int timer, totoalNodes;

void findArticulationPointHelper(int node, int parent=-1)
{
	isVisisted[node] = 1;
	intime[node] = lowestAncestor[node] = timer++;
	int childrens = 0;
	for(int child: adjList[node])
	{
		if(child == parent) continue;
		if(isVisisted[child])
			lowestAncestor[node] = min(lowestAncestor[node],
				intime[child]);
		else
		{
			findArticulationPoint(child, node);
			lowestAncestor[child] = min(lowestAncestor[node],
				lowestAncestor[child]);
			if(intime[node] <= lowestAncestor[child] && parent!=-1)
				cout<<"Found ArticulationPoint: "<<node;
			++childrens;
		}
	}
	if(parent==-1 && childrens>1)
		cout<<"Found ArticulationPoint: "<<node;
}

void findArticulationPoint()
{
	for (int i = 0; i <= SIZE; ++i)
	{
		isVisisted[i] = 0;
		intime[i] = lowestAncestor[i] = -1;
	}
	for (int i = 0; i < totoalNodes; ++i)
		if(!isVisisted[i])
			findArticulationPointHelper(i);
}



