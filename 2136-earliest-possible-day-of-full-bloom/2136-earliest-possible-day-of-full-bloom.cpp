class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int,int> > v;
        for(int i=0;i<plantTime.size();i++){
            v.push_back({growTime[i],plantTime[i]});
        }
        sort(v.begin(),v.end());
        
        int time = 0;
        int curr =0 ;
        
        for(int i = n-1;i>=0;i--){
            curr+=v[i].second;
            time  = max(time, curr+v[i].first);
        }
        return time;
        
    }
};