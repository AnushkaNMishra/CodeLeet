// class Solution {
// public:
    
//     //google
//     vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
//     }
// };
class Solution {
public:
    void t(int i,vector<vector<int>>& a,vector<int>& v)
    {
        for(auto j : a[i])
        {
            v[j]=1;
            if(!v[j])
            t(j,a,v);
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> a(n);
        for(auto i : edges)
        a[i[0]].push_back(i[1]);
        vector<int> v(n,0);
        for(int i=0;i<n;i++)
            t(i,a,v);
        
        vector<int> ans;
        for(int i=0;i<n;i++)
        if(v[i]==0)
        ans.push_back(i);
        return ans;
    }
};