class Solution {
    unordered_map< string , int > mp;
    vector<vector<string>> ans;
public:
    
    void DFS(string word,vector<string> &List, int level ,string &beginWord)
    {
        if(word == beginWord)
        {
            reverse(List.begin(),List.end());
            ans.push_back(List);
            reverse(List.begin(),List.end());
            return;
        }
        
        for(int i=0;i<word.size();i++)
        {
            char org  = word[i];
            for(char c = 'a'; c<='z' ; c++)
            {
                word[i] = c;
                if(mp.count(word)>0 && mp[word] == (level-1))
                {
                    List.push_back(word);
                    DFS(word,List,mp[word],beginWord);
                    List.pop_back();
                }
            }
            word[i] = org;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
       
        //unordered_map< string , int > mp;
        
        queue< pair<string,int> > q;
        q.push(make_pair(beginWord,1));
        
        unordered_set< string > st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        while(!q.empty())
        {
            string word = q.front().first;
            int d = q.front().second;
            q.pop();
            
            mp[word] = d;
            
            if(word==endWord)
                break;
            
            for(int i=0;i<word.size();i++)
            {
                char org = word[i];
                for(char c = 'a' ; c<='z' ; c++)
                {
                    word[i] = c;
                    if(st.count(word) > 0)
                    {
                        st.erase(word);
                        q.push(make_pair(word,d+1));
                    }
                }
                word[i] = org;
            }
        }
        
        //vector<vector<string>> ans;
        vector<string> list;
        list.push_back(endWord);
       
        if(mp.count(endWord))
            DFS(endWord,list,mp[endWord],beginWord);  
        return ans;
    }
};