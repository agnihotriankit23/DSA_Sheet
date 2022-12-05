//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        unordered_set <string>  s(wordList.begin(),wordList.end());
        
        queue< vector<string> > q;
        q.push({beginWord});
        
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int lvl = 0;
        
        vector<vector<string>> ans;
        
        while(!q.empty())
        {
            vector<string> v = q.front();
            q.pop();
            
            if(v.size()>lvl)
            {
                lvl++;
                for(auto i:usedOnLevel)
                    s.erase(i);
                
                usedOnLevel.clear();
            }
            
            string word = v.back();
            
            if(word == endWord)
            {
                if(ans.size()==0)
                {
                    ans.push_back(v);
                }
                else if(ans[0].size() == v.size())
                {
                    ans.push_back(v);
                }
            }
            
            //string temp = word;
            
            for(int i = 0;i<word.size();i++)
            {
                char original = word[i];
                for(char c = 'a';c<='z';c++)
                {
                    word[i]= c;
                    if(s.count(word)>0)
                    {
                        v.push_back(word);
                        usedOnLevel.push_back(word);
                        q.push(v);
                        v.pop_back();
                    }
                }
                word[i]=original;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends