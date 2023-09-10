from typing import List
class Solution:
    def numberOfPoints(self, nums: List[List[int]]) -> int:
        n = len(nums)
        mp = [0 for i in range(101)]

        for lis in nums:
            x,y = lis[0],lis[1]
            for i in range(x,y+1):
                mp[i] = 1
        return sum(mp)
