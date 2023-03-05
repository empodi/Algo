#include <iostream>
#include <algorithm>
#define LEN 50000
#define MIN 0
#define MAX 1000001
using namespace std;

struct info {
    int minVal;
    int maxVal;
};

int N, Q;
int A[LEN + 5] = {0,};
info tree[LEN * 4] = {0,};

info buildTree(int lo, int hi, int pos) {
    if (lo == hi) {
        tree[pos].minVal = tree[pos].maxVal = A[lo];
        return tree[pos];
    }
    int mid = (lo + hi) / 2;
    info l = buildTree(lo, mid, pos * 2);
    info r = buildTree(mid + 1, hi, pos * 2 + 1);
    tree[pos].minVal = min(l.minVal, r.minVal);
    tree[pos].maxVal = max(l.maxVal, r.maxVal);
    return tree[pos];
}

info find(int qlo, int qhi, int lo, int hi, int pos) {
    if (hi < qlo || lo > qhi) return { MAX, MIN };
    if (qlo <= lo && hi <= qhi) return tree[pos];
    int mid = (lo + hi) / 2;
    info l = find(qlo, qhi, lo, mid, pos * 2);
    info r = find(qlo, qhi, mid + 1, hi, pos * 2 + 1);
    return { min(l.minVal, r.minVal), max(l.maxVal, r.maxVal) };
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> A[i];
    buildTree(1, N, 1);
    while (Q--) {
        int a, b;
        cin >> a >> b;
        info res = find(a, b, 1, N, 1);
        cout << res.maxVal - res.minVal << '\n';
    }
    return 0;
}