from typing import List
class Solution:
    def minimumJumps(self, forbidden: List[int], a: int, b: int, x: int) -> int:
        dp = [[0x3f3f3f for _ in range(2)]for i in range(6001)]
        vis = {i:0 for i in range(6001)}
        ln =  len(forbidden)
        for i in range(ln):
            vis[forbidden[i]] = 1
        def dfs (pos,step,a,b,x,flag) :
            nonlocal vis,dp
            if dp[pos][flag] <= step :
                return 
            dp[pos][flag] = step
            if pos == x :
                return 
            if pos + a <= 6000 and vis[pos + a] == 0 :
                dfs(pos + a,step + 1,a,b,x,1)
            if pos - b >= 0 and vis[pos - b] == 0 and flag == 1:
                dfs(pos - b,step + 1,a,b,x,0)
        dfs(0,0,a,b,x,1)
        if dp[x][0] == 0x3f3f3f and dp[x][1] == 0x3f3f3f :
            return -1
        return min(dp[x][0],dp[x][1])