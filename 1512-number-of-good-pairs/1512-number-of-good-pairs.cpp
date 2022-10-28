class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(nums[j]==nums[i] && i<j){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};