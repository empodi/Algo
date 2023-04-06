import java.io.*;
import java.util.*;

public class Main {
    static final int LEN = 10000;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int N, root;
    static boolean isParent[] = new boolean[LEN + 10];
    static boolean isChild[] = new boolean[LEN + 10];
    static int level[] = new int[LEN + 10];
    static int parent[] = new int[LEN + 10];
    static ArrayList<Integer> child[];

    static int pI(String s) {
        return Integer.parseInt(s);
    }
    static void init() throws IOException {
        Arrays.fill(isParent, false);
        Arrays.fill(isChild, false);
        Arrays.fill(level, 0);
        Arrays.fill(parent, 0);
        N = pI(br.readLine());
        child = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            child[i] = new ArrayList<>();
        }
        for (int i = 0; i < N - 1; i++) {
            int a, b;
            String token[] = br.readLine().split(" ");
            a = pI(token[0]);
            b = pI(token[1]);
            parent[b] = a;
            isParent[a] = true;
            isChild[b] = true;
            child[a].add(b);
        }
    }
    static void setRoot() throws Exception {
        for (int i = 1; i <= N; i++) {
            if (isParent[i] && !isChild[i]) {
                root = i;
                break;
            }
        }
    }
    static void setLevel(int pos, int lv) throws Exception {
        level[pos] = lv;
        for (int e : child[pos]) setLevel(e, lv + 1);
    }
    static int findLCS() throws Exception {
        int x, y;
        String token[] = br.readLine().split(" ");
        x = pI(token[0]);
        y = pI(token[1]);
        while (level[x] != level[y]) {
            if (level[x] < level[y]) y = parent[y];
            else if (level[x] > level[y]) x = parent[x];
        }
        while (x != y) {
            x = parent[x];
            y = parent[y];
        }
        return x;
    }
    public static void main(String[] args) throws Exception {
        int T = pI(br.readLine());
        while (T-- > 0) {
            init();
            setRoot();
//            System.out.println("Root: " + root);
            setLevel(root, 1);
            bw.write(findLCS() + "\n");
        }
        bw.flush();
    }
}
