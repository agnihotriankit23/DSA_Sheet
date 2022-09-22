class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string curr="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                curr.push_back(s[i]);
            }else{
                reverse(curr.begin(),curr.end());
                ans+=curr;
                ans.push_back(' ');
                curr="";
            }
        }
        reverse(curr.begin(),curr.end());
                ans+=curr;
        return ans;
    }
};