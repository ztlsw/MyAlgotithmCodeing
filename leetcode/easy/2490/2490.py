from typing import List

class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        strs : List[str] = sentence.split()
        lenth : int = len(strs)
        for i in range(lenth-1):
            if strs[i][-1] != strs[i+1][0]:
                return False
        if strs[-1][-1] != strs[0][0]:
            return False
        return True