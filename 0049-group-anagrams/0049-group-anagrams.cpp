class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>v;
        unordered_map<string,vector<string>>mp;
        string temp;
        int n=strs.size();
        for(int i=0;i<n;i++){
            temp=strs[i];
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(temp);
        }
        for(auto i=mp.begin();i!=mp.end();i++){
            v.push_back(i->second);
        }
        return v;
    }
};
//here if we sort each word then all the similar looking words will be sorted and results in the same way.
//for eg., ate, tea, eat
//when sorted will give ans as, aet,aet,aet, thus we can group them together
//tc- O(mnlongn)
//where n is the length of thr string and m is the total given vector size