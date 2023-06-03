// class Solution {
// public:
//     int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
//     }
// };

class Solution {
private:
    int dfs(int curremp,vector<int> adj[],vector<int>& informTime){
        int time=0;
        for(auto it:adj[curremp]){
            time=max(time,dfs(it,adj,informTime));
        }
        return informTime[curremp]+time;
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            if(i!=headID)
            adj[manager[i]].push_back(i);
        }
        return dfs(headID,adj,informTime);
    }
};