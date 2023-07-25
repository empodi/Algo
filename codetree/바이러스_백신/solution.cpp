#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define BLOCK 1
#define HOSPITAL 2
#define LEN 50
#define MAX_HOS 10
#define MAX 987654321
using namespace std;
typedef pair<int,int> pii;

int N, M, hNum, zeroNum, answer;
int org[LEN + 1][LEN + 1], A[LEN + 1][LEN + 1], hos[MAX_HOS][2];
const int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void init() {
    hNum = zeroNum = 0;
    answer = MAX;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> org[i][j];
            if (org[i][j] == HOSPITAL) {
                hos[hNum][0] = i;
                hos[hNum++][1] = j;
            }
            if (org[i][j] == 0) {
                zeroNum++;
            }
        }
    }
}

void copy() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = org[i][j];
        }
    }
}

void bfs(vector<int> & v) {
    copy();
    queue<pii> q;
    for (auto e : v) {
        q.push({hos[e][0], hos[e][1]});
        A[hos[e][0]][hos[e][1]] = BLOCK;
    }
    int qLen = (int) v.size(), zCnt = 0, ret = 0;
    while (!q.empty()) {
        queue<pii> temp_q;
        for (int k = 0; k < qLen; k++) {
            pii cur = q.front();
            q.pop();
            for (auto d : dirs) {
                int nx = cur.first + d[0];
                int ny = cur.second + d[1];
                if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                if (A[nx][ny] == 0 || A[nx][ny] == HOSPITAL) {
                    if (A[nx][ny] == 0) zCnt++;
                    A[nx][ny] = BLOCK;
                    temp_q.push({nx, ny});
                }
            }
        }
        ret++;
        if (zCnt == zeroNum) {
            answer = min(answer, ret);
            break;
        }
        qLen = temp_q.size();
        q = temp_q;
    }
}

void go(vector<int> & v, int pos) {
    if (v.size() == M) {
        bfs(v);
        return;
    }
    for (int i = pos; i < hNum; i++) {
        v.push_back(i);
        go(v, i + 1);
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    if (zeroNum == 0) {
        answer = 0;
    }
    else {
        vector<int> v;
        go (v, 0);
    }
    if (answer == MAX) cout << "-1 \n";
    else cout << answer << '\n';
    return 0;
}