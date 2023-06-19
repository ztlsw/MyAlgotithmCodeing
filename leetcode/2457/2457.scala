object Solution 
{
    def unequalTriplets(nums: Array[Int]): Int = 
    {
        var len = nums.length
        var ans = 0
        for (i <- 0 until len) 
        {
            for (j <- i + 1 until len) 
            {
                for (k <- j + 1 until len) 
                {
                    if (nums(i) != nums(j) && nums(j) != nums(k) && nums(i) != nums(k)) 
                    {
                        ans += 1
                    }
                }
            }
        }
        ans
    }
}