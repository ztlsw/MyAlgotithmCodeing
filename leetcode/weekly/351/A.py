class Solution:
    def get_first_digit(self,num):
        return int(str(num)[0])

    def get_last_digit(self,num):
        return int(str(num)[-1])
    def countBeautifulPairs(self, nums: List[int]) -> int:
        count = 0
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if gcd(self.get_first_digit(nums[i]), self.get_last_digit(nums[j])) == 1:
                    count += 1
        return count
