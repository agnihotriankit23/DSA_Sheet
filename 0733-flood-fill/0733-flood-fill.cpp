class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        
        queue< pair<int,int> > q;
        vector< vector<int> > visited(n+1,vector<int> (m+1,0));
        
        q.push(make_pair(sr,sc));
        visited[sr][sc]=1;
        
        while(!q.empty())
        {
            pair<int,int> node = q.front();
            q.pop();
            
            int i = node.first;
            int j = node.second;
            
            int prev = image[i][j];
            image[i][j] = color;
           
            
            if((i-1)>=0 && (i-1)<n && j<m && image[i-1][j]==prev && visited[i-1][j]==0){
                q.push(make_pair(i-1,j));
                visited[i-1][j]=1;
            }
            if(i>=0 && (i+1)<n && j<m && image[i+1][j]==prev && visited[i+1][j]==0){
                q.push(make_pair(i+1,j));
                visited[i+1][j]=1;
            }
            if(i<n && (j-1)>=0 && (j-1)<m && image[i][j-1]==prev && visited[i][j-1]==0){
                q.push(make_pair(i,j-1));
                visited[i][j-1]=1 ;          
            }
            if(i<n && j>=0 && (j+1)<m && image[i][j+1]==prev && visited[i][j+1]==0){
                q.push(make_pair(i,j+1));
                visited[i][j+1]=1;
            }
        }
        return image;
    }
};