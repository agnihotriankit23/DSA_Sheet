//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool DFS(int node, int c,vector<int> &color, vector<int>adj[])
    {
        color[node]=c;
        
        for(auto i: adj[node])
        {
            if(color[i]==-1)
            {
                bool ans = DFS(i,!c,color,adj);
                if(ans==0)
                return 0;
            }
            else if(color[i]!=-1 && color[i]==color[node])
            {
                return 0;
            }
        }
        return 1;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V,-1);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	            bool ans = DFS(i,0,color,adj);
	            if(ans==0)
	                return 0;
	        }
	    }
	    return 1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends