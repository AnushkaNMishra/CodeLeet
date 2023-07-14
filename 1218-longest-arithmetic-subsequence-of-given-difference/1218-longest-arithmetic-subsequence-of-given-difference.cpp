class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int>prev;
        int ans=0;
        for(auto it:arr){
            prev[it]=prev[it-difference]+1;
            ans=max(ans,prev[it]);
        }
        return ans;
    }
};