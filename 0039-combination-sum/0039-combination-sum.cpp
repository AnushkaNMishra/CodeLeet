class Solution {
public:
    
    void solve(int ind, int target, vector<int>& candidate, vector<vector<int>>&ans, vector<int>&ds) {
        if(ind==candidate.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        //pick up the element
        if(candidate[ind]<=target){
            ds.push_back(candidate[ind]);
            solve(ind,target-candidate[ind],candidate,ans,ds);
            ds.pop_back();
        }
        
        solve(ind+1,target,candidate,ans,ds);
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidate, int target) {
        vector<vector<int>>ans;
        vector<int>ds;

        solve(0,target,candidate,ans,ds);
        return ans;
    }
};