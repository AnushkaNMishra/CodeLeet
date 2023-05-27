// class Solution {
// public:
//     string stoneGameIII(vector<int>& stoneValue) {
        
//     }
// };
class Solution {
public:
    int fun(int i,vector<int>& v,vector<int> &dp){
        if(i == v.size())
            return 0;

        if(dp[i] != INT_MAX) return dp[i];
        
        int x = v[i]-fun(i+1,v,dp);
        if(i+1 < v.size())
            x = max(x,v[i]+v[i+1]-fun(i+2,v,dp));
        if(i+2 < v.size())
            x = max(x,v[i]+v[i+1]+v[i+2]-fun(i+3,v,dp));

        return dp[i] = x;        
    }

    string stoneGameIII(vector<int>& v) {
        vector<int> dp(v.size(),INT_MAX);
        int ans = fun(0,v,dp);

        if(ans > 0) return "Alice";
        else if(ans < 0) return "Bob";
        return "Tie";
    }
};