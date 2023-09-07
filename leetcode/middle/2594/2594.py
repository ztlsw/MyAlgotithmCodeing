from typing import List
from math import sqrt
class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        n : int = len(ranks)
        l : int = 0 
        r : int = 1e18+7
        ans: int  = 0
        def check(mid, ranks, cars) -> bool:
            cnt : int = 0
            for i in range(n):
                cnt += int (sqrt(mid//ranks[i]))
                if cnt >= cars:
                    return True
            return False
        while l <= r:
            mid = (l+r)//2
            if check(mid, ranks, cars):
                ans = mid
                r = mid-1
            else:
                l = mid+1
        return ans