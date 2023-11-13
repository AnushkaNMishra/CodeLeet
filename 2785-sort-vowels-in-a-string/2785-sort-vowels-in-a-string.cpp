class Solution {
public:
    set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    string sortVowels(string s) {
        // for(auto it: vowel) cout << it;
        vector<int> idx;
        vector<char> vowel;
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(vowels.find(s[i]) != vowels.end()){
                idx.push_back(i);
                vowel.push_back(s[i]);
            }
        }
        sort(vowel.begin(), vowel.end());
        for(int i = 0; i < idx.size(); i++){
            s[idx[i]] = vowel[i];
        }

        
        return s;
    }
};