class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        int n=nums.size();
        cout<<(n*(n+1)/2) -sum<<endl;
        return (n*(n+1)/2) -sum;
    }
};