class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> roadCount(n);
        vector<vector<bool>> adjMatrix(n, vector<bool>(n, false));
        int ans = 0;
        for(int i=0; i<roads.size(); i++){
            adjMatrix[roads[i][0]][roads[i][1]] = true;
            adjMatrix[roads[i][1]][roads[i][0]] = true;
            roadCount[roads[i][0]]++;
            roadCount[roads[i][1]]++;
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ans = max(ans, roadCount[i] + roadCount[j] - adjMatrix[i][j]);
            }
        }
        return ans;
    }
};