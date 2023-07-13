class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,ans=INT_MAX;
        int sum=0;
        int n=nums.size();
        while(j!=n){
            sum=sum+nums[j];
            if(sum<target){
                j++;
            }
            else if(sum>=target){
                while(sum>=target){
                    sum=sum-nums[i];
                    ans=min(j-i+1,ans);
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

        
       