#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
using namespace std;

vector<char> arr[100];
int FT[500], S[101], T[101], timer;
int n;

void eulerTour(int node, int par)
{
	cout<<"node: "<<node<<" par: "<<par<<endl; 
	S[node] = timer;
	FT[timer] = node;
	++timer;

	for(int child: arr[node])
		if(child != par)
			eulerTour(child, node);

	T[node] = timer;
	FT[timer] = node;
	++timer;
}

void printTour()
{
	cout<<"FT:[";
	for(int i=1; i<=(2*n); i++)
		cout<<FT[i]<<",";
	cout<<"]\n";
	cout<<"S:[";
	for(int i=1; i<=n; i++)
		cout<<S[i]<<",";
	cout<<"]\n";
	cout<<"T:[";
	for(int i=1; i<=n; i++)
		cout<<T[i]<<",";
	cout<<"]\n";
}

int main(int argc, char const *argv[])
{
	int ch=1,a,b;
	n=1;
	while(ch)
	{
		++n;
		cin>>a>>b;
		arr[b].pb(a);
		arr[a].pb(b);
		cout<<"\ncontinue? 1/0: ";
		cin>>ch;
	}
	timer=1;
	eulerTour(1, -1);
	printTour();
	return 0;
}