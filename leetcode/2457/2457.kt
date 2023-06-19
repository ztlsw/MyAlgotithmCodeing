class Solution {
    fun unequalTriplets(nums: IntArray): Int 
    {
        var len = nums.size
        var count = 0
        for (i in 0..len-3)
        {
            for (j in i+1..len-2)
            {
                for (k in j+1..len-1)
                {
                    if (nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k])
                    {
                        count++
                    }
                }
            }
        }
        return count
    }
}