class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> Queue;
        vector<vector<int>> ans(m, vector<int>(n, 1e6));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    ans[i][j] = 0;
                    Queue.push({i, j});
                }
            }
        } 
        vector<pair<int, int>> dirs = {{-1 , 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!Queue.empty()) {
            int sz = Queue.size();
            for(int i = 0; i < sz; i++) {
                pair<int, int> curr = Queue.front();
                Queue.pop();
                for(pair<int, int> dir: dirs) {
                    int x = curr.first + dir.first;
                    int y = curr.second + dir.second;
                    if(x < 0 || y < 0 || x >= m || y >= n || mat[x][y] == 0) continue;
                    if(ans[curr.first][curr.second] + 1 < ans[x][y]) {
                        ans[x][y] = ans[curr.first][curr.second] + 1;
                        Queue.push({x, y});
                    }
                }
            }
        }
        return ans;
    }
};