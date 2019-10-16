#include<bits/stdc++.h> 
using namespace std; 

#define MAX_SIZE 20
struct linkNode
{
	int data;
	linkNode* next;
};
//typedef linkNode node;
class linkList
{
	public:struct linkNode* first;
		struct linkNode* last;
		linkList()
		{
			first = NULL;
			last = NULL;
		}

		void insertLast(const int d)
		{
			struct linkNode* newNode = (linkNode*)malloc(sizeof(linkNode));
			newNode->data = d;
			newNode->next = NULL;
			if(last!=NULL)
			{
				last->next = newNode;
				last = newNode;
			}
			else
			{
				first = newNode;
				last = newNode;
			}

		}
		void displayList()
		{
			struct linkNode* current = first;
			current = current->next;
			while(current!=NULL)
			{
				cout<<current->data<<" ";
				current = current->next;
			}
		}
};
class graph
{
	public:
	linkList list[20];
	int nVert;

	graph()
	{
		nVert = 0;
	}

	void addVertex(int d)
	{
		if(nVert<20)
		{
			list[nVert].insertLast(d);
			++nVert;
		}
		else
			cout<<"\nyou cant add more vertex!!";
	}

	void addEdge(const int s, const int e) 
	{ 
		list[s].insertLast(e);
	}

	// A utility function to print the adjacency list 
	// representation of graph 
	void printGraph() 
	{ 
		for (int v = 0; v < nVert; ++v) 
		{ 
			cout << "\n Adjacency list of vertex "<<v<<" \n "; 
			list[v].displayList();
			printf("\n"); 
		} 
	} 
};


int main() 
{ 
	int V = 5; 
	graph g;
	vector<int> adj[V]; 
	for(int i=0;i<5; ++i)
		g.addVertex(i);
	g.addEdge(0, 1); 
	g.addEdge(0, 4); 
	g.addEdge(1, 2); 
	g.addEdge( 1, 3); 
	g.addEdge( 1, 4); 
	g.addEdge( 2, 3); 
	g.addEdge( 3, 4); 
	g.addEdge(1,0); 
	g.printGraph(); 
	return 0; 
} 
