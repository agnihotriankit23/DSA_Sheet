class Solution {
public:
    int evenSum(vector<int> &nums){
        int sum=0;
        for(auto i:nums){
            if(i%2==0)
                sum+=i;
        }
        return sum;
    }
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int currSum=0;
        for(int i:nums){
            if(i%2==0)
                currSum+=i;
        }
        for(int i=0;i<queries.size();i++){
            int val = queries[i][0];
            int ind = queries[i][1];
            int prv = nums[ind];
            if(prv%2==0)
                currSum-=prv;
            nums[ind]+=val;
             if(nums[ind]%2==0)
                currSum+=nums[ind];
            ans.push_back((currSum));
        }
        return ans;
    }
};