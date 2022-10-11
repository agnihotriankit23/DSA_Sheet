class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
       int i=INT_MAX;
        int j = INT_MAX;
        
        for(int it=0;it<nums.size();it++){
            if(nums[it]<=i){
                i=nums[it];
            }else if(nums[it]<=j){
                j= nums[it];
            }else{
                return true;
            }
        }
        return false;
    }
};