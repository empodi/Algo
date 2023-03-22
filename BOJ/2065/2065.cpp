#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define LEFT 0
#define  RIGHT 1

int N, M, T;
struct info {
    int id;
    int tm;
    string s;
};

queue<info> q[2];
vector<pair<int,int>> v;

void init() {
    cin >> M >> T >> N;
    for (int i = 0; i < N; i++) {
        info inf;
        cin >> inf.tm >> inf.s;
        inf.id = i;
        if (inf.s == "left") q[LEFT].push(inf);
        else q[RIGHT].push(inf);
    }
}

void solve() {
    int curTime = 0;
    int ship = LEFT;
    while (!q[LEFT].empty() || !q[RIGHT].empty()) {
        if (!q[ship].empty() && q[ship].front().tm <= curTime) {
            int cnt = 0;
            while (!q[ship].empty() && q[ship].front().tm <= curTime && cnt < M) {
                v.push_back({q[ship].front().id, curTime + T});
                q[ship].pop();
                cnt++;
            }
            curTime += T;
            ship = 1 - ship;
        }
        else {
            if (q[ship].empty() && !q[1 - ship].empty()) {
                ship = 1 - ship;
                curTime = max(curTime, q[ship].front().tm) + T;
            }
            else if (!q[1 - ship].empty() && q[ship].front().tm > q[1 - ship].front().tm) {
                ship = 1 - ship;
                curTime = max(curTime, q[ship].front().tm) + T;
            }
            else {
                curTime = q[ship].front().tm;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    solve();
    sort(v.begin(), v.end());
    for (auto & e : v) cout << e.second << '\n';
    return 0;
}