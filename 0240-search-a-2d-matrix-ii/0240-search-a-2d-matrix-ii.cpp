class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int r=0;
        int c=col-1;
        while(r<row and c>=0){
            if(matrix[r][c]==target){
                return true;
            }
            else if(target>matrix[r][c]){
                r+=1;
            }
            else{
                c-=1;
            }
        }
        return false;
    }
};