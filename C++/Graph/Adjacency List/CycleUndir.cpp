#include<bits/stdc++.h>

using namespace std;

bool vis[10001];

bool dfs(vector<int> g[], int s, int par)
{
    vis[s]=1;
    for(int child: g[s])
    {
        if(vis[child]==0)
        {
            if(dfs(g, child, s)==1)
            {
                return true;
            }
        }
        else
        {
            if((par!=-1) && (!(child==par)))
            {
                return true;
            }
        }
    }
    return false;
}

bool isCyclic(vector<int> g[], int V)
{
   // Your code here
    memset(vis, 0, sizeof vis);
    int res=0;
    for(int i=0; i<V;i++)
        if(vis[i]==0)
        {
            bool temp = dfs(g, i, -1);
            if(temp==1)
                res=temp;
        }
   return res;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends