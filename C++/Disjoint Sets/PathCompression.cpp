int find(int a)
{
	std::vector<int> v;
	while(parent[a]>0)
		v.push_back(a), a = parent[a];

	for(int x: v)
		parent[x] = a;
	return a;
}

// recursive
int find(int a)
{
	if(parent[a] < 0)
		return a;
	return parent[a] = find(parent[a]);
}