class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        lenth : int = len(strs)
        ans : int = 0
        for i in range(lenth):
            if strs[i].isdigit():
                ans = max(ans, int(strs[i]))
            else:
                ans = max(ans, len(strs[i]))
        return ans
