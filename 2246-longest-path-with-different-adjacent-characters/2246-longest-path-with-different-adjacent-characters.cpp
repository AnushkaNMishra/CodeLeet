class Solution {
public:
    int len[100005];
    int ans=1;
    void dfs(int curr, string& s,vector<vector<int>> &adj)
    {
        len[curr]=1;
        
       for(int itr : adj[curr])
        {
            dfs(itr,s,adj);
            if(s[curr]!=s[itr])
            {
                ans=max(ans,len[curr]+len[itr]);
                len[curr]=max(len[curr],len[itr]+1);
            }
        }
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<int>> adj(n);
        
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        dfs(0,s,adj);
        return ans;
    }
};