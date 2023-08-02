class Solution {
public:

    void solve(int ind,vector<int>& nums, vector<vector<int>>&ans){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            solve(ind+1,nums,ans);
            swap(nums[ind],nums[i]);
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(0,nums,ans);
        return ans;
    }  
   
};


//Approach-1

//  void solve(vector<int>& v,vector<int>&nums,vector<vector<int>>&ans, int freq[]){
//         if(v.size()==nums.size()){
//             ans.push_back(v);
//             return;
//         }
//         for(int i=0;i<nums.size();i++){
//             if(freq[i]==0){
//                 v.push_back(nums[i]);
//                 freq[i]=1;
//                 solve(v,nums,ans,freq);
//                 freq[i]=0;
//                 v.pop_back();
//             }
//         }
//     }
    
    
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>>ans;
//         vector<int>v;
//         int freq[nums.size()];
//         //int freq[nums.size()] ={0};
//         for(int i=0;i<nums.size();i++){
//             freq[i]=0;
//         }
//         solve(v,nums,ans,freq);
//         return ans;
//     }