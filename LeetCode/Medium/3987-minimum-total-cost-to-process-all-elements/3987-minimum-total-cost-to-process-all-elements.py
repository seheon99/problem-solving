import math


class Solution:
    def minimumCost(self, nums: list[int], k: int) -> int:
        total = sum(nums)
        n = math.ceil(total / k) - 1
        result = n * (n + 1) // 2
        return result % (10**9 + 7)
