class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3){
            return 0;
        }
        int ans1=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int low=i+1;
            int high=nums.size()-1;
            while(low<high){
                int ans2=nums[i]+nums[low]+nums[high];
                if(ans2==target){
                    return ans2;
                }
                if(abs(target-ans2)<abs(target-ans1)){
                    ans1=ans2;
                }
                if(ans2>target){
                    --high;
                }
                else{
                    ++low;
                }
            }
        }
        return ans1;
        
    }
};