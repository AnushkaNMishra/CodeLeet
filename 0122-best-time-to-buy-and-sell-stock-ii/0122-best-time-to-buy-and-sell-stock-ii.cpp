class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int count=0;
        for(int i=1;i<nums.size();i++){
            count+=max(0,nums[i]-nums[i-1]);
        }
        return count;
    }
};