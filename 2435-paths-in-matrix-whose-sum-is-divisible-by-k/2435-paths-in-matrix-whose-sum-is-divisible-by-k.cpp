

class Solution {
public:
     //int mod = 1000000007;
   
    int mod = 1000000007;
    int DP(int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int k, int sum){
        if(n == 0 && m == 0){
            if((sum + grid[n][m]) % k == 0) return 1;
            return 0;
        }
        if(n < 0 || m < 0) return 0;
        
        if(dp[n][m][sum % k] != -1) return dp[n][m][sum % k];
        
        int up = 0,left = 0;
        up = DP(n - 1, m, grid, dp, k, sum + grid[n][m]) % mod;
        left = DP(n, m - 1, grid, dp, k, sum + grid[n][m]) % mod;
            
        return dp[n][m][sum % k] = (up % mod + left % mod) % mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int sum = 0;
       
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (m, vector<int> (k, -1)));
        return DP(n - 1,m - 1,grid,dp,k,sum) % mod;
        
    }
};