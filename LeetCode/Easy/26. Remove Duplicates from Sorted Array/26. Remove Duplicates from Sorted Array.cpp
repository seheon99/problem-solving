class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int n : nums)
            if (k == 0 || nums[k - 1] != n) nums[k++] = n;
        return k;
    }
};
