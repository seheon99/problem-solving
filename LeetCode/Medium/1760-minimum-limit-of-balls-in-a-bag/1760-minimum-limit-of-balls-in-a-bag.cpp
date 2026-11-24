
class Solution {
public:
    int minimumSize(std::vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = *std::max_element(nums.begin(), nums.end());

        while (left < right) {
            int mid = left + (right - left) / 2;

            long long operations = 0;

            for (int num : nums) {
                operations += (num - 1) / mid;
            }

            if (operations <= maxOperations) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
