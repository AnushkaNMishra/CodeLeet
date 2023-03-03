class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> startIndex;

        for (int i = 0; i < haystack.length(); ++i) {
            if (haystack[i] == needle[0]) startIndex.push_back(i);
        }

        for (int i = 0; i < startIndex.size(); ++i) {
            int j = startIndex[i];
            int k = 0;

            while (j < haystack.length() && k < needle.length() && haystack[j] == needle[k]) {
                k++;
                j++;
            }

            if (k >= needle.length()) {
                return startIndex[i];
            }
        }

        return -1;

    }
};