class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        if(find(wordDict.begin(),wordDict.end(),s)!=wordDict.end()){
            ans.push_back(s);
        }
        
        for(int i=1;i<=s.size();i++){
            string left = s.substr(0,i);
            if(find(wordDict.begin(),wordDict.end(),left)!=wordDict.end()){
                vector<string> temp = wordBreak(s.substr(i),wordDict);
                for(auto i:temp){
                    string str ="";
                    str+=left;
                    str+=" ";
                    str+=i;
                    ans.push_back(str);
                }
            }
        }
        return ans;
    }
};