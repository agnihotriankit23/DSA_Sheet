class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans =1;
        int curr = nums[0];
        
        for(int i=1 ; i<nums.size();i++){
            if(curr!=nums[i]){
                nums[ans]=nums[i];
                ans++;
                curr=nums[i];
            }else{
                
            }
        }
        return ans;
    }
};