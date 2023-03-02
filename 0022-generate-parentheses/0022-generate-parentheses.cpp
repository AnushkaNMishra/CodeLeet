class Solution {
public:
    
    void addbracket(vector<string>& v,int n,int o,int close,string s){
    if(o==n && close==n){
        v.push_back(s);
        }
    if(o<n){
        addbracket(v,n,o+1,close,s+"(");
        }
        if(close<o){
            addbracket(v,n,o,close+1,s+")");
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        if(n==0)return v; 
        string ans="";
        int o=0;
        int close=0;
        addbracket(v,n,o,close,ans);
        return v;
    }
};