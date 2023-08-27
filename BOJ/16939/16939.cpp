#include <iostream>
#include <vector>
using namespace std;

// 4 8 12 16 20 24
int A[25], B[25];

int turns[7][8] = {
        {0,0,0,0,0,0,0,0}, // dummy
        {6,5,14,13,22,21,18,17}, // 1 2 3 4
        {3,4,17,19,10,9,16,14}, // 5 6 7 8
        {7,8,19,20,23,24,15,16}, // 9 10 11 12
        {1,3,5,7,9,11,24,22}, // 13 14 15 16
        {8,6,4,2,21,23,12,10}, // 17 18 19 20
        {20, 18,2,1,13,15,11,12} // 21 22 23 24
};

int rights[25] = {0, 3, 1, 4, 2,
                  7,5,8,6,
                  11, 9, 12, 10,
                  15,13,16,14,
                  19,17,20,18,
                  23,21,24,22};

int lefts[25] = {0, 2,4,1,3,
                 6,8,5,7,
                 10,12,9,11,
                 14,16,13,15,
                 18,20,17,19,
                 22,24,21,23};

void setB() {
    for (int i = 1; i < 25; i++) B[i] = A[i];
}

bool check() {
    for (int i = 1; i < 25; i += 4) {
        if (B[i] == B[i + 1] && B[i] == B[i + 2] && B[i] == B[i + 3]) continue;
        return false;
    }
    return true;
}

void turnLeft(int n) {
    int f = 4 * (n - 1) + 1;
    vector<int> v{f, f + 1, f + 2, f + 3};
    for (auto & e : v) B[e] = A[lefts[e]];
    for (int i = 2; i < 7; i += 2) {
        B[turns[n][i - 2]] = A[turns[n][i]];
        B[turns[n][i - 1]] = A[turns[n][i + 1]];
    }
    B[turns[n][6]] = A[turns[n][0]];
    B[turns[n][7]] = A[turns[n][1]];
}

void turnRight(int n) {
    int f = 4 * (n - 1) + 1;
    vector<int> v{f, f + 1, f + 2, f + 3};
    for (auto & e : v) B[e] = A[rights[e]];
    for (int i = 0; i < 5; i += 2) {
        B[turns[n][i + 2]] = A[turns[n][i]];
        B[turns[n][i + 3]] = A[turns[n][i + 1]];
    }
    B[turns[n][0]] = A[turns[n][6]];
    B[turns[n][1]] = A[turns[n][7]];
}

int solve() {
    for (int i = 1; i < 7; i++) {
        setB();
        turnLeft(i);
        if (check()) return 1;
        setB();
        turnRight(i);
        if (check()) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for (int i = 1; i < 25; i++) cin >> A[i];
    cout << solve() << '\n';
    return 0;
}
