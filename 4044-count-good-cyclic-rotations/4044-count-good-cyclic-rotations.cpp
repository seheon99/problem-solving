class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int size = nums.size();
        
        uint64_t sum_of_nums = reduce(nums.begin(), nums.end(), (uint64_t)0);
        uint64_t sum_of_half = reduce(nums.begin(), nums.begin() + size / 2, (uint64_t)0);

        int count = ((sum_of_half > sum_of_nums / 2) ? 1 : 0);
        for (int i = 0; i < size - 1; i++) {
            sum_of_half -= nums[i];
            sum_of_half += nums[(size / 2 + i) % size];
            
            if (sum_of_half > sum_of_nums / 2) {
                ++count;
            }
        }
        
        return count;
    }
};