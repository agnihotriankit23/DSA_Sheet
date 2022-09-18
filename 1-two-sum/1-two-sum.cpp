class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<int> temp;
       
        temp=nums;
        sort(temp.begin(),temp.end());
        int i=0,j=temp.size()-1;
        int n1,n2;
        while(i<j){
            if((temp[i]+temp[j])==target){
                n1=temp[i];
                n2=temp[j];
                break;
            }else if((temp[i]+temp[j])>target){
                j--;
            }else{
                i++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==n1){
                ans.push_back(i);
                break;
            }
            
        }
         for(int i=0;i<nums.size();i++){
           
            if(i!=ans[0] && nums[i]==n2){
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};