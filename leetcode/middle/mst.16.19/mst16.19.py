from typing import List
class Solution:
    def pondSizes(self, land: List[List[int]]) -> List[int]:
        ans : List[int] = []
        n = len(land)
        m = len(land[0])
        def dfs(i,j):
            if(i<0 or i>=n or j<0 or j>=m or land[i][j]!=0):
                return 0
            land[i][j] =-1
            lim = 1
            lim +=dfs(i+1,j)
            lim +=dfs(i-1,j)
            lim +=dfs(i,j+1)
            lim +=dfs(i,j-1)
            lim +=dfs(i+1,j+1)
            lim +=dfs(i+1,j-1)
            lim +=dfs(i-1,j-1)
            lim +=dfs(i-1,j+1)
            return lim
        for i in range(n):
            for j in range(m):
                if land[i][j] == 0:
                    ans.append(dfs(i,j))
        return sorted(ans)
