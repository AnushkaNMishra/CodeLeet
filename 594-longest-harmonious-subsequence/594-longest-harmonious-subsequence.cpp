class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0,r=1;
        int ans=0;
        while(r<nums.size()){
            int d=nums[r]-nums[l];
            if(d==1){
                ans=max(ans,r-l+1);
            }
            if(d<=1){
                r++;
            }
            else{
                l++;
            }
        }
        return ans;
        
    }
};