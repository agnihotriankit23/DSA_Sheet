class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector< vector<int> > visited(m, vector<int> (n,0));
        
        queue< pair<int,int> > q;
        
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==1 && visited[i][0]==0)
            {
                q.push(make_pair(i,0));
                visited[i][0]=1;
            }
        }
        
        for(int i=0;i<m;i++)
        {
            if(grid[i][n-1]==1 && visited[i][n-1]==0)
            {
                q.push(make_pair(i,n-1));
                visited[i][n-1]=1;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(grid[0][i]==1 && visited[0][i]==0)
            {
                q.push(make_pair(0,i));
                visited[0][i]=1;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(grid[m-1][i]==1 && visited[m-1][i]==0)
            {
                q.push(make_pair(m-1,i));
                visited[m-1][i]=1;
            }
        }
        
        while(!q.empty())
        {
            pair<int,int> f = q.front();
            q.pop();
            
            int i = f.first;
            int j = f.second;
            
            if((i-1)>0 && visited[i-1][j]==0 && grid[i-1][j]==1)
            {
                q.push(make_pair(i-1,j));
                visited[i-1][j]=1;
            }
            
            if((i+1)<m && visited[i+1][j]==0 && grid[i+1][j]==1)
            {
                q.push(make_pair(i+1,j));
                visited[i+1][j]=1;
            }
            
            if((j-1)>0 && visited[i][j-1]==0 && grid[i][j-1]==1)
            {
                q.push(make_pair(i,j-1));
                visited[i][j-1]=1;
            }
            
            if((j+1)<n && visited[i][j+1]==0 && grid[i][j+1]==1)
            {
                q.push(make_pair(i,j+1));
                visited[i][j+1]=1;
            }
        }
        
        int ans = 0;
        
        for(int i=0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(visited[i][j]==0 && grid[i][j]==1)
                    ans++;
            }
        }
        
        return ans;
    }
};