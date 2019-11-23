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
		void displayDFSList(linkList list[], bool isVisted[])
		{
			struct linkNode* current = first;
			//current = current->next;
			//cout<<"\n..";
			// for(int i=0;i<5;++i)
			// 	cout<<"\n"<<i<<" : "<<isVisted[i];
			// cout<<"\n";
			for(;current!=NULL;current = current->next)
			{
				if(!isVisted[current->data])
				{
					isVisted[current->data] = true;
					cout<<current->data<<" -> ";
					list[current->data].displayDFSList(list,isVisted);
				}
				else
				{
					// cout<<"\n"<<current->data<<"\n";
					continue;
				}
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

	void printGraphDFS(int s,bool isVisted[])
	{
		isVisted[s] = true;

		cout<<"start from : "<<s<<" -> ";
		for(int i=s;(i%(nVert))!=s-1;++i)
			list[i%(nVert)].displayDFSList(list,isVisted); 
	}

	void DFS(int s) 
	{ 
		bool  *isVisted = new bool[nVert];
		for(int i=0; i<nVert; ++i)
			isVisted[i] = false;

		printGraphDFS(s,isVisted);
	}
};


int main() 
{ 
	int V = 5; 

	graph g;
	
	for(int i=0;i<5; ++i)
		g.addVertex(i);
	g.addEdge(0, 2); 
	g.addEdge(2, 0); 
	g.addEdge(0, 1); 
	g.addEdge( 1, 2); 
	g.addEdge( 2, 3); 
	g.addEdge( 3, 3); 
	g.addEdge(4, 3); 
	//g.addEdge(1,0); 
	//g.list[1].displayList();
	g.DFS(2); 
	for(int i=0;i<5;++i)
	{
		cout<<"\n "<<i<<" : ";
		g.list[i].displayList();
	}

	
	return 0; 
} 
