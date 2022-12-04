//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void BFS(int node , vector<int> &vis , unordered_map<int , vector< pair<int,int> > > &adj , stack<int> &s )
     {
         vis[node]=1;
         
         for(auto i : adj[node])
         {
             if(vis[i.first]==0)
             {
                 BFS(i.first,vis,adj,s);
             }
         }
         
         s.push(node);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        unordered_map<int , vector< pair<int,int> > > adj;
        for(int i=0;i<M;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2];
            
            adj[u].push_back(make_pair(v,d));
        }
        stack<int> s;
        vector<int> vis(N,0);
        for(int i=0;i<N;i++)
        {
            if(vis[i]==0)
            {
                BFS(i,vis,adj,s);
            }
        }
        vector<int> dist(N,INT_MAX);
        
        dist[0]=0;
        
        while(!s.empty())
        {
            int node = s.top();
            if(dist[node]!=INT_MAX)
                for(auto i : adj[node])
                {
                    int d = dist[node] + i.second;
                    dist[i.first] = min(dist[i.first],d);
                }
             s.pop();
        }
        for(int i = 0 ; i<N;i++)
        {
            if(dist[i]==INT_MAX)
                dist[i]=-1;
        }
        return dist;
     }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends