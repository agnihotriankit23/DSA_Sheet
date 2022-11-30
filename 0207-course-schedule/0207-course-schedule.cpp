class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indeg(n,0);
        unordered_map<int,set<int> > adj;
        for(auto i:prerequisites)
        {
            int u = i[1];
            int v = i[0];
            
            adj[u].insert(v);
            
            indeg[v]++;
        }
        
        queue<int> q;
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
            {
                q.push(i);
                //cnt++;
            }
        }
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            cnt++;
            
            for(auto i:adj[f])
            {
                indeg[i]--;
                if(indeg[i]==0)
                {
                    q.push(i);
                }
            }
        }
        if(cnt==n) return 1;
        return 0;
    }
};