class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char, int> M;
        
        for(int i=0;i<s.length();i++){
            M[s[i]]++;
        }
        for(int i=0; i<s.length(); i++){
            if(M[s.at(i)] == 1)
                return i;
        }
        return -1;
    }
};