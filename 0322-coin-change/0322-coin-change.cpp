const int N_MAX = 10'000;

class Solution {
public:
    int cache[N_MAX + 1];
    bool visited[N_MAX + 1];
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        if (!visited[amount]) {
            visited[amount] = true;
            cache[amount] = -1;
            for (auto coin : coins) {
                if (amount - coin < 0) {
                    continue;
                }

                int prev = coinChange(coins, amount - coin);
                if (prev == -1) {
                    continue;
                }

                if (cache[amount] == -1) {
                    cache[amount] = prev + 1;
                } else {
                    cache[amount] = std::min(cache[amount], prev + 1);
                }
            }
        }
        return cache[amount];
    }
};