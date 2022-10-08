class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff=INT_MAX;
       // int ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int tar=target-nums[i];
            int left=i+1,right=n-1;
            while(left<right){
                if(abs(diff)>abs(tar-nums[left]-nums[right])){
                    diff=tar-nums[left]-nums[right];
                }
                if(nums[left]+nums[right]==tar){
                    return target;
                }
                if(nums[left]+nums[right]<tar){
                    left++;
                }else{
                    right--;
                }
            }
        }
        return target-diff;
    }
};