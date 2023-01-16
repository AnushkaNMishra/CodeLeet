class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newin) {
        vector<vector<int>>res;
        for(auto i:intervals)
        {
            if(i[1]<newin[0]){
                res.push_back(i);
            }
            
            else if(i[0]>newin[1]){
                res.push_back(newin);
                newin=i;
            }
            else if(i[1]>=newin[0] || i[0]<=newin[1]){
                newin[0]=min(newin[0],i[0]);
                newin[1]=max(newin[1],i[1]);  
            }
        }
        res.push_back(newin);
        return res;
    }
};