class Solution {
public:
    void dfs(int node,vector<int> &visited, vector<vector<int>>& isConnected)
    {
        visited[node]=1;
        int n = isConnected.size();
        for(int i = 0;i<n; i++)
        {
            if(i!=node && isConnected[node][i]==1  && visited[i]==0)
                dfs(i,visited,isConnected);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n);
        int ans = 0;
       
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                ans++;
                dfs(i,visited,isConnected);
            }
        }
        return ans;
    }
};