class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int left=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        
        for(int i=0;i<n;i++){
            sum=sum-nums[i];
                if(left==sum){
                    return i;
                }
            left+=nums[i];
        }
        return -1;
    }
};