class Solution {
public:
int solve(int amount, vector<int>& coins, int index, vector<vector<int>> &dp){
    if(amount==0){
        return 1;
    }
    if(dp[amount][index]!=-1){
        return dp[amount][index];
    }
    if(index==coins.size()){
        return 0;
    }
    int take=0;
    if(coins[index]<=amount){
        take=solve(amount-coins[index],coins,index,dp);
    }
    int not_take=solve(amount,coins, index+1,dp);
    return dp[amount][index]=take+not_take;
}
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1, vector<int> (coins.size()+1,-1));
        return solve(amount, coins, 0,dp);
    }
};