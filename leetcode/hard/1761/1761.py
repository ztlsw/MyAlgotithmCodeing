from typing import List
from collections import defaultdict
class Solution:
    def minTrioDegree(self, n: int, edges: List[List[int]]) -> int:
        deg = defaultdict(int)
        mp = defaultdict(set)
        ans = float('inf')
        ln = len(edges)
        edges.sort(key=lambda x: deg[x[0]]+deg[x[1]])
        for u, v in edges:
            deg[u] += 1
            deg[v] += 1
            mp[u].add(v)
            mp[v].add(u)
        for u, v in edges:
            if deg[u]+deg[v]-6 >= ans:
                continue
            common_neighbors = mp[u].intersection(mp[v])
            for j in common_neighbors:
                ans = min(ans, deg[u] + deg[v] + deg[j] - 6)

        if ans == float('inf'):
            return -1
        return ans