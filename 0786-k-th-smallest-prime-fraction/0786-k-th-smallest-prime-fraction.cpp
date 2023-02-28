class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,pair<int,int>>>pq;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                double res=(double)arr[i]/arr[j]; //////////////////
                
                pq.push({res,{arr[i],arr[j]}});
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        vector<int>v;
        v.push_back(pq.top().second.first);
        v.push_back(pq.top().second.second);
        return v;
    }
};