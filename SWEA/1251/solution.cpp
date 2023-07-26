#include <iostream>
#include <algorithm>
#define MAX_ISLAND 1000
using namespace std;
typedef long long ll;

struct info {
    ll dist;
    int x;
    int y;
};

int N, eNum, cnt, A[MAX_ISLAND + 1][2];
int parent[MAX_ISLAND + 1];
info edges[MAX_ISLAND * MAX_ISLAND + 10];
double d, answer;

bool cmp (info a, info b) {
    return a.dist < b.dist;
}

int find(int x) {
    if (x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cnt = answer = eNum = 0;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> A[i][0];
        }
        for (int i = 0; i < N; i++) {
            cin >> A[i][1];
            parent[i] = i;
        }
        cin >> d;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                ll a = abs(A[i][0] - A[j][0]);
                ll b = abs(A[i][1] - A[j][1]);
                edges[eNum] = {a * a + b * b, i, j};
                eNum++;
            }
        }
        sort(edges, edges + eNum, cmp);
        for (int i = 0; i < eNum; i++) {
            int px = find(edges[i].x), py = find(edges[i].y);
            if (px == py) continue;
            cnt++;
            answer += edges[i].dist;
            if (px < py) parent[py] = px;
            else parent[px] = py;
            if (cnt == N - 1) break;
        }
        cout << fixed;
        cout.precision(0);
        cout << "#" << t << ' ' << answer * d << '\n';
    }
    return 0;
}