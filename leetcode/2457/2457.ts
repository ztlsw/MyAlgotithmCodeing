function unequalTriplets(nums: number[]): number 
{
    let count = 0;
    let ans = 0;
    for (let i = 0; i < nums.length - 2; i++)
    {
        for(let j = i + 1; j < nums.length - 1; j++)
        {
            for(let k = j + 1; k < nums.length; k++)
            {
                if(nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k])
                {
                    count++;
                }
            }
        }
    }
    return count;
};