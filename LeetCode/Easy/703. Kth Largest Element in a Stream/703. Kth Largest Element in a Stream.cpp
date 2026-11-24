#include <queue>
#include <iostream>

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums): k(k) {
        for (auto n : nums) {
            if (pq.size() < k) {
                pq.push(n);
                continue;
            }
            if (pq.top() < n) {
                pq.pop();
                pq.push(n);
                continue;
            }
        }
    }
    
    int add(int val) {
        if (pq.size() < k) {
            pq.push(val);
        } else if (pq.top() < val) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }

private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int k;
};