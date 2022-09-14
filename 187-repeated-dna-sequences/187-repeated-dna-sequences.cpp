class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string , int > mp;
        vector<string> ans;
        if(s.size()<10){
            return ans;
        }
        for(int i=0;i<s.size()-1;i++){
            
            if(i+9<s.size()){
                string st="";
                for(int j=i;j<i+10;j++){
                    st.push_back(s[j]);
                }
                mp[st]++;
            }
        }
        for(auto i:mp){
            if(i.second>1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};