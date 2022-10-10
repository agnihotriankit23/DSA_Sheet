class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int> > ans;
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            int st = i+1;
            
            int end = nums.size()-1;
            
            while(st<end)
            {
                if((nums[i]+nums[st]+nums[end])==0)
                {
                    ans.insert({nums[i],nums[st],nums[end]});
                   st++;
                    end--;
                    
                    
                }
                else if((nums[i]+nums[st]+nums[end])>0)
                {
                    end--;
                }
                else
                {
                    st++;
                }
            }
        }
        vector<vector<int> > ans1 (ans.begin(),ans.end());
        // copy(ans.begin(), ans.end(), ans1.begin()); 
        return ans1;
    }
};