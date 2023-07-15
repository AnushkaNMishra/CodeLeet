class Solution {
public:

    int n, k;
    vector<vector<int>> e, mem;

    int slv (int i, int j) {
        if (i >= n or j >= k) return 0;
        if (mem[i][j] != -1) return mem[i][j];
        int nxt = lower_bound(e.begin() + i, e.end(), vector<int>{e[i][1] + 1, INT32_MIN, INT32_MIN}) - e.begin();
        return mem[i][j] = max (
            slv(i + 1, j), e[i][2] + slv(nxt, j + 1)
        );
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        n = events.size(), this->k = k, e = events;
        vector<vector<int>> mem(n, vector<int>(k, -1));
        this->mem = mem;
        return slv(0, 0);
    }
};