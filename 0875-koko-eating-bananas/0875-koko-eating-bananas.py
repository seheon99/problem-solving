import math


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles)
        while l <= r:
            mid = (l + r) // 2
            h_need = sum(map(lambda x: math.ceil(x / mid), piles))
            if h_need > h:
                l = mid + 1
            else:
                r = mid - 1
        return l
