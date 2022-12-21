//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

void dfs(int node, vector<int> &vis,stack<int> &s, vector<int> adj[])
{
    vis[node]=1;
    for(auto i : adj[node])
    {
        if(vis[i]==0)
        dfs(i,vis,s,adj);
    }
    
    s.push(node);
}

void DFS(int node, vector<int> &vis, unordered_map< int , set<int> > &adjList)
{
    vis[node]=1;
    
    for(auto i : adjList[node])
    {
        if(vis[i]==0)
        DFS(i,vis,adjList);
    }
}
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int> vis(V,0);
        stack<int> s;
        
        for(int i=0;i<V;i++)
            if(vis[i]==0)
                dfs(i,vis,s,adj);
        
        
        unordered_map< int , set<int> > adjList;
        
        for(int i = 0;i<V;i++)
        {
            vis[i] = 0 ;
            for(auto e : adj[i])
            {
                adjList[e].insert(i);
            }
        }
        
       
        int cnt = 0;
        
        while(!s.empty())
        {
            int node = s.top();
            s.pop();
            
            if(vis[node]==0)
            {
                cnt++;
                DFS(node,vis,adjList);
            }
            
            
        }
        return cnt;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends