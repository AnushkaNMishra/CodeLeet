// class Solution {
// public:
//     long long mostPoints(vector<vector<int>>& questions) {
        
//     }
// };



//recurr+mem
class Solution {
public:
    
    int n;
    
    long long solve(int i, vector<vector<int>>& q, vector<long long> &dp) {
        
        if(i >= n){
            return 0;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        long long taken= q[i][0] + solve(i+q[i][1]+1, q, dp);
        
        long long not_taken = solve(i+1, q, dp);
        
        return dp[i] = max(taken, not_taken);
        
    }
    
    long long mostPoints(vector<vector<int>>& q) {
        n = q.size();
        vector<long long> dp(n+1, -1);
        return solve(0, q, dp);
    }
};