class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,sum=0;
        int res=INT_MAX;
        
        while(j!=n){
            sum=sum+nums[j];
            if(sum<target){
                j++;
            }
            else if(sum>=target){
                while(sum>=target){
                    res=min(j-i+1,res);
                    sum=sum-nums[i];
                    i++;
                }
                j++;
            }
        }
        if(res==INT_MAX){
            return 0;
        }
        return res;
    }
};