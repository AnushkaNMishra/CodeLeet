class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int i;
        // Each tap waters from start_position to end_position.
        // `m[start_p]` records the maximum end_p 
        vector<int> m(n+1, 0);
        m[0] = ranges[0];
        for (i = 1 ; i < n+1 ; ++i) {
            int start_p = max(0, i-ranges[i]);
            int end_p = i + ranges[i];
            m[start_p] = max(m[start_p], i + ranges[i]);
        }

        // Update longest end_p of each start_p
        for (i = 1 ; i < n+1 ; ++i) {
            m[i] = max(m[i], m[i-1]);
        }
        int res = 0;
        i = 0;
        while (i < n) {
            if (m[i] == i) {  // cannot move forward anymore
                res = -1;
                break;
            }
            // We don't need to use another loop 
            // to check if there exists a j, 
            // where j is within the range of 
            // i+1 and m[i], such that m[j] > n[i], 
            // because we already update the m[j] to m[i].
            i = m[i];
            ++res;
        }
        
        return res;        
    }
};