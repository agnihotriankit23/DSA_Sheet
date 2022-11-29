//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool DFS(int node,vector<int> &vis ,vector<int> &path,vector<int> adj[])
    {
        vis[node]=1;
        path[node]=1;
        
        for(auto i: adj[node])
        {
            if(vis[i]==0)
            {
                if(DFS(i,vis,path,adj)==1)
                return 1;
            }
            else if(vis[i]==1 && path[i]==1)
            {
                return 1;
            }
            
        }
        
        path[node]=0;
        return 0;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        
        
        vector<int> vis(V,0);
        vector<int> path(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(DFS(i,vis,path,adj)==1)
                return 1;
        }
        return 0;
        
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends