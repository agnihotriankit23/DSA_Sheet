//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set< pair<int,int> > s;
        s.insert({0,S});
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        
        while(s.size()!=0)
        {
            pair<int,int > p = *(s.begin());
            int d = p.first;
            int node = p.second;
            s.erase({d,node});
            
            for(auto i: adj[node])
            {
                int pdosi = i[0];
                int wt = i[1];
                
                if(d + wt < dist[pdosi])
                {
                    dist[pdosi] = d  + wt;
                    s.insert({dist[pdosi],pdosi});
                }
            }
        }
        return dist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends