const int MAX_LENGTH = 100;

class Solution {
public:
    int countRotations(string s, int k) {
        int scores[MAX_LENGTH] = {0};
        int n = s.length();

        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                scores[i] = 1;
            } else {
                scores[i] = 0;
            }
        }
        if (s[n - 1] == s[0]) {
            scores[n - 1] = 1;
        }

        int total_score = 0;
        for (int i = 0; i < n; ++i) {
            total_score += scores[i];
        }

        if (k == total_score) {
            return n - total_score;
        } else if (k == total_score - 1) {
            return total_score;
        } else {
            return 0;
        }
    }
};