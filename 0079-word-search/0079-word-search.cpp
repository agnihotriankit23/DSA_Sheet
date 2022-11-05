class Solution {
public:
    bool DFS(int r,int c, int i,vector<vector<int> > &visited,vector<vector<char>>& board, string word){
        if(i==word.size())
        {
            return 1;
        }
        
        if(r<0 || r>=board.size() || c<0 || c>=board[0].size() || visited[r][c]==1 || word[i]!=board[r][c])
        {
            return 0;
        }
        
        visited[r][c]=1;
        bool ans = (DFS(r+1,c,i+1,visited,board,word) || DFS(r-1,c,i+1,visited,board,word) || DFS(r,c+1,i+1,visited,board,word) || DFS(r,c-1,i+1,visited,board,word));
        
        visited[r][c]=0;
        return ans;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        
        vector<vector<int> > visited(rows,vector<int> (cols,0));
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(DFS(i,j,0,visited,board,word))
                {
                    return 1;
                }
            }
        }
        
        return 0;
    }
};