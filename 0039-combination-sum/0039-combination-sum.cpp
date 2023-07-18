class Solution {
public:
 
    void solve(int i,int target, vector<int>& nums,vector<int>& temp, vector<vector<int>>&ans){
        if(i==nums.size()){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        if(nums[i]<=target){
            temp.push_back(nums[i]);
            solve(i,target-nums[i],nums,temp,ans);
            temp.pop_back();
        }
        solve(i+1,target,nums,temp,ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidate, int target) {
       vector<vector<int>>ans;
        vector<int>temp;
        solve(0,target,candidate,temp,ans);
        return ans;
    }
};