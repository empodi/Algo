#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;
typedef long long ll;

ll ret = 0;
int N;
vector<string> strList;
unordered_map<char, ll> um;
unordered_map<char, int> numHash;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    for (int k = 0; k < N; k++) {
        string s;
        cin >> s;
        strList.push_back(s);
        for (int i = 0; i < s.length(); i++) {
            um[s[i]] += pow(10, s.length() - i);
        }
    }
    vector<pair<ll,char>> v;
    for (const auto & [key, value] : um) v.push_back({value,key});
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        numHash[v[i].second] = 10 - v.size() + i;
    }
    for (auto & s : strList) {
        int cur = 0;
        for (auto & elem : s) cur = cur * 10 + numHash[elem];
        ret += cur;
    }
    cout << ret << '\n';
    return 0;
}