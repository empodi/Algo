func longestConsecutive(nums []int) int {
  ret := 0
  hash := map[int]bool{}
  for _,n := range nums {
    hash[n] = true
  }
  for key,_ := range hash {
    // fmt.Println(key, val)
    if !hash[key - 1] {
      start := key
      cnt := 0
      for hash[start] {
        cnt++
        start++
      }
      if cnt > ret {
        ret = cnt
      }
    }
  }
  return ret
}