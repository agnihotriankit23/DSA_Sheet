class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ct=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                ct++;
            }else{
                ans = max(ct,ans);
                ct=0;
            }
        }
        ans = max(ct,ans);
        return ans;
    }
};