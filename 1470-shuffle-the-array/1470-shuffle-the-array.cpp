class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>v;
        int ns=nums.size();
        int mid=(ns/2);
        int i=0;
        int j=mid;
        while(i<mid && j<ns){
             v.push_back(nums[i]);
             v.push_back(nums[j]);
            i++;
            j++;
        }
        return v;
    }
};