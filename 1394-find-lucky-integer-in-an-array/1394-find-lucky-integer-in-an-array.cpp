class Solution {
public:
    int findLucky(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int mx=0,el=0;
        int n=nums.size();
        unordered_map<long,long>um;
        for(int i=0;i<n;i++){
            um[nums[i]]++;
        }
        for(auto x:um){
            if(x.second==x.first){
                //return x.first;
                if(x.second>mx){
                    mx=x.second;
                    el=x.first;
                }
            }
        }
        if(el!=0){
            return el;
        }
        return -1;
    }
};