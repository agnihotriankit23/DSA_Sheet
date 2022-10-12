//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int solve(int amount,int coins[],int M,vector<int> &dp){
	    if(amount==0)
	    return 0;
	    
	    if(amount<0)
	    return INT_MAX;
	    
	    if(dp[amount]!=-1)
	    return dp[amount];
	    
	    int mn=INT_MAX;
	    for(int i=0;i<M;i++){
	        int ans = solve(amount-coins[i],coins,M,dp);
	        if(ans!=INT_MAX){
                mn=min(mn,ans+1);
            }
	    }
	    return dp[amount]=mn;
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    int amount=V;
	    vector<int> dp(V+1,-1);
	    int ans = solve(amount,coins,M,dp);
	    if(ans!=INT_MAX)
	    return ans;
	    
	    return -1;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends