func numFactoredBinaryTrees(arr []int) int {
	dp := make([]int, len(arr))
	dict := make(map[int]int)
	sort.Ints(arr)
	for i := 0; i < len(arr); i++ {
		dict[arr[i]] = i
	}
	for i := 0; i < len(arr); i++ {
		dp[i] = 1
	}
	for i := 0; i < len(arr); i++ {
		for j := 0; j < i; j++ {
			if arr[i]%arr[j] == 0 {
				tmp := arr[i] / arr[j]
				if _, ok := dict[tmp]; ok {
					dp[i] += dp[j] * dp[dict[tmp]]
				}
			}
		}
	}
	sum := 0
	for i := 0; i < len(arr); i++ {
		sum += dp[i]
		sum %= 1000000007
	}
	return sum
}