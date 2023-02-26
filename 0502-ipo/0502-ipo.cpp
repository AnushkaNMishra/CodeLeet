class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; i++) {
            projects[i] = make_pair(capital[i], profits[i]);
        }
        sort(projects.begin(), projects.end());
        priority_queue<int> available_profits;
        int i = 0;
        for (int j = 0; j < k; j++) {
            while (i < n && projects[i].first <= w) {
                available_profits.push(projects[i].second);
                i++;
            }
            if (available_profits.empty()) {
                break;
            }
            w += available_profits.top();
            available_profits.pop();
        }
        return w;
    }
};