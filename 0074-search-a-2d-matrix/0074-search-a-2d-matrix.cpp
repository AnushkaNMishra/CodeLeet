class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col=matrix[0].size();
        int row=matrix.size();
        int c=col-1;
        int r=0;
        while(r<row and c>=0){
            if(matrix[r][c]==target){
                return true;
            }
                else if(target>matrix[r][c]){
                    r=r+1;
                }
                else{
                    c=c-1;
                }
            }
        
        return false;
    }
};