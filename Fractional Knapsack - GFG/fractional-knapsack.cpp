//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool mycmp(Item a, Item b)
    {
        double r1 = (double) a.value / a.weight;
        double r2 = (double) b.value / b.weight;
        
        return r1 > r2;
    }
    
    /*double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr+n, mycmp);
        
        double value = 0;
        
        int i = 0;
        
        while(W >= 0 && i < n)
        {
            if(arr[i].weight > W)
            {
                value += ((double)arr[i].value / arr[i].weight) * W;
                break;
            }
            else
            {
                W = W - arr[i].weight;
                value += arr[i].value;
                
            }
            i++;
        }
        
        
        return value;
        
    }
        
};*/
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double ans =0;
        sort(arr,arr+n,mycmp);
        
        int capacity = W;
        for(int i=0;i<n;i++){
            int index = i;
            int w = arr[index].weight;
            //cout<<capacity<<" ";
            if(w<=capacity){
                ans+= arr[index].value;
                capacity=capacity-w;
            }else{
                //cout<<(double(capacity)/double(w))<<" "<<double(arr[index].value)<<endl;
                ans+= ((double(arr[index].value))/w)*capacity;
                break;
                
            }
        }
       // cout<<capacity<<endl;
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends