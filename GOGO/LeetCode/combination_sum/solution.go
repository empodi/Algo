func gogo(cands []int, target int, sum int, cur []int, idx int, ret *[][]int) {
	if sum > target {
			return
	}
	if target == sum {
			var curCopy []int
			for _, n := range cur {
					curCopy = append(curCopy, n)
			}
			*ret = append(*ret, curCopy)
			// fmt.Println(cur)
			return
	}
	for i := idx; i < len(cands); i++ {
			cur = append(cur, cands[i])
			gogo(cands, target, sum + cands[i], cur, i, ret)
			cur = cur[:len(cur) - 1]
	}
}

func combinationSum(candidates []int, target int) [][]int {
	var ret [][]int
	gogo(candidates, target, 0, []int{}, 0, &ret)
	return ret    
}