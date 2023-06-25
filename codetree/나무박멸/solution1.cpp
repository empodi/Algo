#include <iostream>
#include <cstring>
#define MAX_LEN 20
#define BLOCK -1
using namespace std;

int N, M, K, C;
int A[MAX_LEN + 1][MAX_LEN + 1];
int herbicide[MAX_LEN + 1][MAX_LEN + 1];
int tmp[MAX_LEN + 1][MAX_LEN + 1];
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
const int diagon[4][2] = {{-1,-1},{-1,1},{1,-1},{1,1}};

void init() {
    cin >> N >> M >> K >> C;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    memset(herbicide, 0, sizeof(herbicide));
}

void grow() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] > 0) {
                for (auto d : dir) {
                    int nx = i + d[0];
                    int ny = j + d[1];
                    if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    if (A[nx][ny] > 0) A[i][j]++;
                }
            }
        }
    }
}

void breed() {
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] > 0) {
                int cnt = 0;
                for (auto d : dir) {
                    int nx = d[0] + i;
                    int ny = d[1] + j;
                    if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    if (A[nx][ny] == 0 && herbicide[nx][ny] == 0) cnt++;
                }
                if (cnt > 0) {
                    for (auto d: dir) {
                        int nx = d[0] + i;
                        int ny = d[1] + j;
                        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                        if (A[nx][ny] == 0 && herbicide[nx][ny] == 0) tmp[nx][ny] += A[i][j] / cnt;
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] += tmp[i][j];
        }
    }
}

void disappear() { // 제초제 감소
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (herbicide[i][j] > 0) {
                herbicide[i][j]--;
            }
        }
    }
}

int kill() {
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] > 0) {
                tmp[i][j] += A[i][j];
                for (auto d: diagon) {
                    for (int k = 1; k <= K; k++) {
                        int nx = i + k * d[0];
                        int ny = j + k * d[1];
                        if (nx < 0 || ny < 0 || nx >= N || ny >= N || A[nx][ny] <= 0) break;
                        tmp[i][j] += A[nx][ny];
                    }
                }
            }
        }
    }
    int ki = 0, kj = 0, maxKill = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (maxKill < tmp[i][j]) {
                maxKill = tmp[i][j];
                ki = i;
                kj = j;
            }
        }
    }
    herbicide[ki][kj] = C;
    if (A[ki][kj] == 0) {
        return 0;
    }
    A[ki][kj] = 0;
    for (auto d : diagon) {
        for (int k = 1; k <= K; k++) {
            int nx = ki + d[0] * k;
            int ny = kj + d[1] * k;
            if (nx < 0 || ny < 0 || nx >= N || ny >= N || A[nx][ny] < 0) break;
            herbicide[nx][ny] = C;
            if (A[nx][ny] == 0) break;
            A[nx][ny] = 0;
        }
    }
    return maxKill;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int answer = 0;
    while (M--) {
        grow();
        breed();
        disappear();
        answer += kill();
    }
    cout << answer << '\n';
    return 0;
}