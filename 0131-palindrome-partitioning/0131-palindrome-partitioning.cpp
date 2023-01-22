class Solution {
public:
    
    void helper(string& s, int index, vector<string>&v, vector<vector<string>>&res){
        if(index==s.length()){
            res.push_back(v);
            return;
        }
        
        for(int i=index;i<s.length();i++){
            if(ispalindrome(s,index,i))
            {
                v.push_back(s.substr(index,i-index+1));
                helper(s,i+1,v,res);
                v.pop_back();
            }
        }
    }
    
    bool ispalindrome(string& s, int start,int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<string>>res;
        vector<string>v;
        helper(s,0,v,res);
        return res;
    }
};