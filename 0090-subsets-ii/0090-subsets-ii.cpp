class Solution {
public:
    void solve(int i,vector<int> temp,vector<int> &nums,vector<vector<int> > &ans){
        if(i==nums.size()){
            return;
            
        }
        sort(temp.begin(),temp.end());
        if(find(ans.begin(),ans.end(),temp)==ans.end())
        ans.push_back(temp);
        solve(i+1,temp,nums,ans);
        temp.push_back(nums[i]);
         sort(temp.begin(),temp.end());
        if(find(ans.begin(),ans.end(),temp)==ans.end())
        ans.push_back(temp);
        solve(i+1,temp,nums,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> temp;
        solve(0,temp,nums,ans);
        return ans;
    }
};