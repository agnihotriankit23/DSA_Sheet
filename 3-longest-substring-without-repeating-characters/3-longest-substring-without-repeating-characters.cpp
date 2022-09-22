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
       
        
        
        for(int i=0;i<s.size();i++){
           
            for(int j=i;j<s.size();j++){
                    if(mp[s[j]]>=1){
                        int curr = mp.size();
                        ans=max(ans,curr);
                        mp.clear();
                        break;
                    }else{
                        mp[s[j]]++;
                    }
            }
            int curr = mp.size();
                        ans=max(ans,curr);
              mp.clear();
            
         }
         int curr = mp.size();
               ans=max(ans,curr);
        return ans;
    }
};