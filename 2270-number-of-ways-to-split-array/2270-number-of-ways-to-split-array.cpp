class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
     
        int n=nums.size();
        int count=0;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        long long left=0;
        for(int i=0;i<n-1;i++){
            left+=nums[i];
            sum-=nums[i];
            if(left>=sum){
                count++;
            }
            
        }
        return count;
    }
};