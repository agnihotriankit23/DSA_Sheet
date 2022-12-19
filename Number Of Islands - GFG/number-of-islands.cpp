//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet{
vector<int> rank,parent,size;

public:

DisjointSet(int n)
{
    rank.resize(n+1,0);
    parent.resize(n+1);
    size.resize(n+1);
    for(int i=0;i<n;i++)
    {
        size[i]=1;
        parent[i]=i;
    }
    
}

int findUltParent(int node)
{
    if(parent[node] == node)
    return node;

    return parent[node]= findUltParent(parent[node]); // This is Path Compression
}

void  UnionByRank(int u, int v)
{
    int ult_pu = findUltParent(u);
    int ult_pv = findUltParent(v);

    if(ult_pu == ult_pv)
    return ; 

    if( rank[ult_pu] < rank[ult_pv])
    {
        parent[ult_pu] = ult_pv;
    }
    else if(rank[ult_pu] > rank[ult_pv])
    {
        parent[ult_pv] = ult_pu;
    }
    else
    {
        parent[ult_pv] = ult_pu;
        rank[ult_pu]++;
    }
}

void UnionBySize(int u, int v)
{
    int ult_pu = findUltParent(u);
    int ult_pv = findUltParent(v);

    if(ult_pu == ult_pv)
    return ; 

    if( size[ult_pu] < size[ult_pv])
    {
        parent[ult_pu] = ult_pv;
        size[ult_pv]+=size[ult_pu];
        
    }
    else if(size[ult_pu] > size[ult_pv])
    {
        parent[ult_pv] = ult_pu;
        size[ult_pu]+=size[ult_pv];
        
    }
    else
    {
        parent[ult_pv] = ult_pu;
        size[ult_pu]+=size[ult_pv];
    }
   
}

int count()
{
    
}
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        
        int num = n*m;
        DisjointSet ds(num);
        
        
        vector< vector<int> > vis(n,vector<int> (m,0));
        
        
        int k = operators.size();
        vector<int> ans(k);
        
        k=0;
        int cnt = 0 ;
        for(auto i:operators)
        {
            int x = i[0];
            int y = i[1];
            
            int num = m*x + y ;
            if(vis[x][y]==0)
            {
                cnt++;
                
                int a[4] = {-1,0,0,1};
                int b[4] = {0,-1,1,0};
                
                for(int i=0;i<4;i++)
                {
                    int nr = x + a[i];
                    int nc = y + b[i];
                    
                    if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==1)
                    {
                        int nnum = m*nr + nc;
                        if(ds.findUltParent(num)!=ds.findUltParent(nnum))
                        {
                            ds.UnionBySize(num,nnum);
                            cnt--;
                        }
                        
                    }
                    
                }
                
                
            }
            
            vis[x][y]=1;
            ans[k++]=cnt;
            
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends