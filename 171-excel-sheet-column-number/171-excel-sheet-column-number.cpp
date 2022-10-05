class Solution {
public:
    int titleToNumber(string columnTitle) {
        unordered_map<char,int> mp;
        int n=1;
        for(char ch='A';ch<='Z';ch++){
            mp[ch]=n++;
        }
        int p=0;
        vector< int> power(8);
        power[0]=1;
        for(int i=1;i<7;i++){
            power[i]= power[i-1]*26;
        }
         int sum =0;
        p=0;
        for(int i=columnTitle.size()-1;i>=0;i--){
            sum+= mp[columnTitle[i]]*power[p++];
            //p++;
        }
        return sum;
    }
};