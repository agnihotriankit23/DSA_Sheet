class Solution {
public:
    //int BFS(string s,unordered_map<string,int> &vis,)
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue< pair<string,int> > q;
        
        q.push({beginWord,1});
        
        unordered_map<string,int> vis;
        unordered_map<string,int> mp;
        
        for(auto i : wordList)
        {
            mp[i]=1;
        }
        
        vis[beginWord]=1;
        int ans = 0;
        
        while(!q.empty())
        {
            pair<string,int> p = q.front();
            string s = p.first;
            int lvl = p.second;
            
            if(s == endWord)
                return lvl;
            
            q.pop();
            
            string temp = s;
            for(int i=0;i<s.size();i++)
            {
               
                for(char ch = 'a';ch<='z';ch++)
                {
                    temp[i]=ch;
                    if(mp[temp]==1 && vis[temp]==0)
                    {
                        vis[temp]=1;
                        q.push({temp,lvl+1});
                    }
                    temp = s;
                }
            }
        }
        return ans;
        
    }
};