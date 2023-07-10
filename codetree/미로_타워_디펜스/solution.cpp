#include <iostream>
#include <cstring>
#include <vector>
#define MAX_LEN 30
using namespace std;
typedef pair<int,int> pii;

struct info {
    int x;
    int y;
    int num;
};

int N, M;
int A[MAX_LEN + 1][MAX_LEN + 1];
bool visited[MAX_LEN + 1][MAX_LEN + 1];
info path[MAX_LEN * MAX_LEN + 1];
const int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

void init() {
    cin >> N >> M;
    memset(A, 0, sizeof(A));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
}

pii left(int x, int y) {
    if (x == 1 && y == 0) return {0, 1};
    if (x == -1 && y == 0) return {0, -1};
    if (x == 0 && y == 1) return {-1, 0};
    return {1, 0};
}

void setPath() {
    memset(visited, 0, sizeof(visited));
    visited[N / 2][N / 2] = true;
    int x = N / 2, y = N / 2 - 1, dx = 1, dy = 0, idx = 0;
    while (true) {
        path[idx++] = {x, y, 0};
        visited[x][y] = true;
        if (x == 0 && y == 0) break;
        pii d = left(dx, dy);
        if (visited[x + d.first][y + d.second]) {
            x += dx;
            y += dy;
        }
        else {
            x += d.first;
            y += d.second;
            dx = d.first;
            dy = d.second;
        }
    }
}

int attack(const int & dIdx, const int & p) {
    int ret = 0;
    for (int i = 1; i <= p; i++) {
        ret += A[N / 2 + i * dir[dIdx][0]][N / 2 + i * dir[dIdx][1]];
        A[N / 2 + i * dir[dIdx][0]][N / 2 + i * dir[dIdx][1]] = 0;
    }
    for (int i = 0; i < N * N - 1; i++) {
        path[i].num = A[path[i].x][path[i].y];
    }
    return ret;
}

void pull() {
    int i = 0;
    while (i < N * N - 1) {
        if (path[i].num > 0) {
            int j = i - 1;
            while (j >= 0 && path[j].num == 0) j--;
            j++;
            swap(path[i].num, path[j].num);
        }
        i++;
    }
}

int fourExists() {
    int i = 0, ret = 0;
    while (i < N * N - 1) {
        if (path[i].num == 0) i++;
        else {
            int j = i + 1;
            while (j < N * N - 1 && path[i].num == path[j].num) j++;
            int cnt = j - i;
            if (cnt >= 4) {
                ret += cnt * path[i].num;
                for (int k = i; k < j; k++) {
                    path[k].num = 0;
                }
            }
            i = j;
        }
    }
    return ret;
}

void reset() {
    vector<pii> v;
    int i = 0;
    while (i < N * N - 1) {
        if (path[i].num == 0) i++;
        else {
            int j = i + 1;
            while (j < N * N - 1 && path[i].num == path[j].num) j++;
            v.push_back({path[i].num, j - i});
            i = j;
        }
    }
    i = 0;
    for (auto & e : v) {
        if (i < N * N) {
            path[i++].num = e.second;
        }
        if (i + 1 < N * N) {
            path[i++].num = e.first;
        }
    }
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            A[j][k] = 0;
        }
    }
    for (int j = 0; j < N * N - 1; j++) {
        A[path[j].x][path[j].y] = path[j].num;
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int answer = 0;
    init();
    setPath();
    while (M--) {
        int dIdx, p, res;
        cin >> dIdx >> p;
        answer += attack(dIdx, p);
        pull();
        while ((res = fourExists()) > 0) {
            answer += res;
            pull();
        }
        reset();
    }
    cout << answer << '\n';
    return 0;
}
