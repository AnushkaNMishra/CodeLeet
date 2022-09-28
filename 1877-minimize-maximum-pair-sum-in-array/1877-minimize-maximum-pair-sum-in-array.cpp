class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=0;
        for(int i=0;i<nums.size();i++){
            res=max(res,nums[i]+nums[nums.size()-i-1]);
        }
        return res;
    }
};