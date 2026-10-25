const int MAX_LENGTH = 1000;

class Solution {
public:
    int cache[MAX_LENGTH + 1][MAX_LENGTH + 1] = {};
    bool visited[MAX_LENGTH + 1][MAX_LENGTH + 1] = {};

    string t1;
    string t2;

    int dp(int i, int j) {
        if (i == t1.size() || j == t2.size()) {
            return 0;
        }

        if (!visited[i][j]) {
            visited[i][j] = true;
            if (t1[i] == t2[j]) {
                cache[i][j] = dp(i + 1, j + 1) + 1;
            } else {
                cache[i][j] = std::max(
                    dp(i + 1, j),
                    dp(i, j + 1)
                );
            }
        }
        return cache[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        t1 = text1;
        t2 = text2;
        return dp(0, 0);
    }
};