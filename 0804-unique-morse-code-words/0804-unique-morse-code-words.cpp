class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string>st;
        int n=words.size();
        vector<string>v={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=0;j<words[i].length();j++){
                temp+=v[words[i][j]-'a'];
            }
            st.insert(temp);
            
        }
        return st.size();
       
    }
};