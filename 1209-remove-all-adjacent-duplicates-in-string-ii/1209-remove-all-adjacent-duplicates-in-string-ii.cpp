class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                st.push({s[i],1});
            }
            else{
                if(st.top().first==s[i]){
                    st.top().second++;
                }
                else{
                    st.push({s[i],1});
                }
            }
            if(!st.empty() && st.top().second==k){
                st.pop();
            }
        }
        string ans="";
        while(!st.empty()){
            int freq=st.top().second;
            char c=st.top().first;
            st.pop();
            for(int i=0;i<freq;i++){
                ans+=c;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};