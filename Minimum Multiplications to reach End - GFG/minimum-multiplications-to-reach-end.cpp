//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        set< pair<int,int> > st;
        vector<int> dist(99999,INT_MAX);
        dist[start] = 0;
        st.insert({0,start});
        
        while(st.size()!=0)
        {
            pair<int,int> p = *(st.begin());
            st.erase(p);
            
            int num = p.second;
            int steps = p.first;
            
            if(num == end)
            return steps;
            
            if(num == 99999)
            {
                return -1;
            }
            
            for(int i = 0 ; i< arr.size();i++)
            {
                int n = (num*arr[i])%100000 ;
                if(dist[n] >( steps +1) )
                {
                    dist[n] = steps + 1;
                    st.insert( { dist[n],n});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends