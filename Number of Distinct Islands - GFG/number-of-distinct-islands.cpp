//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  void BFS(int i,int j,vector< pair<int,int> > &v,vector< vector<int> > &vis,vector<vector<int>>& grid ){
      int n = grid.size();
        int m = grid[0].size();
        
      queue< pair<int,int> > q;
      q.push(make_pair(i,j));
      vis[i][j]=1;
      
      while(!q.empty())
      {
          pair<int,int> f = q.front();
          v.push_back(f);
          q.pop();
          
          int i = f.first;
          int j = f.second;
          
          if((i-1)>=0 && vis[i-1][j]==0 && grid[i-1][j]==1)
      {
          q.push(make_pair(i-1,j));
          vis[i-1][j]=1;
      }
      
      if((i+1)<n && vis[i+1][j]==0 && grid[i+1][j]==1)
      {
           q.push(make_pair(i+1,j));
          vis[i+1][j]=1;
      }
      
      if((j-1)>=0 && vis[i][j-1]==0 && grid[i][j-1]==1)
      {
           q.push(make_pair(i,j-1));
          vis[i][j-1]=1;
      }
      
      if((j+1)<m && vis[i][j+1]==0 && grid[i][j+1]==1)
      {
           q.push(make_pair(i,j+1));
          vis[i][j+1]=1;
      }
          
      }
  }
  
  void DFS(int i,int j,vector<pair<int,int> > &v,vector< vector<int> > &vis,vector<vector<int>>& grid,int a,int b)
  {
      vis[i][j]=1;
      v.push_back(make_pair(i-a,j-b));
      
      int n = grid.size();
      int m = grid[0].size();
      
      if((i-1)>=0 && vis[i-1][j]==0 && grid[i-1][j]==1)
      {
          DFS(i-1,j,v,vis,grid,a,b);
      }
      
      if((i+1)<n && vis[i+1][j]==0 && grid[i+1][j]==1)
      {
          DFS(i+1,j,v,vis,grid,a,b);
      }
      
      if((j-1)>=0 && vis[i][j-1]==0 && grid[i][j-1]==1)
      {
          DFS(i,j-1,v,vis,grid,a,b);
      }
      
      if((j+1)<m && vis[i][j+1]==0 && grid[i][j+1]==1)
      {
          DFS(i,j+1,v,vis,grid,a,b);
      }
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector< vector<int> > vis(n, vector<int> (m,0));
        
        set < vector< pair<int,int> > > s;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                {
                    vector< pair<int,int> > v;
                    //BFS(i,j,v,vis,grid);
                    DFS(i,j,v,vis,grid,i,j);
                    s.insert(v);
                }
            }
        }
        /*
        set < vector< pair<int,int> > > ans;
        
        for(int i=0;i<s.size();i++)
        {
            vector<pair < int,int> > v = s[i];
            int a = v[0].first;
            int b = v[0].second;
            for(int j=0;j<v.size();j++)
            {
                v[i].first -= a;
                v[i].second -= b;
            }
            
            ans.insert(v);
        }
        // for(auto i:ans)
        // {
        //     for( auto j:i)
        //     {
        //         cout<<"( "<<j.first<<"  , "<<j.second<<" ) ";
        //     }
        //     cout<<endl;
        // }
        */
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends