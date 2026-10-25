const int MAX_LENGTH = 1000;

class Solution {
public:
    int cache[MAX_LENGTH + 1][MAX_LENGTH + 1] = {};
    bool visited[MAX_LENGTH + 1][MAX_LENGTH + 1] = {};

    int dp(const string& text1, const string& text2, int i, int j) {
        if (i == text1.size() || j == text2.size()) {
            return 0;
        }

        if (!visited[i][j]) {
            visited[i][j] = true;
            if (text1[i] == text2[j]) {
                cache[i][j] = dp(text1, text2, i + 1, j + 1) + 1;
            } else {
                cache[i][j] = std::max(
                    dp(text1, text2, i + 1, j),
                    dp(text1, text2, i, j + 1)
                );
            }
        }
        return cache[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        return dp(text1, text2, 0, 0);
    }
};