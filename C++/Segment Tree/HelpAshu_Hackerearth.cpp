#include <bits/stdc++.h>

using namespace std;

#define ss second
#define ff first
#define PINF INT_MAX
#define NINF INT_MIN
#define MAX 100000
#define lli long long int
int arr[MAX+1];
pair<int, int> segmentTree[MAX*4];
int n,q;

void buildSegmentTree(int si, int ss, int se)
{
	// cout<<"\nsi: "<<si<<" ss: "<<ss<<" se: "<<se;
	if(ss == se)
	{
		if(arr[ss]&1)
			segmentTree[si] = {1,0};
		else
			segmentTree[si] = {0,1};
		return;
	}

	int mid = ss + (se - ss)/2;
	buildSegmentTree(2*si, ss, mid);
	buildSegmentTree((2*si)+1, mid+1, se);

	segmentTree[si].ff = segmentTree[2*si].ff + segmentTree[(2*si)+1].ff;
	segmentTree[si].ss = segmentTree[2*si].ss + segmentTree[(2*si)+1].ss;
}


int query(int si, int ss, int se, int qs, int qe, bool type)
{
	if(qs>se || qe<ss)
		return 0;
	if(ss>=qs && se<=qe)
	{
		if(type)
			return segmentTree[si].ss;
		else
			return segmentTree[si].ff;
	}

	int mid = (ss + se)/2;

	return query(2*si, ss, mid, qs, qe, type) + query((2*si)+1, mid+1, se, qs, qe, type);
}

void update(int si, int ss, int se, int qi, int val)
{
	if(ss == se)
	{
		if(arr[ss] & 1)
			segmentTree[si] = {0,1};
		else
			segmentTree[si] = {1,0};
		arr[ss] = val;
		return;
	}
  
	int mid = (ss + se)/2;
	if(qi <= mid)
		update(2*si, ss, mid, qi, val);
	else
		update((2*si)+1, mid+1, se, qi, val);

	segmentTree[si].ff = segmentTree[2*si].ff + segmentTree[(2*si)+1].ff;
	segmentTree[si].ss = segmentTree[2*si].ss + segmentTree[(2*si)+1].ss;
}

int main(int argc, char const *argv[])
{
	memset(segmentTree, 0, sizeof segmentTree);
	int ch;

	cin>>n;

	for (int i = 1; i <= n; ++i)
		cin>>arr[i];

	buildSegmentTree(1,1,n);
	
	cin>>q;

	while(q--)
	{
		cin>>ch;
		int a,b, val;
		if(ch==0)
		{
			cin>>a>>val;
			if((arr[a]%2) == (val%2))
				continue;
			else
				update(1,1,n,a,val);
		}
		else if(ch==1)
		{
			cin>>a>>b;
			cout<<query(1,1,n,a,b, 1)<<endl;
		}
		else
		{
			cin>>a>>b;
			cout<<query(1,1,n,a,b, 0)<<endl;
		}
	}

	return 0;
}