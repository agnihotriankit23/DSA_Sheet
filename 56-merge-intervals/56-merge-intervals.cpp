class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        
        int ps = ans[0][0];
        int pe = ans[0][1];
        
        for(int i=1;i<intervals.size();i++){
            int cs=intervals[i][0];
            int ce=intervals[i][1];
            
            if(cs<=pe){
                ans.pop_back();
               
                pe=max(pe,ce);
                 ans.push_back({ps,pe});
            }else{
                ps=cs;
                pe=ce;
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};