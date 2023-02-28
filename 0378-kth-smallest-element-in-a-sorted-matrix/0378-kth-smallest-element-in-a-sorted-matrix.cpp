class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>ans;
        //priority_queue<int>pq;
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<r;j++){
                //ans.push_back(i);
                ans.push_back(matrix[i][j]);
            }
           // ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        int a=ans[k-1];
        return a;
    }
};