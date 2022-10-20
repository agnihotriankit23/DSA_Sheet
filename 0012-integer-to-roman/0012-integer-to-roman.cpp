class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string> > v;
        v.push_back({1000,"M"});
        v.push_back({900,"CM"});
        v.push_back({500,"D"});
        v.push_back({400,"CD"});
        v.push_back({100,"C"});
        v.push_back({90,"XC"});
        v.push_back({50,"L"});
        v.push_back({40,"XL"});
        v.push_back({10,"X"});
        v.push_back({9,"IX"});
        v.push_back({5,"V"});
        v.push_back({4,"IV"});
        v.push_back({1,"I"});
        
        string s = "";
        for(int i=0;i<v.size();i++){
            int cnt = num/(v[i].first);
            while(cnt--){
                s+= v[i].second;
            }
            num = num%v[i].first;
        }
        return s;
    }
};