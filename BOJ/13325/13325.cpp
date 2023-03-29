#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define LEN 2500000
#define MAX 987654321
using namespace std;

struct node {
    int cost;
    int adder;
    bool isLeaf;
};

int N, total, maxCost;
long long ret;
node graph[LEN];
vector<int> leaves;

void init() {
    for (int i = 0; i < LEN; i++) {
        graph[i].cost = 0;
        graph[i].adder = MAX;
        graph[i].isLeaf = false;
    }
    cin >> N;
    total = pow(2, N + 1) - 1;
    for (int i = 1; i <= total / 2; i++) {
        int x, y;
        cin >> x >> y;
        graph[i * 2].cost = x;
        graph[i * 2 + 1].cost = y;
    }
    for (int i = pow(2, N); i <= total; i++) {
        leaves.push_back(i);
        graph[i].isLeaf = true;
    }
    maxCost = 0;
    ret = 0;
}

void getCost(int pos, int sum) {
    maxCost = max(maxCost, sum);
//    cout << "pos: " << pos << "  ... sum: " << sum << '\n';
    if (graph[pos].isLeaf) return;
    getCost(pos * 2, sum + graph[pos * 2].cost);
    getCost(pos * 2 + 1, sum + graph[pos * 2 + 1].cost);
}

void leafToRoot(int pos, int remain) {
    if (pos == 1) return;
//    cout << "pos: " << pos << "  ... adder: " << (remain - graph[pos].cost) << '\n';
    graph[pos].adder = min(graph[pos].adder, remain - graph[pos].cost);
    leafToRoot(pos / 2, remain - graph[pos].cost);
}

void getSum(int pos, int accum) {
    if (pos > 1) {
        graph[pos].adder -= accum;
        graph[pos].cost += graph[pos].adder;
        ret += graph[pos].cost;
        accum += graph[pos].cost;
    }
    if (!graph[pos].isLeaf) {
        getSum(pos * 2, accum);
        getSum(pos * 2 + 1, accum);
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    getCost(1, 0);
    for (auto e : leaves) leafToRoot(e, maxCost);
    getSum(1, 0);
    cout << ret << '\n';
    return 0;
}