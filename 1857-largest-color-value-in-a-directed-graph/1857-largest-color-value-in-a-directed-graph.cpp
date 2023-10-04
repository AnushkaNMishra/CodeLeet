// //meta

class Solution {
 public:
     int largestPathValue(string colors, vector<vector<int>>& edges) {
       
    int n = colors.size();
    vector<vector<int>> graph(n);
    vector<int> inDegree(n, 0);
    for (auto &edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        inDegree[edge[1]]++;
    }

    // DFS function to check for cycles.
    vector<int> visited(n, 0);
    bool hasCycle = false;
    function<void(int)> dfsCheckCycle = [&](int node) {
        if (hasCycle || visited[node] == 2) return;
        if (visited[node] == 1) {
            hasCycle = true;
            return;
        }
        visited[node] = 1;
        for (int next : graph[node]) {
            dfsCheckCycle(next);
        }
        visited[node] = 2;
    };
    
            for (int i = 0; i < n; i++) {
        if (!visited[i]) dfsCheckCycle(i);
    }
    if (hasCycle) return -1;

    // Compute topological order using BFS (Kahn's algorithm).
    vector<int> topoOrder;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            topoOrder.push_back(i);
        }
    }
    for (int i = 0; i < topoOrder.size(); i++) {
        for (int next : graph[topoOrder[i]]) {
            if (--inDegree[next] == 0) {
                topoOrder.push_back(next);
            }
        }
    }

// Compute largest color value.
    vector<unordered_map<char, int>> colorCount(n);
    int ans = 0;
    for (int node : topoOrder) {
        colorCount[node][colors[node]]++;
        ans = max(ans, colorCount[node][colors[node]]);
        for (int next : graph[node]) {
            for (auto [color, cnt] : colorCount[node]) {
                colorCount[next][color] = max(colorCount[next][color], cnt);
            }
        }
    }
    return ans;
}

};

//OJ: https://leetcode.com/contest/weekly-contest-240/problems/largest-color-value-in-a-directed-graph/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
