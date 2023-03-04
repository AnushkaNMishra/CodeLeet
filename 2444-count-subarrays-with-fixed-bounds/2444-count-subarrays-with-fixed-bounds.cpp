class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int lastIdx = 0;
        int lastMin = -1, lastMax = -1;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]<minK || nums[i]>maxK) {
                lastIdx = i+1;
                lastMin = lastMax = -1;
                continue;
            }
            if (nums[i] == minK)
                lastMin = i;
            if (nums[i] == maxK)
                lastMax = i;
            if (lastMin != -1 && lastMax != -1) {
                ans += min(lastMin, lastMax) - lastIdx + 1;
            }
        }
        return ans;
    }
};