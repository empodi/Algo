type Pair struct {
	x int 
	y int  
}

func numIslands(grid [][]byte) int {
	answer := 0
	var dirs = [4][2]int {{1,0},{-1,0},{0,1},{0,-1}}
	var visited [301][301]bool
	for i := 0; i <= len(grid); i++ {
			for j := 0; j <= len(grid); j++ {
					visited[i][j] = false
			}
	}
	for i := 0; i < len(grid); i++ {
			for j := 0; j < len(grid[0]); j++ {
					if !visited[i][j] && grid[i][j] == '1' {
							answer++
							q := []Pair{Pair{i,j}}
							visited[i][j] = true
							for len(q) != 0 {
									cur := q[0]
									q = q[1:]
									for _,d := range dirs {
											nx := cur.x + d[0]
											ny := cur.y + d[1]
											if nx < 0 || ny < 0 || nx >= len(grid) || ny >= len(grid[0]) {
													continue
											}
											if visited[nx][ny] || grid[nx][ny] == '0' {
													continue
											}
											visited[nx][ny] = true
											q = append(q, Pair{nx,ny})
									}
							}   
					}
			}
	}
	return answer
}