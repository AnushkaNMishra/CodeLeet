class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>> q;
        vector<int> res;
        for(int i=0;i<k;i++) q.push(make_pair(nums[i],i));
        res.push_back(q.top().first);
        for(int i=k;i<n;i++){
            q.push(make_pair(nums[i],i));
            while(i-q.top().second>=k){
                q.pop();
            }
            res.push_back(q.top().first);
        }
        return res;
    }   
};