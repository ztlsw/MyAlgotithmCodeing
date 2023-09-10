from typing import List
class Solution:
    def isReachableAtTime(self, sx: int, sy: int, fx: int, fy: int, t: int) -> bool:
        maxx = abs(fx - sx)+abs(fy - sy)
        minn = max(abs(fx - sx), abs(fy - sy))
        if maxx == 0:
            if t == 1:
                return False
            return True
        if t < minn:
            return False
        return True