from typing import List
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        indeg = [0 for _ in range(numCourses)]
        mp = [[] for _ in range(numCourses)]
        
        for i in prerequisites:
            indeg[i[0]] += 1
            mp[i[1]].append(i[0])
        q = []
        tot = 0
        for i in range(numCourses):
            if indeg[i] == 0:
                q.append(i)
                tot+=1

        while q:
            x = q.pop(0)
            for i in mp[x]:
                indeg[i] -= 1
                if indeg[i] == 0:
                    q.append(i)
                    tot += 1
        return tot == numCourses


if __name__ == '__main__':
    ret = Solution().canFinish(2, [[1,0]])
    print(ret)
