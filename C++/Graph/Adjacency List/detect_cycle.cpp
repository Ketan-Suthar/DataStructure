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
			first = nullptr;
			last = nullptr;
		}

		void insertLast(const int d)
		{
			struct linkNode* newNode = (linkNode*)malloc(sizeof(linkNode));
			newNode->data = d;
			newNode->next = nullptr;
			if(last!=nullptr)
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
			while(current!=nullptr)
			{
				cout<<current->data<<" ";
				current = current->next;
			}
		}
		bool isCyclicUtil(int v, bool visited[], bool *recStack, linkList list[]) 
		{ 
		    if(visited[v] == false) 
		    { 
		        // Mark the current node as visited and part of recursion stack 
		        visited[v] = true; 
		        recStack[v] = true; 
		  		struct linkNode* current = first;
		  		current = current->next;
		        // Recur for all the vertices adjacent to this vertex 
		        while(current!=nullptr)
		        { 
		            if ( !visited[current->data] && list[current->data].isCyclicUtil(current->data, visited, recStack, list))
		                return true; 
		            else if (recStack[current->data])
		                return true; 
		            current = current->next;
		        } 
		  
		    } 
		    recStack[v] = false;  // remove the vertex from recursion stack 
		    return false; 
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

	bool isCyclic() 
	{ 
	    // Mark all the vertices as not visited and not part of recursion 
	    // stack 
	    bool *visited = new bool[nVert]; 
	    bool *recStack = new bool[nVert]; 
	    for(int i = 0; i < nVert; i++) 
	    { 
	        visited[i] = false; 
	        recStack[i] = false; 
	    } 

	    // Call the recursive helper function to detect cycle in different 
	    // DFS trees
	    for(int i = 0; i < nVert; i++) 
	        if (list[i].isCyclicUtil(i, visited, recStack, list)) 
	            return true;

	    return false; 
	} 

	// void DFS(int s) 
	// { 
	// 	bool  *isVisted = new bool[nVert];
	// 	for(int i=0; i<nVert; ++i)
	// 		isVisted[i] = false;

	// 	printGraphDFS(s,isVisted);
	// }
};

int main() 
{ 
	int V = 5; 

	graph g;
	vector<int> adj[V]; 
	for(int i=0;i<5; ++i)
		g.addVertex(i);
	//g.addEdge(0, 2); 
	g.addEdge(2, 0); 
	g.addEdge(0, 1); 
	//g.addEdge( 1, 2); 
	g.addEdge( 2, 3); 
	//g.addEdge( 3, 3); 
	g.addEdge(4, 3);
	//g.addEdge(1,0); 
	//g.list[1].displayList();
	if(g.isCyclic()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle"; 
	for(int i=0;i<5;++i)
	{
		cout<<"\n "<<i<<" : ";
		g.list[i].displayList();
	}

	
	return 0; 
} 
