class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int> > q;
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int> > visited(m,vector<int> (n,0));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push(make_pair(i,j));
                    visited[i][j]=1;
                }
            }
        }
        
        int ans = 0;
        
        while(!q.empty())
        {
            queue<pair<int,int> > q1;
            
            while(!q.empty())
            {
                bool flag = 0;
                
                
                    
                pair<int,int> node = q.front();
                int i = node.first;
                int j = node.second;
                cout<<i<<" "<<j<<endl;
                q.pop();
            
                if( (i-1)>=0 && !visited[i-1][j] && grid[i-1][j]==1)
                {
                    q1.push(make_pair((i-1),j));
                    visited[i-1][j]=1;
                    grid[i-1][j]=2;
                    flag=1;
                }
                if( (i+1)<m && !visited[i+1][j] && grid[i+1][j]==1)
                {
                    q1.push(make_pair((i+1),j));
                    visited[i+1][j]=1;
                    grid[i+1][j]=2;
                    flag=1;
                }
                if( (j-1)>=0 && !visited[i][j-1] && grid[i][j-1]==1)
                {
                    q1.push(make_pair((i),j-1));
                    visited[i][j-1]=1;
                    grid[i][j-1]=2;
                    flag=1;
                }
                if( (j+1)<n && !visited[i][j+1] && grid[i][j+1]==1)
                {
                    q1.push(make_pair((i),j+1));
                    visited[i][j+1]=1;
                    grid[i][j+1]=2;
                    flag=1;
                }
                
                
            }
            
            q = q1;
            if(!q1.empty())
                ans++;
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};