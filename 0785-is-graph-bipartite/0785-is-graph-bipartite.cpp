class Solution {
public:
    
    bool BFS(int node, vector<int> &color,vector<vector<int>>& graph)
    {
        queue<int> q;
        q.push(node);
        color[node]=0;
        
        while(!q.empty())
        {
            int p = q.front();
            q.pop();
            
            for(auto i:graph[p])
            {
                if(color[i]!=-1 && color[i]==color[p])
                {
                    cout<<i<<" "<<p<<endl;
                    return 0;
                }
                else if(color[i]==-1)
                {
                   color[i]= !color[p];
                    q.push(i);
                }
                    
            }
        }
        return 1;
    }
        
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> color(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                bool ans = BFS(i,color,graph);
                if(ans==0)
                    return 0;
            }
        }
        return 1;
    }
};