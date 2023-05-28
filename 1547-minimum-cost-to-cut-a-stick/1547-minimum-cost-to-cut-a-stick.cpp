class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        cuts.resize(m+2);
        for (int i=m-1; i>=0; i--)
            cuts[i+1] = cuts[i];
        cuts[0] = 0;
        cuts[m+1]=n;
        vector<vector<int>> dp(m+2, vector<int> (m+2, 0));
        for (int diff = 2; diff < m+2; diff++) {
            for (int l=0; l< m+2-diff; l++) {
                int r = l + diff;
                int ans = INT_MAX;
                for (int mid=l+1; mid<r; mid++) {
                    int cost = dp[l][mid]+ dp[mid][r] + cuts[r] - cuts[l];
                    ans = min(ans, cost); // minimize cost
                }
                dp[l][r] = ans;
            }
        }
        return dp[0][m+1];

    }
};