class Solution {
public:
    
     vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
               
                int p1=j+1,p2=n-1;
                while(p1<p2){
                    if((long long)target-nums[i]-nums[j]>nums[p1]+nums[p2]) p1++;
                    else if((long long)target-nums[i]-nums[j]<nums[p1]+nums[p2]) p2--;
                    else{
                        if(nums[p1]==nums[p2]) {
                            ans.push_back({nums[i],nums[j],nums[p1],nums[p2]});
                            break;
                        }
                        ans.push_back({nums[i],nums[j],nums[p1],nums[p2]});
                        int x=nums[p1],y=nums[p2];
                        while(nums[p1]==x) p1++;
                        while(nums[p2]==y) p2--;
                    }
                }
            }
        }
        return ans;
     }
};