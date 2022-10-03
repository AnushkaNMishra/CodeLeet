class Solution {
public:
    int findPoisonedDuration(vector<int>& nums, int duration) {
        int n=nums.size();
        if(n==0)return 0;
        int sum=0;
        for(int i=0;i<n-1;i++){
            if((nums[i]+duration)<=nums[i+1]){
                sum+=duration;
            }
            else{
                sum+=(nums[i+1]-nums[i]);
            }
        }
        return sum+duration;
    }
};