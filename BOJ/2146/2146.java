import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int N;
    static final int LAND = 1;
    static final int WATER = 0;
    static final int LEN = 100;
    static int[][] A = new int[LEN + 1][LEN + 1];
    static boolean[][] visited = new boolean[LEN + 1][LEN + 1];
    static final int[][] dir = {{1,0},{-1,0},{0,1},{0,-1}};

    private static class Point {
        int x;
        int y;
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int pI(String s) {
        return Integer.parseInt(s);
    }
    static void setVisited() {
        for (int i = 0; i <= LEN; i++) {
            for (int j = 0; j <= LEN; j++) visited[i][j] = false;
        }
    }
    static void init() throws Exception {
        N = pI(br.readLine());
        for (int i = 0; i < N; i++) {
            String[] token = br.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                A[i][j] = pI(token[j]);
            }
        }
    }
    static void go(int x, int y) {
        if (A[x][y] == WATER) return;
        A[x][y] = WATER;
        for (int[] d : dir) {
            int nx = x + d[0];
            int ny = y + d[1];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            go(nx, ny);
        }
    }
    static int solve() throws Exception {
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (A[i][j] == WATER) continue;
                setVisited();
                Queue<Point> q = new LinkedList<>();
                Queue<Point> edgeQ = new LinkedList<>();
                q.offer(new Point(i, j));
                visited[i][j] = true;
                while (!q.isEmpty()) {
                    Point p = q.poll();
                    for (int[] d : dir) {
                        int nx = p.x + d[0];
                        int ny = p.y + d[1];
                        if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny]) continue;
                        if (A[nx][ny] == LAND) {
                            visited[nx][ny] = true;
                            q.offer(new Point(nx, ny));
                        } else {
                            edgeQ.offer(new Point(p.x, p.y));
                        }
                    }
                }
                int cnt = 0;
                boolean flag = true;
                while (!edgeQ.isEmpty() && flag) {
                    Queue<Point> tempQ = new LinkedList<>();
                    while (!edgeQ.isEmpty() && flag) {
                        Point p = edgeQ.poll();
                        for (int[] d : dir) {
                            int nx = p.x + d[0];
                            int ny = p.y + d[1];
                            if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny]) continue;
                            if (A[nx][ny] == LAND) {
                                ans = Math.min(ans, cnt);
                                flag = false;
                                break;
                            }
                            visited[nx][ny] = true;
                            tempQ.offer(new Point(nx, ny));
                        }
                    }
                    edgeQ = tempQ;
                    cnt++;
                }
                go(i, j);
            }
        }
        return ans;
    }
    public static void main(String[] args) throws Exception {
        init();
        bw.write("" + solve());
        bw.flush();
    }
}