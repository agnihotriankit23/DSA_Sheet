class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //vector<vector<int> > ans;
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int> > visited(m, vector<int> (n,0));
         vector<vector<int> > ans(m, vector<int> (n,0));
        queue< pair< pair<int,int>, int > > q;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push(make_pair(make_pair(i,j),0));
                    visited[i][j]=1;
                    ans[i][j]=0;
                }
            }
        }
        while(!q.empty())
        {
            pair< pair<int,int>, int > f = q.front();
            q.pop();
            int i = f.first.first;
            int j = f.first.second;
            int d = f.second;
            
            if((i-1)>=0 && mat[i-1][j]==1 && visited[i-1][j]==0)
            {
                //ans[i-1][j]=d+1;
                q.push(make_pair(make_pair(i-1,j),d+1));
                visited[i-1][j]=1;
            }
            if((i+1)<m && visited[i+1][j]==0 && mat[i+1][j]==1)
            {
                //ans[i+1][j]=d+1;
                q.push(make_pair(make_pair(i+1,j),d+1));
                visited[i+1][j]=1;
            }
            if((j-1)>=0 && visited[i][j-1]==0 && mat[i][j-1]==1)
            {
                //ans[i][j-1]=d+1;
                q.push(make_pair(make_pair(i,j-1),d+1));
                visited[i][j-1]=1;
            }
            if((j+1)<n && visited[i][j+1]==0 && mat[i][j+1]==1)
            {
                //ans[i][j+1]=d+1;
                q.push(make_pair(make_pair(i,j+1),d+1));
                visited[i][j+1]=1;
            }
            ans[i][j]=d;
        }
        return ans;
    }
};