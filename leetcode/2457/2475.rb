# @param {Integer[]} nums
# @return {Integer}
def unequal_triplets(nums)
    len = nums.length
    ans = 0
    for i in 0..len-3
        for j in i+1..len-2
            for k in j+1..len-1
                ans = ans+1 if nums[i] != nums[j] && nums[j] != nums[k] && nums[k] != nums[i]
            end
        end
    end
    ans
end