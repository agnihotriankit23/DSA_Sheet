class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int t =0;
        int i=0,j=0;
        
        while(i<neededTime.size() && j<neededTime.size()){
            int curr=0, mx =0;
            
            while(j<neededTime.size() && colors[i]==colors[j]){
                curr+=neededTime[j];
                mx = max(mx,neededTime[j]);
                j++;
            }
            
            t += curr-mx;
            i=j;
        }
        return t;
    }
};