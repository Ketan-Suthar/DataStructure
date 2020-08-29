#include <bits/stdc++.h>

using namespace std;

#define PINF INT_MAX
#define NINF INT_MIN
#define MAX 1000

int arr[MAX], segmentTree[MAX*4], lazy[4*MAX];
int n,q;

void buildSegmentTree(int si, int ss, int se)
{
	// cout<<"\nsi: "<<si<<" ss: "<<ss<<" se: "<<se;
	if(ss == se)
	{
		segmentTree[si] = arr[ss];
		return;
	}

	int mid = ss + (se - ss)/2;
	buildSegmentTree(2*si, ss, mid);
	buildSegmentTree((2*si)+1, mid+1, se);

	segmentTree[si] = (segmentTree[2*si] + segmentTree[(2*si)+1]);
}

void printArray()
{
	cout<<"\narray: ";
	for (int i = 1; i <= n ; ++i)
		cout<<arr[i]<<" ";
}

void printSegmentTree()
{
	cout<<"\ntree: ";
	for (int i = 1; i <= 4*n ; ++i)
		cout<<segmentTree[i]<<" ";
}

void printLazySegmentTree()
{
	cout<<"\nlazy tree: ";
	for (int i = 1; i <= 4*n ; ++i)
		cout<<lazy[i]<<" ";
}

int query(int si, int ss, int se, int qs, int qe)
{
	if(lazy[si] != 0)
	{
		int dx = lazy[si];
		lazy[si] = 0;
		segmentTree[si] += dx * (se-ss+1);

		if(se != ss)
			lazy[si*2] += dx, lazy[(2*si)+1] +=dx;
	}
	if(qs>se || qe<ss)
		return 0;
	if(ss>=qs && se<=qe)
		return segmentTree[si];

	int mid = ss + (se - ss)/2;

	return query(2*si, ss, mid, qs, qe) + query((2*si)+1, mid+1, se, qs, qe);
}

void update(int si, int ss, int se, int qs, int qe, int val)
{
	if(lazy[si] != 0)
	{
		int dx = lazy[si];
		lazy[si] = 0;
		segmentTree[si] += dx * (se-ss+1);

		if(se != ss)
			lazy[si*2] += dx, lazy[(2*si)+1] +=dx;
	}
	if(qs>se || qe<ss)
		return;
	if(ss>=qs && se<=qe)
	{
		int dx = (se - ss + 1)*val;
		segmentTree[si] += dx;

		if(se == ss)
			lazy[2*si] += val, lazy[(2*si)+1] += val;
		return;
	}

	int mid = ss + (se - ss)/2;
	update(2*si, ss, mid, qs, qe, val);
	update((2*si)+1, mid+1, se, qs, qe, val);

	segmentTree[si] =  segmentTree[2*si] + segmentTree[(2*si)+1];
}

int main(int argc, char const *argv[])
{
	memset(lazy, 0, sizeof lazy);
	memset(segmentTree, 0, sizeof segmentTree);
	int ch;

	cin>>n;

	for (int i = 1; i <= n; ++i)
		cin>>arr[i];

	buildSegmentTree(1,1,n);
	printArray();
	printSegmentTree();
	printLazySegmentTree();
	cin>>q;

	while(q)
	{
		cout<<"\n1.for query\n2.for update:\t";
		cin>>ch;
		int a,b, val;
		if(ch==1)
		{
			cin>>a>>b;
			cout<<"\n"<<query(1,1,n,a+1,b+1)<<endl;
		}
		else
		{
			cin>>a>>b>>val;
			update(1,1,n,1+a,1+b,val);
		}
	}

	return 0;
}