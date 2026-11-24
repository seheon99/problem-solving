class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> orderedNums;

        for (int i = 0; i < nums.size(); ++i) {
            if (orderedNums.find(target - nums[i]) != orderedNums.end()) {
                return {orderedNums[target - nums[i]], i};
            } else {
                orderedNums[nums[i]] = i;
            }
        }
        throw ;
    }
};