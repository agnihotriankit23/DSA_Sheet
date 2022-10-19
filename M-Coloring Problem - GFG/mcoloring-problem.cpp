//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(char c,int ind ,vector<char> &v,map<int,set<int>> &adjList){
        for(auto i:adjList[ind]){
            if(v[i]==c)
            return 0;
        }
        return 1;
    }
    bool solve(map<int,set<int>> &adjList,int ind , int n,int m,vector<char> &v,string s){
        if(ind>=n){
            
            return 1;
            
        }
        int ans ;
        // if(v[ind]!=' ')
        //     ans = solve(adjList,ind+1,n,m,v,s);
        // else
        for(int i=0;i<s.size();i++){
            if(isSafe(s[i],ind,v,adjList)){
                v[ind]=s[i];
                ans = solve(adjList,ind+1,n,m,v,s);
                if(ans)
                    return 1;               
                else
                    v[ind]=' ';
            }
            
                
        }
        
        return 0;
        
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        string s ="";
        char ch = 'A';
        int l = m;
        while(l--){
            s.push_back(ch++);
        }
        vector<char> v(n,' ');
        map<int,set<int>> adjList;
        for(int i =0 ;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(graph[i][j]==1){
                    int u = i;
                    int v =j;
                    adjList[u].insert(v);
                    adjList[v].insert(u);
                }
            }
        }
        bool ans = solve(adjList,0,n,m,v,s);
        // for(auto i:adjList){
        //     cout<<i.first<<":->";
        //     for(auto j:i.second){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0;i<n;i++){
            //cout<<i<<" "<<v[i]<<endl;
        }
        for(int i=0;i<n;i++){
                if(v[i]==' ')
                return 0;
            }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends