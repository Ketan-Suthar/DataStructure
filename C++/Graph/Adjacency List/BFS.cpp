#include<bits/stdc++.h> 
using namespace std;

vector<vector<int>> adj;  // adjacency list representation
int n; // number of nodes
int s; // source vertex

queue<int> q;
vector<bool> used(n);
vector<int> dis(n), parent(n);

void bfs(int source)
{
    q.push(source);
    used[source] = true;
    parent[source] = -1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                dis[u] = dis[v] + 1;
                parent[u] = v;
            }
        }
    }
}

void path(int  u)
{
    if (!used[u])
        cout << "No path!";
    else
    {
        vector<int> path;
        for (int v = u; v != -1; v = p[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        cout << "Path: ";
        for (int v : path)
            cout << v << " ";
    }
}