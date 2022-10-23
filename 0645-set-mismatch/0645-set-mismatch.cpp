class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(nums.size()+1,0);
        int sum = 0;
        int n = nums.size();
        for(auto i: nums)
            ans[i]++;
        
        int a,b;
        
        for(int i=1;i<=n;i++){
            if(ans[i]==2)
                a=i;
            if(ans[i]==0)
                b=i;
        }
        return {a,b};
        
    }
};