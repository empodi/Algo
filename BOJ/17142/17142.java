import java.io.*;
import java.util.*;

class Main{
    private static class Info {
        int x, y;
        private Info(int i, int j) {
            this.x = i;
            this.y = j;
        }
    }
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    private static StringTokenizer st;
    private static String[] token;
    private static int N, M, totalBlank, answer;
    private static final int MAX = 987654321;
    private static final int BLANK = 0;
    private static final int BLOCK = 1;
    private static final int VIRUS = 2;
    private static final int DONE = 3;
    private static final int LEN = 50;
    private static final int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    private static int[][] A = new int[LEN + 1][LEN + 1];
    private static int[][] B = new int[LEN + 1][LEN + 1];

    private static ArrayList<Info> viruses = new ArrayList<>();
    private static ArrayList<Info> cur = new ArrayList<>();
    static int pI(String s) {
        return Integer.parseInt(s);
    }
    private static void init() throws IOException {
        token = br.readLine().split(" ");
        N = pI(token[0]);
        M = pI(token[1]);
        viruses.clear();
        cur.clear();
        totalBlank = 0;
        answer = MAX;
        for (int i = 0; i < N; i++) {
            token = br.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                A[i][j] = pI(token[j]);
                if (A[i][j] == VIRUS) {
                    viruses.add(new Info(i, j));
                }
                if (A[i][j] == BLANK) totalBlank++;
            }
        }
    }
    private static int bfs() throws Exception {
        Queue<Info> q = new LinkedList<>();
        int blankCnt = 0, cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                B[i][j] = A[i][j];
                if (B[i][j] == BLANK) blankCnt++;
            }
        }
        for (Info e : cur) {
            B[e.x][e.y] = DONE;
            q.add(new Info(e.x, e.y));
        }
        while (!q.isEmpty()) {
            Queue<Info> temp_q = new LinkedList<>();
            while (!q.isEmpty()) {
                Info cur = q.poll();
                for (int[] d : dirs) {
                    int nx = cur.x + d[0];
                    int ny = cur.y + d[1];
                    if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    if (B[nx][ny] == DONE || B[nx][ny] == BLOCK) continue;
                    if (B[nx][ny] == BLANK) blankCnt--;
                    B[nx][ny] = DONE;
                    temp_q.add(new Info(nx, ny));
                }
            }
            q = temp_q;
            if (!q.isEmpty()) cnt++;
            if (blankCnt == 0) break;
        }
        return blankCnt == 0 ? cnt : MAX;
    }
    private static void go(int idx) throws Exception {
        if (cur.size() == M) {
            answer = Math.min(answer, bfs());
            return;
        }
        for (int i = idx; i < viruses.size(); i++) {
            cur.add(viruses.get(i));
            go(i + 1);
            cur.remove(cur.size() - 1);
        }
    }
    public static void main(String[] args) throws Exception {
        init();
        if (totalBlank == 0) {
            bw.write("0 \n");
        }
        else {
            go(0);
            if (answer == MAX) bw.write("-1 \n");
            else bw.write("" + answer);
        }
        bw.flush();
    }
}