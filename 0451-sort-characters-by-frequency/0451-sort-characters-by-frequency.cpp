class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        string res="";
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto x:mp){
            pq.push(make_pair(x.second,x.first));
        }
        while(!pq.empty()){
            int a=pq.top().first;
            char b=pq.top().second;
            for(int i=0;i<a;i++){
                res+=b;
            }
            pq.pop();
        }
        return res;
    }
};