class Solution:
    def maximumNumberOfStringPairs(self, words: List[str]) -> int:
        length : int = len(words)
        ans : int = 0
        for i in range(length):
            for j in range(i+1,length):
                if words[i] == words[j][::-1]:
                    ans+=1
                    words[i] = "123"
                    words[j] = "123"
        return ans
