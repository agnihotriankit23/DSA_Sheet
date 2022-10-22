class Solution {
public:
    string minWindow(string s, string t) {
        
        if(t=="")
            return "";
        
        unordered_map<char,int> countT;
        unordered_map<char,int> window;
        
        for(auto i:t)
            countT[i]+= 1;
        
        int have = 0, need = countT.size();
        
        pair<int,int> res = {-1,-1};
        int resLen = INT_MAX;
        
        int l = 0;
        
        for(int r =0;r<s.size();r++){
            char c = s[r];
            window[c]+=1;
            
            if(countT[c]>=1 && window[c]==countT[c]){
                have+=1;
            }
            
            while(have == need){
                if((r - l +1)<resLen){
                    res = {l,r};
                    resLen = r - l +1;
                }
                window[s[l]]-=1;
                if(countT[s[l]]>=1 && window[s[l]]<countT[s[l]]){
                    have-=1;
                }
                l+=1;
            }
            
        }
        cout<<res.first<<" "<<res.second<<endl;
        if(resLen!=INT_MAX){
            int r = res.second;
            string ans = "";
            for(int i=res.first;i<=res.second;i++){
                ans.push_back(s[i]);
            }
            return ans;
        }
        return "";
        
        
    }
};