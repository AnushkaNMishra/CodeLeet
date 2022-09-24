class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int xr{};
        for(auto x:nums){
            xr=xr^x;
        }
        return xr;
    }
};