class Solution:
    def mySqrt(self, x: int) -> int:
        lo, hi = 0, x
        while lo <= hi:
            mid = (lo + hi) // 2
            mid_square = mid * mid
            if mid_square == x:
                return mid
            elif mid_square < x:
                lo = mid + 1
            elif mid_square > x:
                hi = mid - 1
        return hi