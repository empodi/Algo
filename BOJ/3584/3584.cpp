#include <iostream>
#include <vector>
#include <cstring>
#define LEN 10000
using namespace std;
typedef long long ll;

int N, root;
int parent[LEN + 10];
bool isChild[LEN + 10], isParent[LEN + 10];
int level[LEN + 10];
vector<int> child[LEN + 10];

void init() {
    for (auto & i : child) i.clear();
    memset(parent, 0, sizeof(parent));
    memset(isParent, false, sizeof(isParent));
    memset(isChild, false, sizeof(isChild));
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b; // a가 b의 부모
        parent[b] = a;
        isParent[a] = true;
        isChild[b] = true;
        child[a].push_back(b);
    }
}

void setRoot() {
    for (int i = 1; i <= N; i++) {
        if (isParent[i] && !isChild[i]) {
            root = i;
            break;
        }
    }
}

void setLevel(const int & pos, const int lv) {
    level[pos] = lv;
    for (auto & e : child[pos]) setLevel(e, lv + 1);
}

int findLCS() {
    int x, y;
    cin >> x >> y;
    while (level[x] != level[y]) {
        if (level[x] < level[y]) y = parent[y];
        else if (level[x] > level[y]) x = parent[x];
    }
    while (x != y) {
        x = parent[x];
        y = parent[y];
    }
    return x;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        init();
        setRoot();
        setLevel(root, 1);
        cout << findLCS() << '\n';
    }
    return 0;
}
