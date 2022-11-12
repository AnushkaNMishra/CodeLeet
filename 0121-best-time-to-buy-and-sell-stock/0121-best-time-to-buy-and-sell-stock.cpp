class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int maxc=0,maxi=0;
        for(int i=1;i<nums.size();i++){
            maxc=max(0,maxc+=nums[i]-nums[i-1]);
            maxi=max(maxi,maxc);
        }
        return maxi;
    }
};