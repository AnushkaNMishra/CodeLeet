class Solution {
public:
    char DFS(unordered_map<char,vector<char>>&adj, int curr,vector<int>&visited)
    {
        visited[curr-'a']=1;
        char minchar=curr;
        for(char& it: adj[curr])
        {
            if(visited[it-'a']==0){
                minchar=min(minchar, DFS(adj,it,visited));
            }
        }
        return minchar;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.length();
        int m=baseStr.length();
        unordered_map<char,vector<char>>adj;
        for(int i=0;i<n;i++){
        char u=s1[i];
        char v=s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string ans;
        for(int i=0;i<m;i++)
        {
            char ch=baseStr[i];
            vector<int>visited(26,0);
            char minchar=DFS(adj,ch,visited);
            ans.push_back(minchar);
        }
        return ans;
        
    }
};