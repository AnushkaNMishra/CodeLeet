class Solution {
public:
    int partitionString(string s) {
        set<char>st;
        int count=0;
        for(int i=0;i<s.size();i++){
            while(i<s.size() && st.find(s[i])==st.end()){
                st.insert(s[i]);
                i++;
            }
            i--;
            count++;
            st.clear();
        }
        return count;
    }
};