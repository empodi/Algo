#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

int N;
vector<string> v;
unordered_map<char, long long> um;

struct info {
    char key;
    long long priority;
    int value;
};

vector<info> A;

bool cmp(info a, info b) {
    return a.priority > b.priority;
}

void init() {
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i];
}

void setPriority() {
    for (auto & s : v) {
        for (int i = 0; i < s.length(); i++) {
            um[s[i]] += pow(10, s.length() - i);
        }
    }
    for (auto & [key, value] : um) {
        A.push_back({key, value, 0});
    }
    sort(A.begin(), A.end(), cmp);
    int p = 9;
    for (auto & e : A) e.value = p--;
//    for (auto & e : A) {
//        cout << "key = " << e.key << "   value = " << e.value << "   priority = " << e.priority << '\n';
//    }
}

int find(char key) {
    for (auto & e : A) {
        if (e.key == key) return e.value;
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    setPriority();

    // calculate
    int ret = 0;
    for (auto & s : v) {
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            num = num * 10 + find(s[i]);
        }
        ret += num;
    }
    cout << ret << '\n';
    return 0;
}
