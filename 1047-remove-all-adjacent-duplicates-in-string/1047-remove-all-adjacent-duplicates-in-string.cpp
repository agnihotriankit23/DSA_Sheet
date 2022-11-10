class Solution {
public:
    string removeDuplicates(string s) {
       
        vector<char> ans;
        ans.push_back(s[0]);
        
        for(int i = 1; i< s.size();i++)
        {
            if(ans.size()!=0 && ans.back() == s[i])
            {
                ans.pop_back();
            }
            else
            {
                ans.push_back(s[i]);
            }
        }
        
        string s1 = "";
        for(auto i: ans)
        {
            s1.push_back(i);
        }
       
        
        return s1;
    }
};