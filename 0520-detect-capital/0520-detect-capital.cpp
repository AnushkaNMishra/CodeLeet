class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 1) return true;
        bool case1 = true, case2 = true, case3 = true;
        if (word[0] >= 'A' and word[0] <= 'Z') {
            case3 = false;
        } else {
            case1 = case2 = false;
        }
        for (int i = 1; i < word.size(); ++i) {
            case1 &= word[i] >= 'A' and word[i] <= 'Z';
            case2 &= word[i] >= 'a' and word[i] <= 'z';
            case3 &= word[i] >= 'a' and word[i] <= 'z';
        }
        return case1 or case2 or case3;
    }
};