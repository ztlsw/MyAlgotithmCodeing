var unequalTriplets = function(nums) 
{
    let ans = 0;
    for (let i = 0; i < nums.length; i++) 
    {
        for (let j = i + 1; j < nums.length; j++) 
        {
            for (let k = j + 1; k < nums.length; k++) 
            {
                if (nums[i] != nums[j] && nums[j] != nums[k] && nums[k] != nums[i]) 
                {
                    ans++;
                }
            }
        }
    }
    return ans;
};