class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int>s;
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        for(auto x:s){
            v.push_back(x);
        }
        int n=v.size();
        if(v.size()<3){
            return v[n-1];
        }
        else{
            return v[n-3];
        }
        return 1;
    }
};