class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<2){
            return s.size();
        }
        int ans=0;
        unordered_map<char,int> mp;
        // for(int i=0;i<s.size();i++){
        //    mp[s[i]]++;
        // }
       
        int curr=0;
        
       for(int i = 0 ; i < s.size() ; i++) {
        if(mp[s[i]]) {
            i = mp[s[i]] - 1 ; 
            mp.clear();
            ans = max(ans,curr);
            curr = 0;
            
        }else {
            mp[s[i]] = i + 1 ; 
            curr++;
        }
        
    }
        
               ans=max(ans,curr);
        return ans;
    }
};