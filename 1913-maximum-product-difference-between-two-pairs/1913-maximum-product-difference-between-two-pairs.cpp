class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int a1=nums[n-1]*nums[n-2];
        int a2=nums[0]*nums[1];
        return a1-a2;
        
    }
};