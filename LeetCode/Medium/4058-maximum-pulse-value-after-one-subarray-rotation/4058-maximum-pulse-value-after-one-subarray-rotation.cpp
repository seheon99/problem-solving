const int N_MAX = 100'000;

class Solution {
public:
    long long maxValue(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        int n = nums.size();
        long long pulse = 0;
        for (int i = 0; i < n; i++) {
            pulse += (i % 2 == 0 ? nums[i] : -nums[i]);
        }

        long long curprefix = nums[0] - nums[1];
        long long minval = curprefix;
        long long maxprefix[2] = { max((long long)0, curprefix), nums[0] };
        for (int i = 2; i < n; i++) {
            if (i % 2 == 0) {
                curprefix += nums[i];
                minval = min(minval, curprefix - maxprefix[1]);
                maxprefix[1] = max(maxprefix[1], curprefix);
            } else {
                curprefix -= nums[i];
                minval = min(minval, curprefix - maxprefix[0]);
                maxprefix[0] = max(maxprefix[0], curprefix);
            }
        }
        if (minval < 0) {
            return pulse - 2 * minval;
        } else {
            return pulse;
        }
    }
};