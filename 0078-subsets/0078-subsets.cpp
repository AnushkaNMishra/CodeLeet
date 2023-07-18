class Solution {
public:
    
    void solve(int ind,vector<int>& nums,vector<int>& temp,vector<vector<int>>&v){
        if(ind==nums.size()){
            v.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        solve(ind+1,nums,temp,v);
        temp.pop_back();
        solve(ind+1,nums,temp,v);
        
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>temp;
        solve(0,nums,temp,v);
        return v;
    }
};