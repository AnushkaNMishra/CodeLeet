class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,ans=INT_MAX;
        int sum=0;
        
        while(j!=n){
            sum=sum+nums[j];
            if(sum<target){
                j++;
            }
            else if(sum>=target){
                while(sum>=target){
                    ans=min(ans,j-i+1);
                    sum=sum-nums[i];
                    i++;
                }
                j++;
            }
        }
        if(ans==INT_MAX){
            return 0;
        }
        return ans;
    }
};

