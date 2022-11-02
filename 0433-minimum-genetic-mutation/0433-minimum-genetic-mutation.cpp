class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string,int> mp;
        
        for(auto i:bank)
            mp[i]=1;
        
        if(mp[end]==0)
            return -1;
        
        queue<pair<string,int> > q;
        q.push({start,0});
        unordered_map<string,int> visited;
        visited[start]=1;
        while(!q.empty()){
            string gene = q.front().first;
            int level = q.front().second;
            q.pop();
            if(gene == end)
                return level;
            
            for(int i=0;i<8;i++){
                string given = "ACGT";
                string temp = gene;
                for(int j=0;j<4;j++){
                    temp[i] = given[j];
                    if(visited[temp]==0 && mp[temp]==1){
                        q.push({temp,level+1});
                        visited[temp]=1;
                    }
                }
            }
           
        }
        return -1;
        
    }
};