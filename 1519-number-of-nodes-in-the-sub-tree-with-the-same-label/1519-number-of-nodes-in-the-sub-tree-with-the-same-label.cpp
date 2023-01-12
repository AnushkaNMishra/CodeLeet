class Solution {
public:
    vector<int>vec;
    
    unordered_map<char,int>dfs(int node,vector<vector<int>>&adj,int parent ,string &labels){
       unordered_map<char,int>m;
        m[labels[node]]++;
        
        for(auto it : adj[node])
        {
            if(it==parent)
            continue;
            
            unordered_map<char,int>temp = dfs(it,adj,node,labels);
            
            for(auto it : temp)
                m[it.first] += it.second;
        }
        vec[node] = m[labels[node]];
        return m;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vec.resize(n);
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        unordered_map<char,int> mp = dfs(0,adj,-1,labels);
        return vec;
    }
};