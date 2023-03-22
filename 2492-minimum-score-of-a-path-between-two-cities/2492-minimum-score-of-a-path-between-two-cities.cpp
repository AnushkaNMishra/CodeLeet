// class Solution {
// public:
//     int minScore(int n, vector<vector<int>>& roads) {
//         int ans=0;
//         for(int i=0;i<)
//     }
// };

class Solution {
public:
    int minScore(int n, vector<vector<int>>& r) {
        
        int ans = INT_MAX;
        vector<vector<pair<int,int>>> g(n+1);
        
        for(auto i: r)
        {
            g[i[0]].push_back({i[1],i[2]});
            g[i[1]].push_back({i[0],i[2]});
        }
        
        vector<bool> vis(n+1, false);
        queue<int> q;
        q.push(1);
        
        while(!q.empty())
        {
            int val = q.front(); 
            vis[val] = true;
            q.pop();
            for(auto j: g[val])
            {
                int to = j.first;
                int dd = j.second;
                ans = min(ans,dd);
                
                if(!vis[to])
                {
                    q.push(to);
                }
                
            }
        }
        
        
        
        
        return ans;
        

    }
};