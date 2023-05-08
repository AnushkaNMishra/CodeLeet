class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        if(mat.size() == 1) return mat[0][0];
        int m = mat.size(), n = mat[0].size();
        int ans = 0;

        for(int i = 0; i < mat.size(); i++){
            ans += mat[i][i];
            ans += mat[m-1-i][i];
        }   
        return ans - ((m % 2 != 0) ? mat[m/2][n/2] : 0);
    }
};