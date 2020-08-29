#include <bits/stdc++.h>

using namespace std;

#define PINF INT_MAX
#define NINF INT_MIN
#define MAX 100001
#define STMAX 400001
#define lli long long int
#define endl "\n"
typedef struct QUERY
{
	int S,E;
}Query;

int arr[MAX], segmentTree[STMAX];
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

	segmentTree[si] = min(segmentTree[2*si], segmentTree[(2*si)+1]);
}

void printSegmentTree()
{
	cout<<"\ntree: ";
	for (int i = 1; i <= n*n ; ++i)
		cout<<segmentTree[i]<<" ";
} 

int query(int si, int ss, int se, int qs, int qe)
{
	if(qs>se || qe<ss)
		return PINF;
	if(ss>=qs && se<=qe)
		return segmentTree[si];

	int mid = ss + (se - ss)/2;
	int l = query(2*si, ss, mid, qs, qe);
	int r = query((2*si)+1, mid+1, se, qs, qe);

	return min(l,r); 
}

int main(int argc, char const *argv[])
{
	cin>>n;

	for (int i = 1; i <= n; ++i)
		cin>>arr[i];

	for (int i = 0; i < STMAX; ++i)
		segmentTree[i] = PINF;
	// cout<<"\nbuilding tree\n";
	buildSegmentTree(1, 1, n);
	// cout<<"\nprinting tree\n";
	// printSegmentTree();

	cin>>q;
	Query q1[q];
	int a,b;
	for (int i = 0; i < q; ++i)
	{
		cin>>a>>b;
		q1[i].S = a+1;
		q1[i].E = b+1;
		// cout<<"\nQ"<<1+i<<" min("<<q1[i].S<<","<<q1[i].E<<") is: ";
		cout<<query(1, 1, n, q1[i].S, q1[i].E)<<endl;
	}

	return 0;
}