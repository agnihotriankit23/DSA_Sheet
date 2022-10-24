class Solution {
    //int ans =0;
    int len{0};
public:
    bool unique(string s){
        unordered_map<char,int> mp;
        for(auto i:s){
            if(mp[i]==1)
                return 0;
            else
                mp[i]=1;
            
        }
        return 1;
    }
    
    void solve(int ind, string s,vector<string> &arr){
        if(!unique(arr[ind]))
            return;
        
         if (s.size() > len) len = s.size();
        
        
        for(int i = ind;i<arr.size();i++){
            solve(i+1, s+arr[i],arr);
        }
        
        
    }
    void checkLen(string str, vector<string> &arr, int itr) {
        if (!unique(str)) return;
        if (str.size() > len) len = str.size();
        for (int i = itr; i < arr.size(); i++)
            checkLen(str+arr[i], arr, i+1);
    }
    
   
    int maxLength(vector<string>& arr) {
         //solve(0,"",arr);
        // return ans;
        checkLen("", arr, 0);
        return len;
    }
};