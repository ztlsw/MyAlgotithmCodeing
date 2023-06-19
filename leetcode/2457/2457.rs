impl Solution {
    pub fn unequal_triplets(nums: Vec<i32>) -> i32 {
        let mut count = 0;
        let mut len = nums.len();
        for i in 0..len 
        {
            for j in i+1..len 
            {
                for k in j+1..len 
                {
                    if nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k] 
                    {
                        count += 1;
                    }
                }
            }
        }
        count as i32
    }
}