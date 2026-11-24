class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # value -> index of values seen so far
        seen = {}
        for i, n in enumerate(nums):
            if target - n in seen:
                return [seen[target - n], i]
            seen[n] = i
