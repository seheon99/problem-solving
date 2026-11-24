#include <algorithm>

using intpair = std::pair<int, int>;

const int MAX = 10000;
const int MIN = -10000;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        intpair store[MAX - MIN + 1];
        for (int i = MIN; i < MAX + 1; i++) {
            store[i - MIN].first =  i;
            store[i - MIN].second = 0;
        }
        for (auto n : nums) {
            store[n - MIN].second += 1;
        }
        std::sort(
            store,
            store + MAX - MIN + 1,
            [](intpair a, intpair b) {
                return a.second > b.second;
            });
        std::vector<int> results;
        for (int i = 0; i < k; i++) {
            results.push_back(store[i].first);
        }
        return results;
    }
};