class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int max_alt=0;
        unordered_map<int, int> um;
        for (int i = 0; i < n; i++){
            um[nums[i]]++;
        }
        
    int element=0, freq=0;
        
    for (auto x : um){
       if(freq<x.second){
        freq=x.second;
        element=x.first;
    } 
    }
    return element;    
    }
};

