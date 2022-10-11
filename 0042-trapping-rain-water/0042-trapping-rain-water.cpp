class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> right(n);
        right[n-1]=0;
        int mx = height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]= mx;
        mx=max(mx,height[i]);
        }
        
        vector<int> left(n);
        left[0]=0;
        mx = height[0];
        for(int i=1;i<height.size();i++){
            left[i]= mx;
        mx=max(mx,height[i]);
        }
        int ans =0;
        
        for(int i=1;i<height.size()-1;i++){
            if((min(left[i],right[i]) - height[i])<=0)
                continue;
            ans += min(left[i],right[i]) - height[i];
        }
        for(auto i:left)
            cout<<i<<" ";
        cout<<endl;
        
        for(auto i:right)
            cout<<i<<" ";
        cout<<endl;
        return ans;
    }
};