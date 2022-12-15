//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

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

void  UnionBySize(int u, int v)
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


};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        set< pair< int ,  pair<int,int> > > st;
        
        for(int i = 0 ; i<V ; i++)
        {
            for(auto e : adj[i])
            {
                st.insert( { e[1] , {i, e[0] } } );
            }
        }
        
        int ans = 0;
        
        DisjointSet ds(V);
        
        while(st.size()!=0)
        {
            pair< int ,  pair<int,int> > p = *(st.begin());
            st.erase(p);
            
            int u = p.second.first;
            int v = p.second.second;
            
            int ult_pu = ds.findUltParent(u);
            int ult_pv = ds.findUltParent(v);
            
            if(ult_pu == ult_pv)
            continue;
            
            ds.UnionBySize(u,v);
            ans+=p.first;
            
        }
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends