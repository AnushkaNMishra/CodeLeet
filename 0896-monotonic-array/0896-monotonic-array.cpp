class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int k=0, j=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                k=1;
            }
            if(nums[i]<nums[i+1]){
                j=1;
            }
            if(k==1 && j==1){
                return false;
            }
        }
        return true;
    }
};