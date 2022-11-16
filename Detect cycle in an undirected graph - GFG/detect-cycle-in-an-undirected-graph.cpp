//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool DFS(int node, int parent,vector<int> &visited,vector<int> adj[])
{
    visited[node]=1;
    for(auto i:adj[node])
    {
        if(visited[i]==1 && i!=parent)
        {
            return 1;
        }
        else if(visited[i]==0)
        {
            bool ans = DFS(i,node,visited,adj);
            if(ans)
                return 1;
        }
    }
    return 0;
}
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        // int n = adj.size();
        // unordered_map<int,set<int> > adjList;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;adj[i].size();j++)
        //     {
        //         adjList[i].insert(adj[i][j]);
        //     }
        // }
        vector<int> visited(V);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                bool ans = DFS(i,-1,visited,adj);
                if(ans)
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends