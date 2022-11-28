class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left=0;
        for(int i=0;i<nums.size();i++){
           if(nums[i]==0){
               swap(nums[i],nums[left]);
               left++;
           } 
        }
            for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
               swap(nums[i],nums[left]);
               left++;
           }
            
        }
    }
};
//there only consis of 1 2 & 3, so sort 0 and 1, and you will eventually get 2 sorted 