//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue <pair<int, pair<int,int> >, vector<pair<int, pair<int,int> >>, greater<pair<int, pair<int,int> >> > pq;
        pq.push({ 0 , { 0,-1}});
        
        vector<int> vis(V,0);
        int sum = 0 ;
        vector< pair<int,int> > MST;
        while(!pq.empty())
        {
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            int wt = pq.top().first;
            
            pq.pop();
            
            if(parent!= -1 && vis[node]==0)
            {
                sum+= wt;
                MST.push_back({parent,node});
            }
            if(vis[node]==1) continue;
            vis[node] = 1;
           
            for(auto e : adj[node])
            
            {
                //cout<<node<<" "<<e[0]<<" "<<e[1]<<"\n";
                if(vis[e[0]]==0)
                {
                    pq.push({e[1], {e[0],node}});
                }
            }
            
        
            
        }
        
        
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends