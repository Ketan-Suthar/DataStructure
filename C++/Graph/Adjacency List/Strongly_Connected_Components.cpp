#include<bits/stdc++.h> 
using namespace std; 

#define MAX_SIZE 20
class graph;
class mystack
{
public:
	int arr[MAX_SIZE];
	int top = -1;
	//mystack();

	void push(const int x)
	{
		if(top == MAX_SIZE-1)
			cout<<"\nCannot insert stack is full";
		else
			arr[++top] = x;
	}
	inline int peek()
	{
		return arr[top];
	}
	void pop()
	{
		--top;
	}
	void display()
	{
		for(int i=0;i<=top;++i)
			cout<<" - "<<arr[i];
	}
	bool isempty()
	{
		if(top>0)
			return 1;
		else
			return 0;
	}
	//~mystack();
	
};

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
		void DFSUtil(int v, linkList list[], bool isVisted[], mystack &stack)
		{
			struct linkNode* current = first;
			isVisted[v] = true;
			for(;current!=NULL;current = current->next)
			{
				int data = current->data;
				if(!isVisted[data])
				{
					isVisted[data] = true;
					cout<<data<<" -> ";
					list[data].DFSUtil(data, list, isVisted, stack);
				}
			}

			stack.push(v);
			cout<<"\n stack peek: "<<stack.peek();
		}
		friend void reverseEdges(linkList, graph);
};

void reverseEdges(linkList l, graph gt)
{
	struct linkNode* current = l.first;
	int start = current->data;
	current = current->next;
	for(;current!=NULL;current = current->next)
	{
		gt.addEdge(current->data, start);
	}
}
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

	void DFS(int s,bool isVisted[], mystack &stack)
	{
		//isVisted[s] = true;

		cout<<"start from : "<<s<<" -> ";
		int i=s;
		do
		{
			if(!isVisted[i%(nVert)])
			{
				list[i%(nVert)].DFSUtil(i%(nVert), list, isVisted, stack);
			}
			cout<<"hii "<<((i%(nVert)))<<" "<<s;
			++i;
		}while((i%(nVert))!=s);

		//cout<<"\n end";	
	}

/*	void transpose(graph &gt, graph *g)
	{
	
		
	}
*/
	void SCC()
	{
		mystack stack;
		bool  *isVisted = new bool[nVert];
		for(int i=0; i<nVert; ++i)
			isVisted[i] = false;

		DFS(0, isVisted, stack);
		cout<<"\nstack : ";

		graph gt;
		for(int i=0;i<nVert; ++i)
			gt.addVertex(i);

		//gt.transpose(gt, this);

		for(int i=0;i<nVert;++i)
			reverseEdges(list[i], gt);

		for(int i=0;i<nVert;++i)
		{
			cout<<"\n "<<i<<" : ";
			gt.list[i].displayList();
		}

		//stack.display();
	}
};


int main() 
{ 
	int V = 5; 

	graph g;
	
	for(int i=0;i<5; ++i)
		g.addVertex(i);
	g.addEdge(0, 2); 
	//g.addEdge(2, 0); 
	g.addEdge(0, 1); 
	g.addEdge(1, 2); 
	g.addEdge(2, 3); 
	g.addEdge(3, 3); 
	g.addEdge(4, 3); 
	
	g.SCC();

	for(int i=0;i<5;++i)
	{
		cout<<"\n "<<i<<" : ";
		g.list[i].displayList();
	}

	
	return 0; 
} 
