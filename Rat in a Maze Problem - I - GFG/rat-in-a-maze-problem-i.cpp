//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(int i, int j,int n,vector<vector<int>> &m,vector<vector<int>> &v){
        if((i>=0 && i<n) && (j>=0 && j<n) && v[i][j]==0 && m[i][j]==1){
            return 1;
        }
        return 0;
    }
    void solve(int i, int j, string path, vector<vector<int>> &m, int n, vector<string> &ans, vector<vector<int>> &v){
        
        if(i==n-1 && j==n-1){
            ans.push_back(path);
            return;
        }
        
        if(m[i][j]==0)
        return;
        
        v[i][j]=1;
        
        //Take D
        if(isSafe(i+1,j,n,m,v)){
            path.push_back('D');
            solve(i+1,j,path,m,n,ans,v);
            path.pop_back();
        }
        
        
        //Take L
        if(isSafe(i,j-1,n,m,v)){
            path.push_back('L');
            solve(i,j-1,path,m,n,ans,v);
            path.pop_back();
        }
        
        
        //Take R
        if(isSafe(i,j+1,n,m,v)){
            path.push_back('R');
            solve(i,j+1,path,m,n,ans,v);
            path.pop_back();
        }
        
        
        //Take U
        if(isSafe(i-1,j,n,m,v)){
            path.push_back('U');
            solve(i-1,j,path,m,n,ans,v);
            path.pop_back();
        }
        
        
        v[i][j]=0;
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0]==0 || m[n-1][n-1]==0)
            return ans;
        
        
        vector<vector<int> > v(n, vector<int> (n,0));
        string path = "";
        solve(0,0,path,m,n,ans,v);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends