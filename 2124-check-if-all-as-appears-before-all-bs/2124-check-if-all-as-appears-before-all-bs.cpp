class Solution {
public:
    bool checkString(string s) {
        string st=s;
        sort(st.begin(),st.end());
        int c=0;
        for(int i=0;i<s.length();i++){
            if(st[i]==s[i]){
                c++;
            }
        }
        if(c==s.length()){
            return true;
        }
        return false;
    }
};