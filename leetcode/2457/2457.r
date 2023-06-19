unequalTriplets <- function(nums) {
  length <- length(nums)
  ans <- 0
  for(i in 1:length) {
    for(j in (i + 1):length) {
      for(k in (j + 1):length) {
        if(nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k]) {
          ans <- count + 1
        }
      }
    }
  }
  return(count)
}
