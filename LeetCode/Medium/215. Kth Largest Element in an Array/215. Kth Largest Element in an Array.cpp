#include <queue>

using Container = std::vector<int>;
using Compare = std::greater<int>;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, Container, Compare> queue;
        for (auto n : nums) {
            if (queue.size() < k) {
                queue.push(n);
                continue;
            }
            if (queue.top() < n) {
                queue.pop();
                queue.push(n);
                continue;
            }
        }
        return queue.top();
    }
};