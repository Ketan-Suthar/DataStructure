int parent[MAX+1], rank[MAX+1];

void make_set(int v)
{
    parent[v] = v;
    rank[v] = 0;
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}