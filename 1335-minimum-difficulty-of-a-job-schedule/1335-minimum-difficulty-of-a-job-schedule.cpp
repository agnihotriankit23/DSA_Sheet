class Solution {
public:
    
    int solve(int index, int n, int d, vector<int> &job,vector<vector<int> > &dp){
        if(d==1)
            return dp[index][d]=*max_element(job.begin()+index,job.end());
        
        if(dp[index][d]!=-1)
            return dp[index][d];
        
        int result = INT_MAX;
        int currD = INT_MIN;
        
        for(int i=index;i<=n-d;i++){
            currD = max(currD,job[i]);
            result = min(result,currD + solve(i+1,n,d-1,job,dp));
        }
        return dp[index][d]=result;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n<d)
            return -1;
        vector<vector<int> > dp(n+1,vector<int> (d+1,-1));
        return solve(0,n,d,jobDifficulty,dp);
    }
};