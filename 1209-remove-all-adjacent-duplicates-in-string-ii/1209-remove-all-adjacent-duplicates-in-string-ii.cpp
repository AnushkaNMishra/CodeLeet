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
        string res="";
        while(!st.empty()){
            int freq=st.top().second;
            char c=st.top().first;
            for(int i=0;i<freq;i++){
                res+=c;
            }
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};