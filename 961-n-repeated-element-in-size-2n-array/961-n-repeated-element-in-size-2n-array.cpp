class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        unordered_map<int,int>um;
        for(int i=0;i<nums.size();i++){
            um[nums[i]]++;
        }
        for(auto x: um){
            if(x.second>1)
                return x.first;
        }
        return 1;
            
    }
};