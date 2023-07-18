class Solution {
public:
    
    void solve(int ind, int target, vector<int>& nums,vector<int>& temp, vector<vector<int>>&ans){
       if(target==0){
           ans.push_back(temp);
           return;
       }
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]){
                continue; //repeated element 
            }
            if(nums[i]<=target){
                temp.push_back(nums[i]);
                solve(i+1,target-nums[i],nums,temp,ans);
                temp.pop_back();
            }
            else{
                break;
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        vector<vector<int>>ans;
        solve(0,target,candidates,temp,ans);
        return ans;
        
    }
};