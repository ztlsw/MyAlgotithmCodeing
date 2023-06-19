
class Solution
{
    func unequalTriplets(_ nums: [Int]) -> Int 
    {
        var length = nums.count
        var count = 0
        for i in 0..<length
        {
            for j in i+1..<length
            {
                for k in j+1..<length
                {
                    if nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k]
                    {
                        count += 1
                    }
                }
            }
        }
        return count
    }
}
