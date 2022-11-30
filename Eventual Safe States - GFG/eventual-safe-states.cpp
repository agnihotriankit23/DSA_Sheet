//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
       unordered_map<int,set<int,greater<int> > > mp;
       for(int i=0;i<V;i++)
       {
           int v = i;
           
           for(auto j:adj[i])
           {
               mp[j].insert(i);
           }
       }
    //   for(int i=0;i<V;i++)
    //   {
    //       cout<<i<<" -> ";
    //       for(auto j:adj[i])
    //       {
    //           cout<<j<<" ";
    //       }
    //       cout<<endl;
    //   }
    //   for(int i=0;i<V;i++)
    //   {
    //       cout<<i<<" -> ";
    //       for(auto j:mp[i])
    //       {
    //           cout<<j<<" ";
    //       }
    //       cout<<endl;
    //   }
       vector<int> ans;
       queue<int> q;
       vector<int> indeg(V,0);
       for(int i=0;i<V;i++)
       {
           for(auto j:mp[i])
           {
               indeg[j]++;
           }
       }
       
       for(int i=V-1;i>=0;i--)
       {
           if(indeg[i]==0)
           q.push(i);
       }
       
       while(!q.empty())
       {
           int node = q.front();
           q.pop();
           
           ans.push_back(node);
           
           for(auto i:mp[node])
           {
               indeg[i]--;
               if(indeg[i]==0)
               q.push(i);
           }
       }
       sort(ans.begin(),ans.end());
       return ans;
       
       
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends