#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#define MOD 100
using namespace std;
typedef pair<int,int> pii;

// (x, y)
int N;
int dir[4][2] = { {1,0}, {0, -1}, {-1, 0}, {0, 1} };
unordered_set<int> uSet;

int getHash(const int & x, const int & y) {
    return x * MOD + y;
}

void go(int x, int y, int d, int gen) {
    vector<pii> v;
    v.push_back({x, y});
    v.push_back({x + dir[d][0], y + dir[d][1]});
    for (int t = 0; t < gen; t++) {
        vector<pii> tmp;
        int endX = v.back().first;
        int endY = v.back().second;
        int len = (int) v.size();
        for (int i = len - 2; i >= 0; i--) {
            int newX = endX - (v[i].second - endY);
            int newY = endY + (v[i].first - endX);
            tmp.push_back({newX, newY});
        }
        for (auto & e : tmp) v.push_back(e);
    }
    for (auto & e : v) {
        uSet.insert(getHash(e.first, e.second));
    }
}

bool check(const int & x, const int & y) {
    if (uSet.find(getHash(x, y)) != uSet.end()
        && uSet.find(getHash(x + 1, y)) != uSet.end()
        && uSet.find(getHash(x, y + 1)) != uSet.end()
        && uSet.find(getHash(x + 1, y + 1)) != uSet.end()) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y, d, gen;
        cin >> x >> y >> d >> gen;
        go(x, y, d, gen);
    }
//    for (auto e : uSet) {
//        cout << e / MOD << ' ' << e % MOD << '\n';
//    }
    int ret = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (check(i, j)) ret++;
        }
    }
    cout << ret << '\n';
    return 0;
}