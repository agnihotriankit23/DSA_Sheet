class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        int mx = INT_MIN;
        for(auto i: words){
            mp[i]++;
            mx = max(mx,mp[i]);
        }
        
        //map<int, vector<string> > mp1;
        vector<vector<string> > v(mx+1);
        for(auto i : mp){
           v[i.second].push_back(i.first);
        }
        vector<string> ans;
        int cnt = k;
        for(int i = mx ;i>=0 && cnt!=0;i--){
            cout<<i<<" ";
            sort(v[i].begin(),v[i].end());
            for(int j=0;j<v[i].size() && cnt!=0;j++){
                cout<<v[i][j]<<" ";
                ans.push_back(v[i][j]);
                cnt--;
            }
            cout<<endl;
        }
        
        // vector<pair<int,string> > v;
        // for(auto i: mp){
        //     v.push_back(make_pair(i.second,i.first));
        // }
        //  sort(v.begin(),v.end());
        // for(auto i:v){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
         
        // //int i = v.size()-1;
        // k = v.size() - k;
        // while(k<v.size()){
        //     ans.push_back(v[k++].second);
        // }
        // sort(ans.begin(), ans.end());
        return ans;
    }
};