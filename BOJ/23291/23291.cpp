#include <iostream>
#include <cstring>
#include <vector>
#define LEN 100
#define MAX 987654321
using namespace std;
typedef pair<int, int> pii;

int N, K;
int A[LEN + 1][LEN + 1], B[LEN + 1][LEN + 1];
const int dirs[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

void init() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i][0];
    }
}

void add() {
    int minVal = MAX;
    for (int i = 1; i <= N; i++) {
        minVal = min(minVal, A[i][0]);
    }
    for (int i = 1; i <= N; i++) {
        if (A[i][0] == minVal) A[i][0]++;
    }
}

int getNext(const int n) {
    for (int i = 1; i <= 100; i++) {
        if (i * i >= n) return i;
    }
    return 0;
}

void firstRotate() {
    int s = 1, e = 1, h = 1;
    while (true) {
        h = getNext(e);
        if (e + h > N) break;
        int idx = 1;
        for (int i = e; i >= s; i--) {
            int last = e + 1;
            for (int j = 0; j < h; j++) {
                A[last + j][idx] = A[i][j];
                A[i][j] = 0;
            }
            idx++;
        }
        s = e + 1;
        e += h;
    }
}

void control() {
    memset(B, 0, sizeof(B));
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (A[i][j] == 0) continue;
            for (auto d : dirs) {
                int nx = i + d[0];
                int ny = j + d[1];
                if (nx < 0 || ny < 0 || nx > N || ny > N) continue;
                if (A[nx][ny] == 0) continue;
                int diff = abs(A[i][j] - A[nx][ny]) / 5;
                if (diff > 0) {
                    if (A[nx][ny] > A[i][j]) {
                        B[nx][ny] -= diff;
                        B[i][j] += diff;
                    }
                    else {
                        B[nx][ny] += diff;
                        B[nx][ny] -= diff;
                    }
                }
            }
        }
    }
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            A[i][j] += B[i][j];
        }
    }
}

void down() {
    int idx = 1;
    memset(B, 0, sizeof(B));
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (A[i][j]) B[idx++][0] = A[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            A[i][j] = B[i][j];
        }
    }
}

void secondRotate() {
    for (int i = 1; i <= N / 2; i++) {
        A[N + 1 - i][1] = A[i][0];
        A[i][0] = 0;
    }
    int s = N / 2 + 1;
    int e = s + N / 4 - 1;
    for (int i = s; i <= e; i++) {
        for (int j = 0; j < 2; j++) {
            A[s + N - i][3 - j] = A[i][j];
            A[i][j] = 0;
        }
    }
}

int getDiff() {
    int maxVal = 0, minVal = MAX;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (A[i][j] > 0) {
                maxVal = max(maxVal, A[i][j]);
                minVal = min(minVal, A[i][j]);
            }
        }
    }
    return maxVal - minVal;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    int cnt = 0;
    while (true) {
        add();
        firstRotate();
        control();
        down();
        secondRotate();
        control();
        down();
        cnt++;
        int res = getDiff();
        if (res <= K) break;
    }
    cout << cnt << '\n';
    return 0;
}
