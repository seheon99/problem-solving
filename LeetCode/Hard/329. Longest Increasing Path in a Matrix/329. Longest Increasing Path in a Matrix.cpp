const int N_MAX = 200;
const int M_MAX = 200;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

class Solution {
private:
    int m;
    int n;
public:
    int cache[M_MAX][N_MAX];
    bool visited[M_MAX][N_MAX];
    int dp(vector<vector<int>>& matrix, int x, int y) {
        
        if (!visited[y][x]) {
            visited[y][x] = true;

            int max = 1;
            for (int i = 0; i < 4; i++) {
                int xi = x + dx[i];
                int yi = y + dy[i];
                if (xi < 0 || xi >= n || yi < 0 || yi >= m) {
                    continue;
                }
                if (matrix[yi][xi] > matrix[y][x]) {
                    max = std::max(max, dp(matrix, xi, yi) + 1);
                }
            }
            cache[y][x] = max;
        }
        return cache[y][x];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        int max = 0;
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                max = std::max(max, dp(matrix, x, y));
            }
        }
        return max;
    }
};