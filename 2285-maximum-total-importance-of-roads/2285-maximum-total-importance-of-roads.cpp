class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int,int>mp;
        for(auto it:roads){
            mp[it[0]]++;
            mp[it[1]]++;            
        }
        long long ans=0;
        priority_queue<long long>pq;
        for(auto it:mp){
            pq.push(it.second);
        }
        while(!pq.empty() && n){
            ans+=n*pq.top();
            pq.pop();
            n--;
        }
        return ans;
    }
};