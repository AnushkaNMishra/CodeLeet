class Solution {
public:

    unordered_map<string , int> mp;
    vector<int> dp;
    int minExtraChar(string s, vector<string>& dictionary) {

        dp.resize(s.size() + 1 , -1);


        for(auto str : dictionary) {
            mp[str]++;
        }
        return solve(0 , s);
    }

    int solve(int index , string &s) {

        if(index == s.size()) return 0;

        if(dp[index] != -1) return dp[index];

        string tmp = "";
        int ans = INT_MAX;
        for(int i = index ; i < s.size() ; i++) {
            tmp += s[i];
            if(mp[tmp])
            ans = min(ans , solve(i + 1 , s));
            else {
                ans = min(ans , i - index + 1 + solve(i + 1 , s));
            }
        }

        return (dp[index] = ans);
    }
};