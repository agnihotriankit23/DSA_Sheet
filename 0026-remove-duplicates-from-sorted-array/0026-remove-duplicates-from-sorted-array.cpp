class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums[0];
        int it =1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==n){
                
            }else{
                nums[it++]= nums[i];
                n=nums[i];
            }
        }
        return it;
    }
};