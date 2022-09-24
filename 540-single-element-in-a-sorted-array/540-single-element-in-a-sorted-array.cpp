class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int xr{};
        for(auto x:nums){
            xr=xr^x;
        }
        return xr;
    }
};