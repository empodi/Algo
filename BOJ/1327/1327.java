import java.io.*;
import java.util.*;

public class Main {
    static class Info {
        int nums[];
        int cnt;
        public Info(int n[], int cnt) {
            this.nums = n;
            this.cnt = cnt;
        }
    }
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int N, K;
    static int[] A, sorted;
    static Set<String> hashSet = new HashSet<>();

    static int pI(String s) {
        return Integer.parseInt(s);
    }
    static void init() throws IOException {
        String token[] = br.readLine().split(" ");
        N = pI(token[0]);
        K = pI(token[1]);
        A = new int[N];
        sorted = new int[N];
        token = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            A[i] = pI(token[i]);
            sorted[i] = A[i];
        }
        Arrays.sort(sorted);
//        System.out.println(Arrays.toString(A));
//        System.out.println(Arrays.toString(sorted));
    }
    static boolean check(int a[], int b[]) {
        for (int i = 0; i < N; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
    static void swap(int nums[], int lo, int hi) {
        while (lo < hi) {
            int t = nums[lo];
            nums[lo] = nums[hi];
            nums[hi] = t;
            lo++;
            hi--;
        }
    }
    static int solve() {
        Queue<Info> q = new LinkedList<>();
        q.offer(new Info(A, 0));
        hashSet.add(Arrays.toString(A));
        while (!q.isEmpty()) {
            Info tmp = q.poll();
            if (check(tmp.nums, sorted)) {
                return tmp.cnt;
            }
            for (int i = 0; i <= N - K; i++) {
                int[] nums = tmp.nums.clone();
                swap(nums, i, i + K - 1);
                String str = Arrays.toString(nums);
                if (hashSet.contains(str)) continue;
                hashSet.add(str);
                q.offer(new Info(nums, tmp.cnt + 1));
            }
        }
        return -1;
    }
    public static void main(String[] args) throws Exception {
        init();
        bw.write("" + solve());
        bw.flush();
    }
}