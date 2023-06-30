func isCircularSentence(sentence string) bool {
	str := strings.Split(sentence, " ")
	for i := 0; i < len(str)-1; i++ {
		if str[i+1][0] != str[i][len(str[i])-1] {
			return false
		}
	}
	i := len(str)-1
	if  str[i][len(str[i])-1] != str[0][0] {
		return false
	}
	return true
}