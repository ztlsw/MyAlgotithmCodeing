from typing import List

class Solution:
    def specialPerm(self, nums: List[int]) -> int:
        n :int = len(nums)
        mp : int =  [[0]*n for _ in range(n)]
        dp : int = [[0]*(1<<n) for _ in range(n)]
        ans : int = 0
        MOD : int = 10**9 + 7
        for i in range(n):
            for j in range(n):
                if nums[i] % nums[j] == 0 or nums[j] % nums[i] == 0:
                    mp[i][j] = 1
                    mp[j][i] = 1
        for i in range(n):
            dp[i][1<<i] = 1

        for mask in range(1<<n):
            for i in range(n):
                if mask & (1<<i) :
                    for j in range(n):
                        if mask & (1<<j) == 0:
                            if mp[i][j] == 1:
                                dp[i][mask] += dp[j][mask^(1<<i)]
                                dp[i][mask] %= MOD
        for i in range(n):
            ans += dp[i][(1<<n)-1]
            ans %= MOD
        return ans