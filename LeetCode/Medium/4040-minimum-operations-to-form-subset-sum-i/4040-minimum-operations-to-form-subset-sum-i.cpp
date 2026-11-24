const int MAX_NUMS = 100;
const int MAX_SUM = 5000;

class Solution {
private:
    int cache[MAX_NUMS + 1][MAX_SUM + 1];
    bool visited[MAX_NUMS + 1][MAX_SUM + 1];

    int _minOperations(const vector<int>& nums, const int begin, const int sum) {
        if (sum == 0) {
            return 0;
        } else if (sum < 0) {
            return -1;
        } else if (begin == nums.size()) {
            return -1;
        }

        if (visited[begin][sum] == false) {
            visited[begin][sum] = true;
            int count_min = _minOperations(nums, begin + 1, sum);
            if (count_min == 0) {
                cache[begin][sum] = 0;
            } else {
                int n = nums[begin];
                int count = 0;
                while (n <= sum) {
                    int count_submin =
                        _minOperations(nums, begin + 1, sum - n);
                    if (count_submin != -1) {
                        count_min =
                            min(count + count_submin,
                                (count_min == -1 ? INT_MAX : count_min));
                    }
                    n *= 2;
                    ++count;
                }
                n = nums[begin] / 2;
                count = 1;
                while (n >= 1) {
                    int count_submin =
                        _minOperations(nums, begin + 1, sum - n);
                    if (count_submin != -1) {
                        count_min =
                            min(count + count_submin,
                                (count_min == -1 ? INT_MAX : count_min));
                    }
                    n /= 2;
                    ++count;
                }
                cache[begin][sum] = count_min;
            }
        }
        return cache[begin][sum];
    }

public:
    int minOperations(vector<int>& nums, int sum) {
        memset(visited, 0, sizeof(visited));
        return _minOperations(nums, 0, sum);
    }
};