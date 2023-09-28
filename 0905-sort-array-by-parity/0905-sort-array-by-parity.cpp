class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0;
        int j=1;
        while(j!=nums.size()){
            if(nums[i]%2==0){
                i++;
                j++;
            }
            else if(nums[i]%2!=0 && nums[j]%2==0){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else if(nums[j]%2!=0){
                j++;
            }
        }
        return nums;
    }
};