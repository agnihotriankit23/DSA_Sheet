class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Always there will be at most 2 elements as majority with frequncy > n/3
        int num1 = -1;
        int num2 = -1;
        int vote1=0;
        int vote2 = 0;
        for(int i=0;i<nums.size();i++){
            if(num1== nums[i]){
                vote1++;
            }else if(num2 == nums[i]){
                vote2++;
            }else if(vote1 == 0){
                num1 = nums[i];
                vote1++;
            }else if(vote2 == 0){
                num2 = nums[i];
                vote2++;
            }else{
                vote1--;
                vote2--;
            }
        }
        vote1=0;
        vote2=0;
        for(auto i:nums){
            if(i==num1)
                vote1++;
            else if(i==num2)
                vote2++;
        }
        vector<int> v;
        if(vote1 > (nums.size())/3)
            v.push_back(num1);
        if(vote2 > (nums.size())/3)
            v.push_back(num2);
        return v;
    }
};