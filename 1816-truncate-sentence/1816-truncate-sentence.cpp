class Solution {
public:
    string truncateSentence(string s, int k) {
        stack<string>st;
        string ans="";
        for(int i=0;i<s.size();i++){
            string temp="";
            if(k==0) break;
            if(s[i]==' ')continue;
            while(i<s.size() && s[i]!=' '){
                temp+=s[i];
                i++;
            }
            //st.push(temp);
            ans+=temp;
            ans+=" ";
            k--;
        }
        s.erase();
        
        // while(!st.empty()){
        //     ans+=st.top();
        //     st.pop();
        //     ans+=" ";
        // }
        ans.pop_back();
        //strcpy(s,ans);
        s=ans;
        
        return s;
    }
};