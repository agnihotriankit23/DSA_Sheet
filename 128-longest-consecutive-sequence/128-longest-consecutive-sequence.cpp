class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(int i:nums){
            s.insert(i);
        }
        int ans=0;
        for(int i:s){
            if(!s.count(i-1)){
                int currNum=i;
                int curr=1;
                
                while(s.count(currNum+1)){
                    curr+=1;
                    currNum+=1;
                }
                
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};