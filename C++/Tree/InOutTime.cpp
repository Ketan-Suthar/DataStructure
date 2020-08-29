#define MAX 1000

int timer = 1;
int inTimer[MAX], outTimer[MAX];

void setTimer(int v)
{
	isVis[v] = 1;
	inTimer[v] = timer++;
	for(int child: arr[v])
		if(!isVis[child])
			setTimer(child);

	outTimer[v] = timer++;
}