#define SIZE 1000000
bool isVisisted[SIZE];
int inTime[SIZE], outTime[SIZE];
std::vector<int> adjList[SIZE];
int timer = 1;

void setInOutTime(int node)
{
	isVisisted[node] = 1;
	inTime[node] = timer++;
	for(int child: adjList[node])
		if(!isVisisted[child])
			setInOutTime(child);
	outTime[node] = timer++;
}