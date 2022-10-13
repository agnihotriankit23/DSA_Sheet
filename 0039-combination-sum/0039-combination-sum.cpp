class Solution {
public:
    
    void solve(int target, vector<int> &candidates,vector<int> temp,vector<vector<int>> &ans){
        if(target==0){
            sort(temp.begin(),temp.end());
            if(find(ans.begin(),ans.end(),temp)==ans.end())
            ans.push_back(temp);
            return ;
        }
        
        if(target<0)
            return;
        
        for(int i=0;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            solve(target-candidates[i],candidates,temp,ans);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        
        vector<int> temp;
        
        solve(target,candidates,temp,ans);
        return ans;
    }
};