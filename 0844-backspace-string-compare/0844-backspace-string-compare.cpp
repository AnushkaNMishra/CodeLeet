class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string str="";
        string str1="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='#' && str.empty())
            {
                continue;
            }
            else if(s[i]=='#' && !str.empty())
            {
                str.pop_back();
            }
            else 
            {
                str=str+s[i];
            }
        }
        for(int i=0;i<t.size();i++)
        {
            if(t[i]=='#' && str1.empty())
            {
                continue;
            }
            else if(t[i]=='#' && !str1.empty())
            {
                str1.pop_back();
            }
            else 
            {
                str1=str1+t[i];
            }
        }
        return str==str1;
    }
};