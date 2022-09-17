class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>um;
        for(int i=0;i<n;i++){
            um[nums[i]]++;
        }
        for(auto x: um){
            if(x.second>1)
                return x.first;
        }
        return 1;
            
    }
};