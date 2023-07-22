
class Solution {
public:
    int n;
    double mem[26][26][101];

    double rec(int i, int j, int k) {
        if(i<0 || j<0 || j>=n || i>=n) return 0.0;
        if(k == 0) return 1.0;
        if(mem[i][j][k] != -1) return mem[i][j][k];

        double tmp = rec(i+2, j+1, k-1);
        tmp += rec(i+2, j-1, k-1);
        tmp += rec(i-2, j+1, k-1);
        tmp += rec(i-2, j-1, k-1);
        tmp += rec(i+1, j+2, k-1);
        tmp += rec(i-1, j+2, k-1);
        tmp += rec(i+1, j-2, k-1);
        tmp += rec(i-1, j-2, k-1);

        return mem[i][j][k] = tmp/8;
    }

    double knightProbability(int N, int k, int row, int column) {
        n = N;
        fill_n(&mem[0][0][0], 26*26*100, -1.0);
        return rec(row, column, k);
    }
};