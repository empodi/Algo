#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int N, K, ans;
ll maxTime = 0, A[500000] = {0,};

int strToNum(string s) {
    return stoi(s.substr(0,2)) * 3600 + stoi(s.substr(3,2)) * 60 + stoi(s.substr(6,2));
}

string numToStr(int n) {
    int hour = n / 3600;
    n %= 3600;
    int minute = n / 60;
    n %= 60;
    string h = (hour < 10) ? "0" + to_string(hour) : to_string(hour);
    string m = (minute < 10) ? "0" + to_string(minute) : to_string(minute);
    string s = (n < 10) ? "0" + to_string(n) : to_string(n);
    return h + ":" + m + ":" + s;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    N = strToNum(play_time);
    K = strToNum(adv_time);
    for (auto & e : logs) {
        int lo = strToNum(e.substr(0,8));
        int hi = strToNum(e.substr(9,8));
        A[lo + 1]++;
        A[hi + 1]--;
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        cnt += A[i];
        A[i] = A[i - 1] + cnt;
    }
    for (int i = 0; i <= N - K; i++) {
        ll curTime = A[i + K] - A[i];
        if (curTime > maxTime) {
            maxTime = curTime;
            ans = i;
        }
    }
    return numToStr(ans);
}

