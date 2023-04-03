import java.io.*;
import java.util.*;

class Info implements Comparable<Info> {
    int deadline, money;
    Info(int m, int d) {
        this.money = m;
        this.deadline = d;
    }

    @Override
    public int compareTo(Info r) {
        return Integer.compare(this.deadline, r.deadline);
    }
}

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static Info[] info;
    static int N;
    static final int MAX_DAY = 10000;

    static int pI(String s) {
        return Integer.parseInt(s);
    }
    static void init() throws Exception {
        st = new StringTokenizer(br.readLine());
        N = pI(st.nextToken());
        info = new Info[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            info[i] = new Info(pI(st.nextToken()), pI(st.nextToken()));
        }
        Arrays.sort(info);
    }
    static int solve() throws Exception {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int infoIdx = 0, ret = 0;
        for (int day = 1; day <= MAX_DAY; day++) {
            while (infoIdx < N && info[infoIdx].deadline <= day) {
                if (pq.size() < day) pq.add(info[infoIdx].money);
                else if (pq.size() == day && pq.peek() < info[infoIdx].money) {
                    pq.poll();
                    pq.add(info[infoIdx].money);
                }
                infoIdx++;
            }
        }
        while (!pq.isEmpty()) {
            ret += pq.peek();
            pq.poll();
        }
        return ret;
    }

    public static void main(String[] args) throws Exception {
        init();
        bw.write("" + solve());
        bw.flush();
    }
}