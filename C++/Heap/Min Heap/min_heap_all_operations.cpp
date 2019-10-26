// min heap program
#include <iostream>
#include <climits>
#include <cstdlib> 
#include <ctime> 
#include<time.h> 
using namespace std;

// A utility function to swap two elements 
void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 
class minheap
{
	int *harr,size,capacity;
	public:
		minheap(int);
		inline int parent(int i)
		{	return ((i+1)/2)-1;	}

		inline int left(int i)
		{	return (2*i)+1;	}

		inline int right(int i)
		{	return (2*i)+2;	}

		inline int getmin() {	return harr[0];	}
		int extractmin(); 
		void deletekey(int);
		void insertkey(int);
		void decreasekey(int,int);
		void minheapify(int);
		void display();
};

minheap::minheap(const int cap)
{
	size = 0;
	capacity = cap;
	harr = new int[cap];
}
//insert new k
void minheap::insertkey(int k)
{
	if(size == capacity)
	{
		cout<<"\nOverflow!! cannot insert new key";
		return;
	}
	harr[size++]=k;
	int i = size-1;
	while(i != 0 && harr[parent(i)] > harr[i])
	{
		//cout<<"\n "<<harr[parent(i)]<<" "<<harr[i]<<"\n";
		swap(&harr[parent(i)], &harr[i]);
		i = parent(i);
	}
}


int minheap::extractmin() 
{ 
    if (size <= 0) 
        return INT_MAX; 
    if (size == 1)
        return harr[size--];
  
    // Store the minimum value, and remove it from heap 
    int root = harr[0]; 
    harr[0] = harr[size-1]; 
    size--; 
    minheapify(0);
    return root; 
}

void minheap::decreasekey(int i, int new_val) 
{ 
    harr[i] = new_val; 
    while (i != 0 && harr[parent(i)] > harr[i]) 
    { 
       swap(&harr[i], &harr[parent(i)]); 
       i = parent(i); 
    } 
}
void minheap::deletekey(int i) 
{ 
    decreasekey(i, INT_MIN); 
    extractmin();
} 

void minheap::minheapify(int i) 
{ 
    int l = left(i); 
    int r = right(i); 
    int smallest = i; 
    if (l < size && harr[l] < harr[i]) 
        smallest = l; 
    if (r < size && harr[r] < harr[smallest]) 
        smallest = r; 
    if (smallest != i) 
    { 
        swap(&harr[i], &harr[smallest]); 
        minheapify(smallest); 
    } 
} 
void minheap::display()
{
	cout<<"\nHeap:: ";
	for(int i=0;i<size;++i)
		cout<<harr[i]<<" ";
}
int main(int argc, char const *argv[])
{
	srand (time(NULL));
	minheap h(20);
	int arr[] = {42,14,15,23,30,65,64,39,38,98};
	for(int i=0; i<10;++i)
	{
		//int n = rand() % 100 + 1; //generate random numbers
		//cout<<"adding: "<<arr[i]<<"\n";
		h.insertkey(arr[i]);
		//h.display();
	}
	cout<<"\nnew heap: ";
	h.display();
	h.decreasekey(9,24);
	h.display();
	for(int i=0;i<10;++i)
		cout<<h.extractmin()<<" ";
	return 0;
}