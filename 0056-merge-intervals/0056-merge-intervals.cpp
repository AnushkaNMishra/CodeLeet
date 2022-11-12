class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>v;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        v.push_back(intervals[0]);
        for(int i=0;i<n;i++){
            if(v.back()[1]>=intervals[i][0]){
                v.back()[1]=max(v.back()[1],intervals[i][1]);
            }
            else{
                v.push_back(intervals[i]);
            }
        }
        return v;
    }
};