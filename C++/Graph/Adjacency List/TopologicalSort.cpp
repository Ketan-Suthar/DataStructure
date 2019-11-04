#include<bits/stdc++.h> 
using namespace std; 

#define MAX_SIZE 20

struct linkNode
{
	int data;
	linkNode* next;
};
class mystack
{
public:

	int s[MAX_SIZE];
	int top;

	mystack()
	{
		top = -1;
	}
	void push(const int v)
	{
		if(top == MAX_SIZE-1)
			cout<<"\n stack is full";
		else
			s[++top] = v;
	}
	int peek()
	{
		if(top == -1)
		{
			//cout<<"\n stack is empty!!";
			return -1;
		}
		else
			return s[top];
	}
	void pop()
	{
		if(top == -1)
			cout<<"\n stack is empty!!";
		else
			--top;
	}
	const bool isEmpty()
	{
		if(top == -1)
			return true;
		else
			return false;
	}
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
		void TopologicalSortUtil(linkList list[], bool isVisted[], mystack &s)
		{
			struct linkNode* current = first;
			isVisted[current->data] = true;
			for(;current!=NULL;current = current->next)
				if(!isVisted[current->data])
					list[current->data].TopologicalSortUtil(list,isVisted, s);

			s.push(first->data);	
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

	void TopologicalSort()
	{
		mystack s;
		bool  *isVisted = new bool[nVert];
		for(int i=0; i<nVert; ++i)
			isVisted[i] = false;
		
		for(int i=0;i<nVert;++i)
			if(isVisted[i]==false)
				list[i].TopologicalSortUtil(list, isVisted, s);

		cout<<"\nTopological order is: ";
		while(s.isEmpty()==false)
		{
			cout<<s.peek()<<" ";
			s.pop();
		}	
	}
};


int main() 
{ 
	int V = 6; 

	graph g;
	vector<int> adj[V]; 
	for(int i=0;i<6; ++i)
		g.addVertex(i);

    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 

	g.TopologicalSort(); 
	for(int i=0;i<V;++i)
	{
		cout<<"\n "<<i<<" : ";
		g.list[i].displayList();
	}
	return 0; 
} 
