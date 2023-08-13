class Solution {
public:
    bool foo(const vector<int>& nums, const int k) {
        if (k == -1) {
            return true;
        }
        if (k-2 >= 0) {
            if (nums[k] == nums[k-1] && nums[k] == nums[k-2]) {
                if (foo(nums, k-3)) {
                    return true;
                }
            }
            if (nums[k]-1 == nums[k-1] && nums[k]-2 == nums[k-2]) {
                if (foo(nums, k-3)) {
                    return true;
                }
            }
        }
        if (k-1 < nums.size()) {
            if (nums[k] == nums[k-1]) {
                if (foo(nums, k-2)) {
                    return true;
                }
            }
        }
        return false;
    }


    bool validPartition(vector<int>& nums) {
        return foo(nums, nums.size()-1);
    }
};