class Solution {
public:
    
    void solve(vector<int>& v,vector<int>&nums,vector<vector<int>>&ans, int freq[]){
        if(v.size()==nums.size()){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(freq[i]==0){
                v.push_back(nums[i]);
                freq[i]=1;
                solve(v,nums,ans,freq);
                freq[i]=0;
                v.pop_back();
            }
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++){
            freq[i]=0;
        }
        solve(v,nums,ans,freq);
        return ans;
    }
};