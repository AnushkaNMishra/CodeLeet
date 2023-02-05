class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> p2, s2;
        vector<int> ans;
        for(int i=0; i<p.size(); i++) {
            p2[p[i]]++;
            s2[s[i]]++;
        }
        if(p2 == s2) ans.push_back(0);
        for(int i=p.size(), j=0; i<s.size(); i++) {
            s2[s[i]]++; 
            s2[s[j]]--;
            if(s2[s[j]] == 0) s2.erase(s[j]);
            j++;
            if(p2 == s2) ans.push_back(j);
        }
        return ans;
    }
};