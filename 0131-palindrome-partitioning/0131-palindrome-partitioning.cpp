class Solution {
public:
    
    
    void helper(string& s, int index, vector<string>&v,vector<vector<string>>& ans){
        if(index==s.length()){
            ans.push_back(v);
            return;
        }
        for(int i=index;i<s.length();i++){
            if(ispalindrome(s,index,i)){
                v.push_back(s.substr(index,i-index+1));
                helper(s,i+1,v,ans);
                v.pop_back();
            }
        }
    }
    
     bool ispalindrome(string& s, int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>part;
        helper(s,0,part,ans);
        return ans;
    }
};