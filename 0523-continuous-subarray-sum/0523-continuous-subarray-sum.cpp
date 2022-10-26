class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
    	// initialize the hash map with index 0 for sum 0
        unordered_map<int, int> mp{{0, -1}};
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int r  = sum%k;
            if(mp.count(r)==0){
                mp[r]=i;
            }else if(i - mp[r] >1)
                return 1;
        }
        return false;
    }
};