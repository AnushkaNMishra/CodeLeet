class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans="";
        for(int i=0;i<s.size();i++){
            string temp="";
            if(k==0) break;
            if(s[i]==' ')continue;
            while(i<s.size() && s[i]!=' '){
                temp+=s[i];
                i++;
            }
            ans+=temp;
            ans+=" ";
            k--;
        }
        
        ans.pop_back();
        
        return ans;
    }
};