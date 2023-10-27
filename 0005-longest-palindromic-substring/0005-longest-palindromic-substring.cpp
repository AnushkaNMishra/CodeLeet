#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string str) {
        int n = str.length();
        string ans = "";

        if (n == 1) {
            return str;
        }

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int max_len = 1;  

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            ans = str[i];  
        }

        for (int i = 0; i < n - 1; i++) {
            if (str[i] == str[i + 1]) {
                dp[i][i + 1] = true;
                max_len = 2;
                ans = str.substr(i, 2);
            }
        }

        for (int len = 3; len <= n; len++) 
        {
            for (int i = 0; i < n - len + 1; i++) 
            {
                int j = i + len - 1;  
                if (str[i] == str[j] && dp[i + 1][j - 1]) 
                {
                    dp[i][j] = true;
                    if (len > max_len) 
                    {
                        max_len = len;
                        ans = str.substr(i, len);
                    }
                }
            }
        }

        return ans;
    }
};
