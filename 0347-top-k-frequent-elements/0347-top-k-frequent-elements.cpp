class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      vector<int>ans;
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        while(k!=0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};
 // vector<int>res;
 //        unordered_map<int,int>mp;
 //        priority_queue<pair<int,int>>pq;
 //        for(int i=0;i<nums.size();i++){
 //            mp[nums[i]]++;
 //        }
 //        for(auto& it:mp){
 //            pq.push({it.second,it.first});
 //        }
 //        while(k>0){
 //            res.push_back(pq.top().second);
 //            pq.pop();
 //            k--;
 //        }
 //        return res;