class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int a = nums[i];
            int b = nums[i+1];
            int c = nums[i+2];
            
            if((a+b)>c && (b+c)>a && (a+c)>b){
                ans = max(ans,a+b+c);
            }
        }
        return ans;
    }
};