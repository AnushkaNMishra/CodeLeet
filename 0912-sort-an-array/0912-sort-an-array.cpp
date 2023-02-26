class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int>pq;
        
        for(auto it:nums){
            pq.push(it);
        }
        for(auto i:nums){
            int t=pq.top();
            nums[n-1]=t;
            n--;
            pq.pop();
        }
        return nums;
    }
};