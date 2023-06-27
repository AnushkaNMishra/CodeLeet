class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>res;
        priority_queue<tuple<int,int,int>>pq;
        int n=nums1.size(), m=nums2.size();
        if(n==0 || m==0) return res;
        
        pq.push({-nums1[0]-nums2[0],0,0});
        
        while(pq.size()&& res.size()<k)
        {
            auto first=pq.top();
            int i=get<1>(first);
            int j=get<2>(first);
            pq.pop();
            res.push_back({nums1[i],nums2[j]});
            
            if(i+1<n && j==0){
                pq.push({-nums1[i+1]-nums2[j],i+1,j});
            }
            if(i<n && j+1<m){
                pq.push({-nums1[i]-nums2[j+1],i,j+1});
            }
        }
        return (res);
        
    }
};

//storing the -ve sum
