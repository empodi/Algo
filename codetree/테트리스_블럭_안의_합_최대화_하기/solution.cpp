#include <iostream>
#include <cstring>
#define MAX_LEN 200
using namespace std;

int N, M;
int A[MAX_LEN + 10][MAX_LEN + 10];

void init() {
    memset(A, 0, sizeof(A));
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }
}

int type1 (int x, int y) {
    int ret = 0;
    int local = 0;
    for (int i = x; i <= x + 3; i++) local += A[i][y];
    ret = max(ret, local);
    local = 0;
    for (int i = y; i <= y + 3; i++) local += A[x][i];
    ret = max(ret, local);
    return ret;
}

int type2 (int x, int y) {
    return A[x][y] + A[x][y + 1] + A[x + 1][y] + A[x + 1][y + 1];
}

int type3 (int x, int y) {
    /*
     ###
     ###
     */
    int ret = 0;
    int sum = 0;
    for (int i = x; i <= x + 1; i++) {
        for (int j = y; j <= y + 2; j++) {
            sum += A[i][j];
        }
    }
    ret = max(ret, sum - A[x][y] - A[x][y + 1]);
    ret = max(ret, sum - A[x][y + 1] - A[x][y + 2]);
    ret = max(ret, sum - A[x + 1][y] - A[x + 1][y + 1]);
    ret = max(ret, sum - A[x + 1][y + 1] - A[x + 1][y + 2]);
    ret = max(ret, sum - A[x][y] - A[x + 1][y + 2]);
    ret = max(ret, sum - A[x + 1][y] - A[x][y + 2]);
    ret = max(ret, sum - A[x][y] - A[x][y + 2]);
    ret = max(ret, sum - A[x + 1][y] - A[x + 1][y + 2]);
    return ret;
}

int type4 (int x, int y) {
    /*
     ##
     ##
     ##
     */
    int ret = 0;
    int sum = 0;
    for (int i = x; i <= x + 2; i++) {
        for (int j = y; j <= y + 1; j++) {
            sum += A[i][j];
        }
    }
    ret = max(ret, sum - A[x][y] - A[x + 1][y]);
    ret = max(ret, sum - A[x + 1][y] - A[x + 2][y]);
    ret = max(ret, sum - A[x][y + 1] - A[x + 1][y + 1]);
    ret = max(ret, sum - A[x + 1][y + 1] - A[x + 2][y + 1]);
    ret = max(ret, sum - A[x][y] - A[x + 2][y + 1]);
    ret = max(ret, sum - A[x][y + 1] - A[x + 2][y]);
    ret = max(ret, sum - A[x][y] - A[x + 2][y]);
    ret = max(ret, sum - A[x][y + 1] - A[x + 2][y + 1]);
    return ret;
}

int solve() {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ret = max(ret, type1(i, j));
            ret = max(ret, type2(i, j));
            ret = max(ret, type3(i, j));
            ret = max(ret, type4(i, j));
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    cout << solve() << '\n';
    return 0;
}
