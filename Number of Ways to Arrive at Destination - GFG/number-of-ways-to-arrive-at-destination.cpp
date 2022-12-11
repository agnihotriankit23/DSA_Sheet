//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    int mod = int(1e9+7);
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
         set < pair<int,int> > st;
        st.insert({0,0});
        
        vector<int> dist(n,1e9);
        vector<int> ways(n,0);

        ways[0] = 1 ;
        dist[0] = 0 ;

        unordered_map<int , set< pair<int,int> > > adj;

        for(auto i:roads)
        {
            int u = i[0];
            int v = i[1];
            int wt = i[2];

            adj[u].insert({v,wt});
            adj[v].insert({u,wt});
        }

        while(st.size()!=0)
        {
            pair<int,int> p  = *(st.begin());
            st.erase(p);

            int d = p.first;
            int node = p.second;

            for(auto i : adj[node])
            {
                int pdosi = i.first;
                int cost = i.second;

                if(dist[pdosi] == (d+cost))
                {
                    ways[pdosi]= ( ways[pdosi] + ways[node])%mod;
                }
                else if(dist[pdosi] > (d+cost))
                {
                    dist[pdosi] = d+cost;
                    ways[pdosi] = ways[node]%mod;
                    st.insert({dist[pdosi],pdosi});
                }
            }

        }
        return ways[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends