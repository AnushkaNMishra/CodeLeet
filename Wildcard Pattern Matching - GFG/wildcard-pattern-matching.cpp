//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int wildCard(string pattern,string str)
    {
        int N = str.length();
    int M = pattern.length();
    
    // Create a DP table to store the results of subproblems
    vector<vector<bool>> dp(N + 1, vector<bool>(M + 1, false));
    
    // Empty pattern matches empty string
    dp[0][0] = true;
    
    // Fill the first row (when pattern is empty)
    for (int j = 1; j <= M; j++) {
        if (pattern[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }
    
    // Fill the DP table
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (pattern[j - 1] == '?' || pattern[j - 1] == str[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (pattern[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
    }
    
    // The result is in the bottom-right cell of the DP table
    return dp[N][M] ? 1 : 0;

    }
    
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends