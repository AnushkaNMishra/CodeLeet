class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int curr_sum=nums[0],maxs=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                maxs=max(maxs,curr_sum);
                curr_sum=0;
            }
            curr_sum+=nums[i];
        }
        return max(maxs,curr_sum);
        
    }
};