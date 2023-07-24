#include <iostream>
#define LEN 12
using namespace std;

int N, cnum, maxCore, lines;
int A[LEN + 5][LEN + 5];
int cores[LEN + 5][2];
const int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    cnum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j]) {
                cores[cnum][0] = i;
                cores[cnum][1] = j;
                cnum++;
            }
        }
    }
    maxCore = lines = 0;
}

void go(int idx, int cnt, int lsum) {
    if (idx == cnum) {
        if (cnt == maxCore) lines = min(lines, lsum);
        else if (cnt > maxCore) {
            maxCore = cnt;
            lines = lsum;
        }
        return;
    }
    int x = cores[idx][0];
    int y = cores[idx][1];
    if (x == 0 || y == 0 || x == N - 1 || y == N - 1) {
        go (idx + 1, cnt + 1, lsum);
        return;
    }
    for (auto & d : dirs) {
        x = cores[idx][0] + d[0];
        y = cores[idx][1] + d[1];
        bool flag = true;
        while (x >= 0 && y >= 0 && x < N && y < N) {
            if (A[x][y]) {
                flag = false;
                break;
            }
            x += d[0];
            y += d[1];
        }
        if (flag) {
            x = cores[idx][0] + d[0];
            y = cores[idx][1] + d[1];
            int l = 0;
            while (x >= 0 && y >= 0 && x < N && y < N) {
                l++;
                A[x][y] = 1;
                x += d[0];
                y += d[1];
            }
            go (idx + 1, cnt + 1, lsum + l);
            x = cores[idx][0] + d[0];
            y = cores[idx][1] + d[1];
            while (x >= 0 && y >= 0 && x < N && y < N) {
                A[x][y] = 0;
                x += d[0];
                y += d[1];
            }
        }
        else {
            go (idx + 1, cnt, lsum);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        init();
        go(0, 0, 0);
        cout << "#" << t << ' ' << lines << '\n';
    }
    return 0;
}
