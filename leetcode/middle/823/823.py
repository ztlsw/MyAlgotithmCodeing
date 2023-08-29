from typing import List

class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        lenn = len(arr)
        dp = [1 for i in range(lenn)]
        dict = {}
        arr.sort()
        for i in range(lenn):
            dict[arr[i]] = i
        
        for i in range(lenn):
            for j in range(i):
                if arr[i] % arr[j] == 0:
                    tmp = arr[i] // arr[j]
                    if tmp in dict:
                        dp[i] += dp[j] * dp[dict[tmp]]
        return sum(dp) % (10 ** 9 + 7)


if __name__ == '__main__':
    arr = [18,31,2,4,14,7,9,63,10,84]
    s = Solution()
    print(s.numFactoredBinaryTrees(arr))