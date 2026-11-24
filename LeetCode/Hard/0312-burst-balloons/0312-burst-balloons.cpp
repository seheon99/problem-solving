const int N_MAX = 300;

class Solution {
public:
    int cache[N_MAX + 2][N_MAX + 2];
    bool visited[N_MAX + 2][N_MAX + 2];
    int n[N_MAX + 2];

    int dp(int l, int r) {
        if (l > r) {
            return 0;
        }
        if (!visited[l][r]) {
            visited[l][r] = true;
            for (int k = l; k <= r; k++) {
                cache[l][r] = std::max(
                    cache[l][r],
                    dp(l, k - 1) + n[l - 1] * n[k] * n[r + 1] + dp(k + 1, r)
                );
            }
        }
        return cache[l][r];
    }

    int maxCoins(vector<int>& nums) {
        n[0] = 1;
        for (int i = 1; i <= nums.size(); i++) {
            n[i] = nums[i - 1];
        }
        n[nums.size() + 1] = 1;
        return dp(1, nums.size());
    }
};
