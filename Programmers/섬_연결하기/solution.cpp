#include <string>
#include <vector>
#include <queue>
#define MAX 100
using namespace std;
typedef pair<int,int> pii;

int parent[MAX + 10];
priority_queue< pair<int,pii>, vector<pair<int,pii>>, greater<> > pq;

int findParent(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = findParent(parent[x]);
}

int helper (const int & n) {
    int ret = 0, cnt = 0;
    while (true) {
        auto [ cost, t ] = pq.top();
        auto [a , b] = t;
        pq.pop();
        int pa = findParent(a);
        int pb = findParent(b);
        if (pa != pb) {
            ret += cost;
            cnt++;
            parent[pa] = pb;
        }
        if (cnt == n - 1) break;
    }
    return ret;
}

int solution(int n, vector<vector<int>> costs) {
    for (int i = 0; i <= n; i++) parent[i] = i;
    for (auto & e : costs) {
        pq.push( { e[2], { e[0], e[1] } } );
    }
    return helper(n);
}