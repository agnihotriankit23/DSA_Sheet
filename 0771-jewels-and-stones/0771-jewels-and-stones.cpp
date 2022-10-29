class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> mp;
        for(auto i:jewels)
            mp[i]=1;
        
        int ans =0;
        
        for(auto i:stones){
            if(mp[i]==1){
                ans++;
            }
        }
        return ans;
    }
};