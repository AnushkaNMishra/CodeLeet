class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        int mini=0;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            if(it.second==1){
                return it.first;
            }
        }
        return 0;
    }
};