class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int numRequests = requests.size();
        int maxAchievable = 0;

        // Try all possible combinations of requests
        for (int mask = 0; mask < (1 << numRequests); mask++) {
            std::vector<int> buildingBalance(n, 0);

            // Calculate the net change in employee transfers for each building
            for (int i = 0; i < numRequests; i++) {
                if ((mask >> i) & 1) {
                    buildingBalance[requests[i][0]]--;
                    buildingBalance[requests[i][1]]++;
                }
            }

            // Check if the net change is zero for all buildings
            bool isAchievable = true;
            for (int balance : buildingBalance) {
                if (balance != 0) {
                    isAchievable = false;
                    break;
                }
            }

            // Update the maximum achievable requests if the current combination is valid
            if (isAchievable) {
                maxAchievable = std::max(maxAchievable, __builtin_popcount(mask));
            }
        }

    return maxAchievable;
    }
};