from typing import List


class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0

        nums.insert(0, -(2**31) - 1)
        nums.append(-(2**31) - 1)

        l, r = 1, len(nums) - 2
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] > nums[mid - 1] and nums[mid] > nums[mid + 1]:
                return mid - 1
            elif nums[mid] > nums[mid - 1]:
                l = mid + 1
            else:
                r = mid - 1
        return l - 1
