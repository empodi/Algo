#include <iostream>
#include <vector>
#define LEN 50
using namespace std;

int N, K, root, ret;
vector<int> graph[LEN + 1];
int parent[LEN + 1];

void init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        parent[i] = x;
        if (x == -1) root = i;
        else graph[x].push_back(i);
    }
    cin >> K;
    ret = 0;
}

void removeNode() {
    int rParent = parent[K];
    for (int i = 0; i < graph[rParent].size(); i++) {
        if (graph[rParent][i] == K) {
            graph[rParent][i] = -1;
            break;
        }
    }
}

void countLeaf(const int & pos) {
    int cnt = 0;
    for (auto e : graph[pos]) {
        if (e < 0) continue;
        countLeaf(e);
        cnt++;
    }
    if (cnt == 0) ret++;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    if (K != root) {
        removeNode();
        countLeaf(root);
    }
    cout << ret << '\n';
    return 0;
}
