class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i+=2){
            count+=nums[i];
        }
        return count;
    }
};