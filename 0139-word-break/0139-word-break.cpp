class Solution {
public:
    int dp[300];
    bool f(int ind,string &s,set<string>&wordDict)
    {
        if(ind==s.size())  
            return true;
        string temp="";
        if(dp[ind]!=-1)
        return dp[ind];
        for(int j=ind;j<s.size();j++)
        {
            temp+=s[j];
            if(wordDict.find(temp)!=wordDict.end())
            {
                if(f(j+1,s,wordDict)==true)
                    return dp[ind]=true;   
            }
        }
            return dp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof dp);
        set<string>st;
        for(auto i:wordDict)st.insert(i);
        return f(0,s,st);
        //return dp[0]=
    }
};