class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int max_alt=0;
        unordered_map<int, int> um;
        for (int i = 0; i < n; i++){
            um[nums[i]]++;
        }
        vector<int>v;
    int element=0, freq=0;
        
    for (auto x : um){
        int a=n/3;
       if(a<x.second){
        v.push_back(x.first);
   
       }

    }
        return v;
    }
};