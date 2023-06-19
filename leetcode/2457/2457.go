func unequalTriplets(nums []int) int{
	var length int = len(nums)
	var count int = 0
	for i := 0; i < length; i++ {
		for j := i + 1; j < length; j++ {
			for k := j + 1; k < length; k++ {
				if nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k] {
					count++
				}
			}
		}
	}
	return count
}