class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(digits[n-1]==9){
            vector<int> ans;
            int carry=0;
             int sum = digits[n-1] + 1 + carry;
             ans.push_back(sum%10);
            carry = sum/10;
            for(int i=n-2;i>=0;i--){
               sum = digits[i]+carry;
                ans.push_back(sum%10);
                carry = sum/10;
                
            }
            if(carry){
                ans.push_back(carry);
                
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }else{
            vector<int> ans;
            int carry=0;
             int sum = digits[n-1] + 1 + carry;
             ans.push_back(sum%10);
            carry = sum/10;
            for(int i=n-2;i>=0;i--){
               sum = digits[i]+carry;
                ans.push_back(sum%10);
                carry = sum/10;
                
            }
            if(carry){
                ans.push_back(carry);
                
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
    }
};