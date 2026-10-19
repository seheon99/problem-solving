
class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.size();

        vector<int> indegree(n, 0);
        vector<int> degree(n, 0);

        auto getColor = [](char c) {
            if (c == 'R') return 0;
            if (c == 'B') return 1;
            return 2;
        };

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];

            degree[u]++;
            degree[v]++;

            int a = getColor(colors[u]);
            int b = getColor(colors[v]);

            if (a == b) {
                return -1;
            }

            if ((a + 1) % 3 == b) {
                indegree[v]++;
            } else {
                indegree[u]++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (indegree[i] > 1) {
                return -1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0 && degree[i] <= 2) {
                return i;
            }
        }
        return -1;
    }
};
